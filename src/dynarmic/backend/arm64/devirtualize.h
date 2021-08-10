/* This file is part of the dynarmic project.
 * Copyright (c) 2021 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#pragma once

#include <aarch64/macro-assembler-aarch64.h>
#include <mp/traits/function_info.h>

#include "dynarmic/common/assert.h"
#include "dynarmic/common/cast_util.h"
#include "dynarmic/common/common_types.h"

namespace Dynarmic::Backend::Arm64 {

template<auto mfp>
struct DevirtualizationInfo {
    mp::equivalent_function_type_with_class<decltype(mfp)>* function_pointer;
    u64 this_pointer;

    void EmitCall(vixl::aarch64::MacroAssembler& code) {
        using namespace vixl::aarch64;

        code.Mov(x0, this_pointer);
        code.CallRuntime(function_pointer);
    }
};

template<auto mfp>
DevirtualizationInfo<mfp> Devirtualize(mp::class_type<decltype(mfp)>* this_) {
    struct MemberFunctionPointer {
        /// For a non-virtual function, this is a simple function pointer.
        /// For a virtual function, it is virtual table offset in bytes.
        u64 ptr;
        /// Required adjustment to `this` shifted left by 1. LSB is 1 if the member function is virtual.
        u64 adj;
    } mfp_struct = Common::BitCast<MemberFunctionPointer>(mfp);

    static_assert(sizeof(MemberFunctionPointer) == 16);
    static_assert(sizeof(MemberFunctionPointer) == sizeof(mfp));

    const u64 this_ptr = Common::BitCast<u64>(this_) + (mfp_struct.adj >> 1);

    u64 fn_ptr = mfp_struct.ptr;
    if (mfp_struct.adj & 1) {
        const u64 vtable = Common::BitCastPointee<u64>(this_ptr);
        fn_ptr = Common::BitCastPointee<u64>(vtable + fn_ptr);
    }

    return {Common::BitCast<mp::equivalent_function_type_with_class<decltype(mfp)>*>(fn_ptr), this_ptr};
}

}  // namespace Dynarmic::Backend::Arm64
