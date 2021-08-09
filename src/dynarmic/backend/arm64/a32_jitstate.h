/* This file is part of the dynarmic project.
 * Copyright (c) 2021 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#pragma once

#include <array>

#include "dynarmic/common/common_types.h"
#include "dynarmic/frontend/A32/location_descriptor.h"
#include "dynarmic/ir/location_descriptor.h"

namespace Dynarmic::Backend::Arm64 {

struct A32JitState {
    std::array<u32, 16> regs{};
    std::array<u32, 64> ext_regs{};
    u32 cpsr = 0;
    u32 fpscr = 0;
    bool exclusive_state = false;

    bool halt_requested = false;

    IR::LocationDescriptor GetLocationDescriptor() const {
        // TODO: Optimize
        return A32::LocationDescriptor{regs[15], A32::PSR{cpsr}, A32::FPSCR{fpscr}};
    }
};

}  // namespace Dynarmic::Backend::Arm64
