/* This file is part of the dynarmic project.
 * Copyright (c) 2021 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#include <memory>

#include <boost/icl/interval_set.hpp>

#include "dynarmic/backend/arm64/a32_address_space.h"
#include "dynarmic/backend/arm64/a32_jitstate.h"
#include "dynarmic/common/assert.h"
#include "dynarmic/common/scope_exit.h"
#include "dynarmic/interface/A32/a32.h"
#include "dynarmic/interface/A32/context.h"

namespace Dynarmic::A32 {

using namespace Backend::Arm64;

struct Context::Impl {
    A32JitState state;
};

Context::Context()
        : impl(std::make_unique<Context::Impl>()) {}

Context::~Context() = default;

Context::Context(const Context& ctx)
        : impl(std::make_unique<Context::Impl>(*ctx.impl)) {}

Context::Context(Context&& ctx) noexcept
        : impl(std::move(ctx.impl)) {}

Context& Context::operator=(const Context& ctx) {
    *impl = *ctx.impl;
    return *this;
}

Context& Context::operator=(Context&& ctx) noexcept {
    impl = std::move(ctx.impl);
    return *this;
}

struct Jit::Impl final {
    Impl(Jit* jit_interface, A32::UserConfig conf)
            : jit_interface(jit_interface)
            , current_address_space(conf) {}

    void Run() {
        ASSERT(!jit_interface->is_executing);
        jit_interface->is_executing = true;
        SCOPE_EXIT { jit_interface->is_executing = false; };
        current_state.halt_requested = false;

        // TODO: RSB Optimization
        const auto descriptor = current_state.GetLocationDescriptor();
        const auto entry_point = current_address_space.GetBlock(descriptor).entry_point;
        const auto run_code = current_address_space.GetPreludeInfo().run_code;
        run_code(current_state, entry_point);

        RequestCacheInvalidation();
    }

    void Step() {
        ASSERT(!jit_interface->is_executing);
        jit_interface->is_executing = true;
        SCOPE_EXIT { jit_interface->is_executing = false; };
        current_state.halt_requested = false;

        ASSERT_FALSE("Unimplemented");

        RequestCacheInvalidation();
    }

    void ClearCache() {
        invalidate_entire_cache = true;
        RequestCacheInvalidation();
    }

    void InvalidateCacheRange(std::uint32_t start_address, std::size_t length) {
        invalid_cache_ranges.add(boost::icl::discrete_interval<u32>::closed(start_address, static_cast<u32>(start_address + length - 1)));
        RequestCacheInvalidation();
    }

    void Reset() {
        current_state = {};
    }

    void HaltExecution() {
        current_state.halt_requested = true;
    }

    std::array<std::uint32_t, 16>& Regs() {
        return current_state.regs;
    }

    const std::array<std::uint32_t, 16>& Regs() const {
        return current_state.regs;
    }

    std::array<std::uint32_t, 64>& ExtRegs() {
        return current_state.ext_regs;
    }

    const std::array<std::uint32_t, 64>& ExtRegs() const {
        return current_state.ext_regs;
    }

    std::uint32_t Cpsr() const {
        return current_state.cpsr;
    }

    void SetCpsr(std::uint32_t value) {
        current_state.cpsr = value;
    }

    std::uint32_t Fpscr() const {
        return current_state.fpscr;
    }

    void SetFpscr(std::uint32_t value) {
        current_state.fpscr = value;
    }

    Context SaveContext() const {
        Context ctx;
        ctx.impl->state = current_state;
        return ctx;
    }

    void SaveContext(Context& ctx) const {
        ctx.impl->state = current_state;
    }

    void LoadContext(const Context& ctx) {
        current_state = ctx.impl->state;
    }

    void ClearExclusiveState() {
        current_state.exclusive_state = false;
    }

    void DumpDisassembly() const {
        ASSERT_FALSE("Unimplemented");
    }

private:
    void RequestCacheInvalidation() {
        if (jit_interface->is_executing) {
            current_state.halt_requested = true;
            return;
        }

        ASSERT_FALSE("Unimplemented");

        invalidate_entire_cache = false;
        invalid_cache_ranges.clear();
    }

    Jit* jit_interface;
    A32JitState current_state{};
    A32AddressSpace current_address_space;

    // Requests made during execution to invalidate the cache are queued up here.
    boost::icl::interval_set<u32> invalid_cache_ranges;
    bool invalidate_entire_cache = false;
};

Jit::Jit(UserConfig conf)
        : impl(std::make_unique<Impl>(this, conf)) {}

Jit::~Jit() = default;

void Jit::Run() {
    impl->Run();
}

void Jit::Step() {
    impl->Step();
}

void Jit::ClearCache() {
    impl->ClearCache();
}

void Jit::InvalidateCacheRange(std::uint32_t start_address, std::size_t length) {
    impl->InvalidateCacheRange(start_address, length);
}

void Jit::Reset() {
    impl->Reset();
}

void Jit::HaltExecution() {
    impl->HaltExecution();
}

std::array<std::uint32_t, 16>& Jit::Regs() {
    return impl->Regs();
}

const std::array<std::uint32_t, 16>& Jit::Regs() const {
    return impl->Regs();
}

std::array<std::uint32_t, 64>& Jit::ExtRegs() {
    return impl->ExtRegs();
}

const std::array<std::uint32_t, 64>& Jit::ExtRegs() const {
    return impl->ExtRegs();
}

std::uint32_t Jit::Cpsr() const {
    return impl->Cpsr();
}

void Jit::SetCpsr(std::uint32_t value) {
    impl->SetCpsr(value);
}

std::uint32_t Jit::Fpscr() const {
    return impl->Fpscr();
}

void Jit::SetFpscr(std::uint32_t value) {
    impl->SetFpscr(value);
}

Context Jit::SaveContext() const {
    return impl->SaveContext();
}

void Jit::SaveContext(Context& ctx) const {
    impl->SaveContext(ctx);
}

void Jit::LoadContext(const Context& ctx) {
    impl->LoadContext(ctx);
}

void Jit::ClearExclusiveState() {
    impl->ClearExclusiveState();
}

void Jit::DumpDisassembly() const {
    impl->DumpDisassembly();
}

}  // namespace Dynarmic::A32
