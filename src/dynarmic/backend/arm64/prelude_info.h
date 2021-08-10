/* This file is part of the dynarmic project.
 * Copyright (c) 2021 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#pragma once

#include <aarch64/assembler-aarch64.h>

namespace Dynarmic::Backend::Arm64 {

struct A32JitState;

struct PreludeInfo {
    using RunCodeFuncType = void (*)(A32JitState&, void*);
    RunCodeFuncType run_code = nullptr;

    vixl::aarch64::Label return_from_run_code;
    vixl::aarch64::Label return_to_caller;
};

}  // namespace Dynarmic::Backend::Arm64
