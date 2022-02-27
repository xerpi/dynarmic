/* This file is part of the dynarmic project.
 * Copyright (c) 2022 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#pragma once

namespace Dynarmic {

struct SpinLock {
    void Lock() {
        volatile int* ptr = &storage;
        asm volatile(
            "   jmp 2f\n"
            "1:\n"
            "   pause\n"
            "2:\n"
            "   mov $1, %%eax\n"
            "   lock xchg %%eax, %[ptr]\n"
            "   test %%eax, %%eax\n"
            "   jnz 1b\n"
            : [ptr] "=m"(*ptr)
            : /* none */
            : "eax", "cc", "memory");
    }

    void Unlock() {
        volatile int* ptr = &storage;
        asm volatile(
            "   xor %%eax, %%eax\n"
            "   xchg %%eax, %[ptr]\n"
            "   mfence\n"
            : [ptr] "=m"(*ptr)
            : /* none */
            : "eax", "cc", "memory");
    }

    volatile int storage;
};

}  // namespace Dynarmic
