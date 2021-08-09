/* This file is part of the dynarmic project.
 * Copyright (c) 2021 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#pragma once

namespace Dynarmic::Backend::Arm64 {

struct A32JitState;

struct PreludeInfo {
    using RunCodeFuncType = void (*)(A32JitState&, void*);
    RunCodeFuncType run_code = nullptr;
};

}  // namespace Dynarmic::Backend::Arm64
