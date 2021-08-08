/* This file is part of the dynarmic project.
 * Copyright (c) 2021 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#pragma once

#include <array>

#include "dynarmic/common/common_types.h"

namespace Dynarmic::Backend::Arm64 {

struct A32JitState {
    std::array<u32, 16> regs{};
    std::array<u32, 64> ext_regs{};
    u32 cpsr = 0;
    u32 fpscr = 0;
    bool exclusive_state = false;

    bool halt_requested = false;
};

}  // namespace Dynarmic::Backend::Arm64
