/* This file is part of the dynarmic project.
 * Copyright (c) 2021 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#include <aarch64/constants-aarch64.h>

namespace Dynarmic::Backend::Arm64 {

constexpr auto NZCV = static_cast<vixl::aarch64::SystemRegister>(vixl::aarch64::SystemRegisterEncoder<3, 3, 4, 2, 0>::value);
constexpr auto FPCR = static_cast<vixl::aarch64::SystemRegister>(vixl::aarch64::SystemRegisterEncoder<3, 3, 4, 4, 0>::value);
constexpr auto FPSR = static_cast<vixl::aarch64::SystemRegister>(vixl::aarch64::SystemRegisterEncoder<3, 3, 4, 4, 1>::value);

}  // namespace Dynarmic::Backend::Arm64
