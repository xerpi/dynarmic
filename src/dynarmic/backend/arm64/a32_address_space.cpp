/* This file is part of the dynarmic project.
 * Copyright (c) 2021 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#include "dynarmic/backend/arm64/a32_address_space.h"

#include <aarch64/macro-assembler-aarch64.h>
#include <boost/icl/interval_set.hpp>

#include "dynarmic/backend/arm64/a32_emitter.h"
#include "dynarmic/backend/arm64/a32_jitstate.h"
#include "dynarmic/backend/arm64/devirtualize.h"
#include "dynarmic/backend/arm64/stack_layout.h"
#include "dynarmic/backend/arm64/vixl_helpers.h"
#include "dynarmic/common/assert.h"
#include "dynarmic/common/cast_util.h"
#include "dynarmic/common/common_types.h"
#include "dynarmic/frontend/A32/location_descriptor.h"
#include "dynarmic/frontend/A32/translate/translate.h"
#include "dynarmic/interface/A32/config.h"
#include "dynarmic/ir/basic_block.h"
#include "dynarmic/ir/location_descriptor.h"
#include "dynarmic/ir/opt/passes.h"

namespace Dynarmic::Backend::Arm64 {

A32AddressSpace::A32AddressSpace(const A32::UserConfig& conf)
        : conf(conf) {
    EmitPrelude();
}

A32AddressSpace::~A32AddressSpace() = default;

A32AddressSpace::BlockDescriptor A32AddressSpace::GetBlock(IR::LocationDescriptor descriptor) {
    if (const auto iter = block_descriptors.find(descriptor); iter != block_descriptors.end()) {
        return iter->second;
    }
    return EmitBlock(descriptor);
}

void A32AddressSpace::ClearCache() {
    block_descriptors.clear();
    ASSERT_FALSE("Unimplemented");
    cache_generation++;
}

void A32AddressSpace::InvalidateCacheRanges(const boost::icl::interval_set<u32>& /*ranges*/) {
    ASSERT_FALSE("Unimplemented");
    cache_generation++;
}

void A32AddressSpace::EmitPrelude() {
    using namespace vixl::aarch64;

    // Dispatcher

    prelude.run_code = code.GetCursorAddress<PreludeInfo::RunCodeFuncType>();

    code.PushCalleeSavedRegisters();
    code.Sub(sp, sp, sizeof(StackLayout));
    code.Mov(x28, x0);  // Store JitState pointer in x28
    code.Mov(x19, x1);

    static_assert(offsetof(StackLayout, save_host_fpsr) + 4 == offsetof(StackLayout, save_host_fpcr));
    code.Mrs(x2, FPSR);
    code.Mrs(x3, FPCR);
    code.Stp(w2, w3, MemOperand{sp, offsetof(StackLayout, save_host_fpsr)});

    Devirtualize<&A32::UserCallbacks::GetTicksRemaining>(conf.callbacks).EmitCall(code);
    code.Str(x0, MemOperand{sp, offsetof(StackLayout, cycles_to_run)});
    code.Mov(x27, x0);  // Store cycles_remaining in x27

    code.Br(x19);

    code.Bind(&prelude.return_from_run_code);

    code.Cmp(x27, 0);
    code.B(le, &prelude.return_to_caller);
    code.Mov(x1, x28);
    code.CallRuntime(Common::FptrCast([](A32AddressSpace& self, A32JitState& state) -> void* {
        return self.GetBlock(state.GetLocationDescriptor()).entry_point;
    }));
    code.Br(x0);

    code.Bind(&prelude.return_to_caller);

    code.Ldr(x1, MemOperand{sp, offsetof(StackLayout, cycles_to_run)});
    code.Sub(x1, x1, x27);
    Devirtualize<&A32::UserCallbacks::AddTicks>(conf.callbacks).EmitCall(code);

    static_assert(offsetof(StackLayout, save_host_fpsr) + 4 == offsetof(StackLayout, save_host_fpcr));
    code.Ldp(w2, w3, MemOperand{sp, offsetof(StackLayout, save_host_fpsr)});
    code.Msr(FPSR, x2);
    code.Msr(FPCR, x3);

    code.Add(sp, sp, sizeof(StackLayout));
    code.PopCalleeSavedRegisters();
    code.Ret();

    code.FinalizeCode();
}

A32AddressSpace::BlockDescriptor A32AddressSpace::EmitBlock(IR::LocationDescriptor descriptor) {
    if (code.GetBuffer()->GetRemainingBytes() < MINIMUM_REMAINING_CODESIZE) {
        ClearCache();
    }

    // Generate and optimize IR

    IR::Block ir_block = A32::Translate(A32::LocationDescriptor{descriptor}, conf.callbacks, {conf.arch_version, conf.define_unpredictable_behaviour, conf.hook_hint_instructions});
    if (conf.HasOptimization(OptimizationFlag::GetSetElimination)) {
        Optimization::A32GetSetElimination(ir_block);
        Optimization::DeadCodeElimination(ir_block);
    }
    if (conf.HasOptimization(OptimizationFlag::ConstProp)) {
        Optimization::A32ConstantMemoryReads(ir_block, conf.callbacks);
        Optimization::ConstantPropagation(ir_block);
        Optimization::DeadCodeElimination(ir_block);
    }
    Optimization::VerificationPass(ir_block);

    // Emit code (translate IR into executable code)

    const BlockDescriptor block_descriptor = [&] {
        buffer.SetWritable();
        const auto entry_point = code.GetCursorAddress<void*>();

        A32Emitter emitter{prelude, code};
        emitter.Emit(ir_block);

        const size_t size = static_cast<size_t>(code.GetCursorAddress<uptr>() - reinterpret_cast<uptr>(entry_point));
        buffer.SetExecutable();

        return BlockDescriptor{entry_point, size};
    }();

    // Update data structures and backpatch

    block_descriptors[descriptor] = block_descriptor;

    return block_descriptor;
}

}  // namespace Dynarmic::Backend::Arm64
