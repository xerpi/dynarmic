/* This file is part of the dynarmic project.
 * Copyright (c) 2021 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#pragma once

namespace vixl::aarch64 {
class MacroAssembler;
}  // namespace vixl::aarch64

namespace Dynarmic::IR {
class Block;
class Inst;
}  // namespace Dynarmic::IR

namespace Dynarmic::Backend::Arm64 {

struct PreludeInfo;

class A32Emitter {
public:
    A32Emitter(PreludeInfo& prelude, vixl::aarch64::MacroAssembler& code);

    void Emit(IR::Block& block);

private:
#define OPCODE(name, type, ...) void Emit##name(IR::Inst* inst);
#define A32OPC(name, type, ...) void EmitA32##name(IR::Inst* inst);
#define A64OPC(...)
#include "dynarmic/ir/opcodes.inc"
#undef OPCODE
#undef A32OPC
#undef A64OPC

    PreludeInfo& prelude;
    vixl::aarch64::MacroAssembler& code;
};

}  // namespace Dynarmic::Backend::Arm64
