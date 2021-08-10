/* This file is part of the dynarmic project.
 * Copyright (c) 2016 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#pragma once

#include <array>

#include "dynarmic/common/common_types.h"

namespace Dynarmic::Backend::Arm64 {

constexpr size_t SpillCount = 64;

struct alignas(16) StackLayout {
    std::array<std::array<u64, 2>, SpillCount> spill;

    s64 cycles_to_run;

    u32 save_host_fpsr;
    u32 save_host_fpcr;

    bool check_bit;
};

static_assert(sizeof(StackLayout) % 16 == 0);

}  // namespace Dynarmic::Backend::Arm64
