/* This file is part of the dynarmic project.
 * Copyright (c) 2021 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#pragma once

namespace Dynarmic {
namespace A64 {

class ResumeToken final {
public:
    ResumeToken() = delete;
    ResumeToken(const ResumeToken&) = delete;
    ResumeToken& operator=(const ResumeToken&) = delete;

    /// Halt execution.
    void Halt();

private:
    void* impl;
};

} // namespace A64
} // namespace Dynarmic
