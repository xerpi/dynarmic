/* This file is part of the dynarmic project.
 * Copyright (c) 2021 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#include <array>
#include <utility>

#include <catch2/catch.hpp>
#include <cpu-features.h>

TEST_CASE("Host CPU supports", "[a64]") {
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
