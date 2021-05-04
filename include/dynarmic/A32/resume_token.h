/* This file is part of the dynarmic project.
 * Copyright (c) 2021 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#pragma once

namespace Dynarmic {
namespace A32 {

class ResumeToken final {
public:
    ResumeToken() = delete;
    ResumeToken(const ResumeToken&) = delete;
    ResumeToken& operator=(const ResumeToken&) = delete;

    /// Halt execution.
    void Halt();

    /// Perform a code cache during execution (instead of waiting for a halt).
    void CheckCacheInvalidations();

private:
    void* impl;
};

} // namespace A32
} // namespace Dynarmic
