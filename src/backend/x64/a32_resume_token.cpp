/* This file is part of the dynarmic project.
 * Copyright (c) 2016 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#include <dynarmic/A32/resume_token.h>

#include "backend/x64/abi.h"
#include "backend/x64/stack_layout.h"

namespace Dynarmic::A32 {

using namespace Backend::X64;

void ResumeToken::Halt() {

}

void ResumeToken::CheckCacheInvalidations() {

}

} // namespace Dynarmic::A32
