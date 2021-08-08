/* This file is part of the dynarmic project.
 * Copyright (c) 2021 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#pragma once

#include <array>

#include "dynarmic/common/common_types.h"

namespace Dynarmic::Backend::Arm64 {

class CodeBuffer final {
public:
    CodeBuffer(size_t size);
    ~CodeBuffer();

    void SetExecutable();
    void SetWritable();

    u8* GetPointer() const { return pointer; }
    size_t GetSize() const { return size; }

private:
    u8* pointer;
    size_t size;
};

}  // namespace Dynarmic::Backend::Arm64
