/* This file is part of the dynarmic project.
 * Copyright (c) 2021 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#include "dynarmic/backend/arm64/code_buffer.h"

#include <sys/mman.h>
#ifdef __APPLE__
#    include <libkern/OSCacheControl.h>
#    include <sys/sysctl.h>
#endif

#include "dynarmic/common/assert.h"

namespace Dynarmic::Backend::Arm64 {

// Required macOS entitlemenets (if Hardened Runtime enabled):
// com.apple.security.cs.allow-jit (for MAP_JIT)
// See also: https://developer.apple.com/documentation/apple-silicon/porting-just-in-time-compilers-to-apple-silicon

CodeBuffer::CodeBuffer(size_t size_)
        : size(size_) {
#ifdef __APPLE__
    pointer = reinterpret_cast<u8*>(mmap(nullptr, size_, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS | MAP_JIT, -1, 0));
    SetWritable();
#else
    pointer = reinterpret_cast<u8*>(mmap(nullptr, size_, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0));
#endif
    ASSERT(pointer != nullptr);
}

CodeBuffer::~CodeBuffer() {
    munmap(pointer, size);
}

void CodeBuffer::SetExecutable() {
#ifdef __APPLE__
    pthread_jit_write_protect_np(1);
    sys_icache_invalidate(pointer, size);  // TODO: Minimize invalidation region
#else
    const int result = mprotect(pointer, size, PROT_READ | PROT_EXEC);
    ASSERT(result != 0);
#endif
}

void CodeBuffer::SetWritable() {
#ifdef __APPLE__
    pthread_jit_write_protect_np(0);
#else
    const int result = mprotect(pointer, size, PROT_READ | PROT_WRITE);
    ASSERT(result != 0);
#endif
}

}  // namespace Dynarmic::Backend::Arm64
