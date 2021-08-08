/* This file is part of the dynarmic project.
 * Copyright (c) 2021 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#include <array>
#include <utility>

#include <aarch64/macro-assembler-aarch64.h>
#include <catch2/catch.hpp>
#include <cpu-features.h>

#include "dynarmic/backend/arm64/code_buffer.h"
#include "dynarmic/common/common_types.h"

TEST_CASE("Host CPU supports", "[backend_arm64]") {
    auto cpu_info = vixl::CPUFeatures::InferFromOS();

    static constexpr std::array types{
#define V(SYMBOL, NAME, CPUINFO) std::make_pair(vixl::CPUFeatures::Feature::SYMBOL, NAME),
        VIXL_CPU_FEATURE_LIST(V)
#undef V
    };

    std::puts("CPU Features:\n");

    constexpr size_t line_max = 80;
    size_t line_length = 0;
    for (const auto& [type, name] : types) {
        if (cpu_info.Has(type)) {
            const size_t name_length = std::strlen(name) + 1;
            if ((line_length + name_length) >= line_max) {
                line_length = name_length;
                std::putchar('\n');
            } else if (line_length) {
                std::putchar(' ');
            }
            std::fputs(name, stdout);
            line_length += name_length;
        }
    }
    std::putchar('\n');
}

TEST_CASE("Vixl sanity check", "[backend_arm64]") {
    using namespace vixl::aarch64;

    Dynarmic::Backend::Arm64::CodeBuffer buffer{4096};
    MacroAssembler code{buffer.GetPointer(), buffer.GetSize()};

    buffer.SetWritable();

    auto abs_fn = code.GetCursorAddress<s64 (*)(s64)>();
    code.Cmp(x0, 0);
    code.Cneg(x0, x0, mi);
    code.Ret();

    code.FinalizeCode();

    buffer.SetExecutable();

    std::printf("abs(-42) = %lli\n", abs_fn(-42));
}
