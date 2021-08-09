/* This file is part of the dynarmic project.
 * Copyright (c) 2021 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#include "dynarmic/backend/arm64/a32_emitter.h"

#include <aarch64/macro-assembler-aarch64.h>

#include "dynarmic/common/assert.h"
#include "dynarmic/ir/microinstruction.h"

namespace Dynarmic::Backend::Arm64 {

A32Emitter::A32Emitter(const PreludeInfo& prelude, vixl::aarch64::MacroAssembler& code)
        : prelude(prelude), code(code) {}

void A32Emitter::Emit(IR::Block&) {
    (void)code;
    (void)prelude;

    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32SetCheckBit(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32GetRegister(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32GetExtendedRegister32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32GetExtendedRegister64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32GetVector(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32SetRegister(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32SetExtendedRegister32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32SetExtendedRegister64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32SetVector(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32GetCpsr(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32SetCpsr(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32SetCpsrNZCV(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32SetCpsrNZCVRaw(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32SetCpsrNZCVQ(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32GetNFlag(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32SetNFlag(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32GetZFlag(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32SetZFlag(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32GetCFlag(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32SetCFlag(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32GetVFlag(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32SetVFlag(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32OrQFlag(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32GetGEFlags(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32SetGEFlags(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32SetGEFlagsCompressed(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32BXWritePC(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32UpdateUpperLocationDescriptor(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32CallSupervisor(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32ExceptionRaised(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32DataSynchronizationBarrier(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32DataMemoryBarrier(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32InstructionSynchronizationBarrier(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32GetFpscr(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32SetFpscr(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32GetFpscrNZCV(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32SetFpscrNZCV(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32ClearExclusive(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32ReadMemory8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32ReadMemory16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32ReadMemory32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32ReadMemory64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32ExclusiveReadMemory8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32ExclusiveReadMemory16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32ExclusiveReadMemory32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32ExclusiveReadMemory64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32WriteMemory8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32WriteMemory16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32WriteMemory32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32WriteMemory64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32ExclusiveWriteMemory8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32ExclusiveWriteMemory16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32ExclusiveWriteMemory32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32ExclusiveWriteMemory64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32CoprocInternalOperation(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32CoprocSendOneWord(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32CoprocSendTwoWords(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32CoprocGetOneWord(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32CoprocGetTwoWords(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32CoprocLoadWords(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitA32CoprocStoreWords(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVoid(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitIdentity(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitBreakpoint(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitCallHostFunction(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPushRSB(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitGetCarryFromOp(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitGetOverflowFromOp(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitGetGEFromOp(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitGetNZCVFromOp(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitGetUpperFromOp(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitGetLowerFromOp(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitNZCVFromPackedFlags(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPack2x32To1x64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPack2x64To1x128(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitLeastSignificantWord(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitLeastSignificantHalf(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitLeastSignificantByte(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitMostSignificantWord(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitMostSignificantBit(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitIsZero32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitIsZero64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitTestBit(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitConditionalSelect32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitConditionalSelect64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitConditionalSelectNZCV(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitLogicalShiftLeft32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitLogicalShiftLeft64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitLogicalShiftRight32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitLogicalShiftRight64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitArithmeticShiftRight32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitArithmeticShiftRight64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitRotateRight32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitRotateRight64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitRotateRightExtended(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitLogicalShiftLeftMasked32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitLogicalShiftLeftMasked64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitLogicalShiftRightMasked32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitLogicalShiftRightMasked64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitArithmeticShiftRightMasked32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitArithmeticShiftRightMasked64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitRotateRightMasked32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitRotateRightMasked64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitAdd32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitAdd64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitSub32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitSub64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitMul32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitMul64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitSignedMultiplyHigh64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitUnsignedMultiplyHigh64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitUnsignedDiv32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitUnsignedDiv64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitSignedDiv32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitSignedDiv64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitAnd32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitAnd64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitAndNot32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitAndNot64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitEor32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitEor64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitOr32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitOr64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitNot32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitNot64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitSignExtendByteToWord(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitSignExtendHalfToWord(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitSignExtendByteToLong(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitSignExtendHalfToLong(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitSignExtendWordToLong(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitZeroExtendByteToWord(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitZeroExtendHalfToWord(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitZeroExtendByteToLong(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitZeroExtendHalfToLong(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitZeroExtendWordToLong(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitZeroExtendLongToQuad(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitByteReverseWord(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitByteReverseHalf(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitByteReverseDual(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitCountLeadingZeros32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitCountLeadingZeros64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitExtractRegister32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitExtractRegister64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitReplicateBit32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitReplicateBit64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitMaxSigned32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitMaxSigned64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitMaxUnsigned32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitMaxUnsigned64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitMinSigned32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitMinSigned64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitMinUnsigned32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitMinUnsigned64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitSignedSaturatedAdd8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitSignedSaturatedAdd16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitSignedSaturatedAdd32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitSignedSaturatedAdd64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitSignedSaturatedDoublingMultiplyReturnHigh16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitSignedSaturatedDoublingMultiplyReturnHigh32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitSignedSaturatedSub8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitSignedSaturatedSub16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitSignedSaturatedSub32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitSignedSaturatedSub64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitSignedSaturation(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitUnsignedSaturatedAdd8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitUnsignedSaturatedAdd16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitUnsignedSaturatedAdd32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitUnsignedSaturatedAdd64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitUnsignedSaturatedSub8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitUnsignedSaturatedSub16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitUnsignedSaturatedSub32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitUnsignedSaturatedSub64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitUnsignedSaturation(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedAdd8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedAdd16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedAdd32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedAdd64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedSub8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedSub16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedSub32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedSub64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorUnsignedSaturatedAdd8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorUnsignedSaturatedAdd16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorUnsignedSaturatedAdd32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorUnsignedSaturatedAdd64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorUnsignedSaturatedSub8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorUnsignedSaturatedSub16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorUnsignedSaturatedSub32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorUnsignedSaturatedSub64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPackedAddU8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPackedAddS8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPackedSubU8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPackedSubS8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPackedAddU16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPackedAddS16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPackedSubU16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPackedSubS16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPackedAddSubU16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPackedAddSubS16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPackedSubAddU16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPackedSubAddS16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPackedHalvingAddU8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPackedHalvingAddS8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPackedHalvingSubU8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPackedHalvingSubS8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPackedHalvingAddU16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPackedHalvingAddS16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPackedHalvingSubU16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPackedHalvingSubS16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPackedHalvingAddSubU16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPackedHalvingAddSubS16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPackedHalvingSubAddU16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPackedHalvingSubAddS16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPackedSaturatedAddU8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPackedSaturatedAddS8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPackedSaturatedSubU8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPackedSaturatedSubS8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPackedSaturatedAddU16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPackedSaturatedAddS16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPackedSaturatedSubU16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPackedSaturatedSubS16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPackedAbsDiffSumS8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitPackedSelect(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitCRC32Castagnoli8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitCRC32Castagnoli16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitCRC32Castagnoli32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitCRC32Castagnoli64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitCRC32ISO8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitCRC32ISO16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitCRC32ISO32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitCRC32ISO64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitAESDecryptSingleRound(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitAESEncryptSingleRound(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitAESInverseMixColumns(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitAESMixColumns(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitSM4AccessSubstitutionBox(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorGetElement8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorGetElement16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorGetElement32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorGetElement64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSetElement8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSetElement16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSetElement32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSetElement64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorAbs8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorAbs16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorAbs32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorAbs64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorAdd8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorAdd16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorAdd32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorAdd64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorAnd(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorAndNot(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorArithmeticShiftRight8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorArithmeticShiftRight16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorArithmeticShiftRight32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorArithmeticShiftRight64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorArithmeticVShift8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorArithmeticVShift16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorArithmeticVShift32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorArithmeticVShift64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorBroadcastLower8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorBroadcastLower16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorBroadcastLower32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorBroadcast8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorBroadcast16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorBroadcast32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorBroadcast64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorBroadcastElementLower8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorBroadcastElementLower16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorBroadcastElementLower32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorBroadcastElement8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorBroadcastElement16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorBroadcastElement32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorBroadcastElement64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorCountLeadingZeros8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorCountLeadingZeros16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorCountLeadingZeros32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorDeinterleaveEven8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorDeinterleaveEven16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorDeinterleaveEven32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorDeinterleaveEven64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorDeinterleaveEvenLower8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorDeinterleaveEvenLower16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorDeinterleaveEvenLower32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorDeinterleaveEvenLower64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorDeinterleaveOdd8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorDeinterleaveOdd16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorDeinterleaveOdd32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorDeinterleaveOdd64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorDeinterleaveOddLower8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorDeinterleaveOddLower16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorDeinterleaveOddLower32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorDeinterleaveOddLower64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorEor(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorEqual8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorEqual16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorEqual32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorEqual64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorEqual128(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorExtract(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorExtractLower(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorGreaterS8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorGreaterS16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorGreaterS32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorGreaterS64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorHalvingAddS8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorHalvingAddS16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorHalvingAddS32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorHalvingAddU8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorHalvingAddU16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorHalvingAddU32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorHalvingSubS8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorHalvingSubS16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorHalvingSubS32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorHalvingSubU8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorHalvingSubU16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorHalvingSubU32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorInterleaveLower8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorInterleaveLower16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorInterleaveLower32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorInterleaveLower64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorInterleaveUpper8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorInterleaveUpper16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorInterleaveUpper32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorInterleaveUpper64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorLogicalShiftLeft8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorLogicalShiftLeft16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorLogicalShiftLeft32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorLogicalShiftLeft64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorLogicalShiftRight8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorLogicalShiftRight16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorLogicalShiftRight32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorLogicalShiftRight64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorLogicalVShift8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorLogicalVShift16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorLogicalVShift32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorLogicalVShift64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorMaxS8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorMaxS16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorMaxS32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorMaxS64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorMaxU8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorMaxU16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorMaxU32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorMaxU64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorMinS8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorMinS16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorMinS32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorMinS64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorMinU8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorMinU16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorMinU32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorMinU64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorMultiply8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorMultiply16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorMultiply32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorMultiply64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorNarrow16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorNarrow32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorNarrow64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorNot(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorOr(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorPairedAddLower8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorPairedAddLower16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorPairedAddLower32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorPairedAddSignedWiden8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorPairedAddSignedWiden16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorPairedAddSignedWiden32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorPairedAddUnsignedWiden8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorPairedAddUnsignedWiden16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorPairedAddUnsignedWiden32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorPairedAdd8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorPairedAdd16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorPairedAdd32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorPairedAdd64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorPairedMaxS8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorPairedMaxS16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorPairedMaxS32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorPairedMaxU8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorPairedMaxU16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorPairedMaxU32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorPairedMinS8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorPairedMinS16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorPairedMinS32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorPairedMinU8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorPairedMinU16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorPairedMinU32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorPolynomialMultiply8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorPolynomialMultiplyLong8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorPolynomialMultiplyLong64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorPopulationCount(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorReverseBits(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorRoundingHalvingAddS8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorRoundingHalvingAddS16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorRoundingHalvingAddS32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorRoundingHalvingAddU8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorRoundingHalvingAddU16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorRoundingHalvingAddU32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorRoundingShiftLeftS8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorRoundingShiftLeftS16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorRoundingShiftLeftS32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorRoundingShiftLeftS64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorRoundingShiftLeftU8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorRoundingShiftLeftU16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorRoundingShiftLeftU32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorRoundingShiftLeftU64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorShuffleHighHalfwords(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorShuffleLowHalfwords(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorShuffleWords(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignExtend8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignExtend16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignExtend32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignExtend64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedAbsoluteDifference8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedAbsoluteDifference16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedAbsoluteDifference32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedMultiply16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedMultiply32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedAbs8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedAbs16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedAbs32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedAbs64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedAccumulateUnsigned8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedAccumulateUnsigned16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedAccumulateUnsigned32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedAccumulateUnsigned64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedDoublingMultiply16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedDoublingMultiply32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedDoublingMultiplyLong16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedDoublingMultiplyLong32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedNarrowToSigned16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedNarrowToSigned32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedNarrowToSigned64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedNarrowToUnsigned16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedNarrowToUnsigned32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedNarrowToUnsigned64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedNeg8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedNeg16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedNeg32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedNeg64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedShiftLeft8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedShiftLeft16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedShiftLeft32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedShiftLeft64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedShiftLeftUnsigned8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedShiftLeftUnsigned16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedShiftLeftUnsigned32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSignedSaturatedShiftLeftUnsigned64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSub8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSub16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSub32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorSub64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorTable(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorTableLookup64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorTableLookup128(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorTranspose8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorTranspose16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorTranspose32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorTranspose64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorUnsignedAbsoluteDifference8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorUnsignedAbsoluteDifference16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorUnsignedAbsoluteDifference32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorUnsignedMultiply16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorUnsignedMultiply32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorUnsignedRecipEstimate(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorUnsignedRecipSqrtEstimate(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorUnsignedSaturatedAccumulateSigned8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorUnsignedSaturatedAccumulateSigned16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorUnsignedSaturatedAccumulateSigned32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorUnsignedSaturatedAccumulateSigned64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorUnsignedSaturatedNarrow16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorUnsignedSaturatedNarrow32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorUnsignedSaturatedNarrow64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorUnsignedSaturatedShiftLeft8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorUnsignedSaturatedShiftLeft16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorUnsignedSaturatedShiftLeft32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorUnsignedSaturatedShiftLeft64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorZeroExtend8(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorZeroExtend16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorZeroExtend32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorZeroExtend64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitVectorZeroUpper(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitZeroVector(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPAbs16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPAbs32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPAbs64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPAdd32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPAdd64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPCompare32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPCompare64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPDiv32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPDiv64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPMax32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPMax64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPMaxNumeric32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPMaxNumeric64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPMin32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPMin64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPMinNumeric32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPMinNumeric64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPMul32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPMul64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPMulAdd16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPMulAdd32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPMulAdd64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPMulX32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPMulX64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPNeg16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPNeg32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPNeg64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPRecipEstimate16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPRecipEstimate32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPRecipEstimate64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPRecipExponent16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPRecipExponent32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPRecipExponent64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPRecipStepFused16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPRecipStepFused32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPRecipStepFused64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPRoundInt16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPRoundInt32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPRoundInt64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPRSqrtEstimate16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPRSqrtEstimate32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPRSqrtEstimate64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPRSqrtStepFused16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPRSqrtStepFused32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPRSqrtStepFused64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPSqrt32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPSqrt64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPSub32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPSub64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPHalfToDouble(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPHalfToSingle(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPSingleToDouble(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPSingleToHalf(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPDoubleToHalf(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPDoubleToSingle(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPDoubleToFixedS16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPDoubleToFixedS32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPDoubleToFixedS64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPDoubleToFixedU16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPDoubleToFixedU32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPDoubleToFixedU64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPHalfToFixedS16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPHalfToFixedS32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPHalfToFixedS64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPHalfToFixedU16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPHalfToFixedU32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPHalfToFixedU64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPSingleToFixedS16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPSingleToFixedS32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPSingleToFixedS64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPSingleToFixedU16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPSingleToFixedU32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPSingleToFixedU64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPFixedU16ToSingle(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPFixedS16ToSingle(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPFixedU16ToDouble(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPFixedS16ToDouble(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPFixedU32ToSingle(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPFixedS32ToSingle(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPFixedU32ToDouble(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPFixedS32ToDouble(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPFixedU64ToDouble(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPFixedU64ToSingle(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPFixedS64ToDouble(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPFixedS64ToSingle(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorAbs16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorAbs32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorAbs64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorAdd32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorAdd64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorDiv32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorDiv64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorEqual16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorEqual32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorEqual64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorFromHalf32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorFromSignedFixed32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorFromSignedFixed64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorFromUnsignedFixed32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorFromUnsignedFixed64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorGreater32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorGreater64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorGreaterEqual32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorGreaterEqual64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorMax32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorMax64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorMin32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorMin64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorMul32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorMul64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorMulAdd16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorMulAdd32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorMulAdd64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorMulX32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorMulX64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorNeg16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorNeg32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorNeg64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorPairedAdd32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorPairedAdd64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorPairedAddLower32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorPairedAddLower64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorRecipEstimate16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorRecipEstimate32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorRecipEstimate64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorRecipStepFused16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorRecipStepFused32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorRecipStepFused64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorRoundInt16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorRoundInt32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorRoundInt64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorRSqrtEstimate16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorRSqrtEstimate32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorRSqrtEstimate64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorRSqrtStepFused16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorRSqrtStepFused32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorRSqrtStepFused64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorSqrt32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorSqrt64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorSub32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorSub64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorToHalf32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorToSignedFixed16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorToSignedFixed32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorToSignedFixed64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorToUnsignedFixed16(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorToUnsignedFixed32(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

void A32Emitter::EmitFPVectorToUnsignedFixed64(IR::Inst*) {
    ASSERT_FALSE("Unimplemented");
}

}  // namespace Dynarmic::Backend::Arm64
