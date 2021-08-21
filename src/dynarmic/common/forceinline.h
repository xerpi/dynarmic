/* This file is part of the dynarmic project.
 * Copyright (c) 2018 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#pragma once

#if defined(__clang) || defined(__GNUC__)
#    define forceinline __attribute__((always_inline))
#elif defined(_MSC_VER)
#    define forceinline __forceinline
#else
#    define forceinline
#endif
