/* This file is part of the dynarmic project.
 * Copyright (c) 2022 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#include <array>
#include <string>
#include <tuple>
#include <vector>

#include <dynarmic/common/common_types.h>
#include <dynarmic/frontend/A32/a32_location_descriptor.h>
#include <dynarmic/frontend/A32/a32_types.h>
#include <dynarmic/frontend/A32/ITState.h>
#include <dynarmic/frontend/A32/translate/a32_translate.h>
#include <dynarmic/ir/basic_block.h>
#include <dynarmic/ir/opcodes.h>

#include "A32/testenv.h"
#include "fuzz_util.h"
#include "rand_int.h"

using namespace Dynarmic;

bool ShouldTestInst(u32 instruction, u32 pc, bool is_thumb, bool is_last_inst, A32::ITState it_state = {}) {
    const A32::LocationDescriptor location = A32::LocationDescriptor{pc, {}, {}}.SetTFlag(is_thumb).SetIT(it_state);
    IR::Block block{location};
    const bool should_continue = A32::TranslateSingleInstruction(block, location, instruction);

    if (!should_continue && !is_last_inst) {
        return false;
    }

    if (auto terminal = block.GetTerminal(); boost::get<IR::Term::Interpret>(&terminal)) {
        return false;
    }

    for (const auto& ir_inst : block) {
        switch (ir_inst.GetOpcode()) {
        case IR::Opcode::A32ExceptionRaised:
        case IR::Opcode::A32CallSupervisor:
        case IR::Opcode::A32CoprocInternalOperation:
        case IR::Opcode::A32CoprocSendOneWord:
        case IR::Opcode::A32CoprocSendTwoWords:
        case IR::Opcode::A32CoprocGetOneWord:
        case IR::Opcode::A32CoprocGetTwoWords:
        case IR::Opcode::A32CoprocLoadWords:
        case IR::Opcode::A32CoprocStoreWords:
            return false;
        case IR::Opcode::A32ClearExclusive:
        case IR::Opcode::A32ReadMemory8:
        case IR::Opcode::A32ReadMemory16:
        case IR::Opcode::A32ReadMemory32:
        case IR::Opcode::A32ReadMemory64:
        case IR::Opcode::A32ExclusiveReadMemory8:
        case IR::Opcode::A32ExclusiveReadMemory16:
        case IR::Opcode::A32ExclusiveReadMemory32:
        case IR::Opcode::A32ExclusiveReadMemory64:
        case IR::Opcode::A32WriteMemory8:
        case IR::Opcode::A32WriteMemory16:
        case IR::Opcode::A32WriteMemory32:
        case IR::Opcode::A32WriteMemory64:
        case IR::Opcode::A32ExclusiveWriteMemory8:
        case IR::Opcode::A32ExclusiveWriteMemory16:
        case IR::Opcode::A32ExclusiveWriteMemory32:
        case IR::Opcode::A32ExclusiveWriteMemory64:
            return false;
        case IR::Opcode::A32SetRegister:
            return ir_inst.GetArg(0).GetA32RegRef() != A32::Reg::LR;
        default:
            continue;
        }
    }

    return true;
}

std::vector<u16> GenRandomThumbInst(u32 pc, bool is_last_inst, A32::ITState it_state = {}) {
    static const struct InstructionGeneratorInfo {
        std::vector<InstructionGenerator> generators;
        std::vector<InstructionGenerator> invalid;
    } instructions = [] {
        const std::vector<std::tuple<std::string, const char*>> list{
#define INST(fn, name, bitstring) {#fn, bitstring},
#include "dynarmic/frontend/A32/decoder/thumb16.inc"
#undef INST
        };

        std::vector<InstructionGenerator> generators;
        std::vector<InstructionGenerator> invalid;

        // List of instructions not to test
        static constexpr std::array do_not_test{
            "thumb16_BKPT",
            "thumb16_IT",
            "thumb16_SETEND",
            "thumb16_CPS",
        };

        for (const auto& [fn, bitstring] : list) {
            if (std::find(do_not_test.begin(), do_not_test.end(), fn) != do_not_test.end()) {
                invalid.emplace_back(InstructionGenerator{bitstring});
                continue;
            }
            generators.emplace_back(InstructionGenerator{bitstring});
        }

        return InstructionGeneratorInfo{generators, invalid};
    }();

    while (true) {
        const size_t index = RandInt<size_t>(0, instructions.generators.size() - 1);
        const u32 inst = instructions.generators[index].Generate();

        if (ShouldTestInst(inst, pc, true, is_last_inst, it_state)) {
            return {static_cast<u16>(inst)};
        }
    }
}

auto GenGenRandomThumbInst(std::vector<std::string_view> do_test) {
    static const struct InstructionGeneratorInfo {
        std::vector<InstructionGenerator> generators;
        std::vector<InstructionGenerator> invalid;
    } instructions = [&do_test] {
        const std::vector<std::tuple<std::string, const char*>> list{
#define INST(fn, name, bitstring) {#fn, bitstring},
#include "dynarmic/frontend/A32/decoder/thumb16.inc"
#include "dynarmic/frontend/A32/decoder/thumb32.inc"
#undef INST
        };

        std::vector<InstructionGenerator> generators;
        std::vector<InstructionGenerator> invalid;

        for (const auto& [fn, bitstring] : list) {
            if (std::find(do_test.begin(), do_test.end(), fn) == do_test.end()) {
                invalid.emplace_back(InstructionGenerator{bitstring});
                continue;
            }
            generators.emplace_back(InstructionGenerator{bitstring});
        }

        return InstructionGeneratorInfo{generators, invalid};
    }();

    return [=](u32 pc, bool is_last_inst, A32::ITState it_state = {}) -> std::vector<u16> {
        while (true) {
            const size_t index = RandInt<size_t>(0, instructions.generators.size() - 1);
            const u32 inst = instructions.generators[index].Generate();
            const bool is_four_bytes = (inst >> 16) != 0;

            if (ShouldTestInst(is_four_bytes ? Common::SwapHalves32(inst) : inst, pc, true, is_last_inst, it_state)) {
                if (is_four_bytes)
                    return {static_cast<u16>(inst >> 16), static_cast<u16>(inst)};
                return {static_cast<u16>(inst)};
            }
        }
    };
}

Dynarmic::A32::UserConfig GetUserConfig(ThumbTestEnv& testenv) {
    Dynarmic::A32::UserConfig user_config;
    user_config.optimizations = no_optimizations;
    user_config.callbacks = &testenv;
    return user_config;
}

void ExecuteTest(std::vector<u16> instructions) {
    const u32 start_address = 0x1000;
    const u32 start_cpsr = (RandInt<u32>(0, 0xF) << 28) | 0x1F0;

    std::array<u32, 16> start_regs;
    std::generate(start_regs.begin(), start_regs.end(), [] { return RandInt<u32>(0, ~u32(0)); });
    start_regs[14] = 0 ;
    start_regs[15] = start_address;
     
    ThumbTestEnv env{};
    Dynarmic::A32::Jit jit{GetUserConfig(env)};

    const u32 num_words_to_initial = start_address / sizeof(u16);

    env.code_mem.resize(num_words_to_initial + instructions.size());
    env.code_mem[0] = ThumbTestEnv::infinite_loop;

    std::copy(instructions.begin(), instructions.end(), env.code_mem.begin() + num_words_to_initial);
    env.PadCodeMem();

    jit.Regs() = start_regs;
    jit.Regs()[14] = 1;
    jit.SetCpsr(start_cpsr);

    env.ticks_left = instructions.size();
    jit.Run();

    fmt::print("new PrecomputedTestCase()\n{{\n");

    fmt::print("    Instructions = new ushort[] {{ ");
    for (u16 inst : instructions) {
        fmt::print("0x{:04x}, ", inst);
    }
    fmt::print("0x{:04x}", ThumbTestEnv::infinite_loop);
    fmt::print(" }},\n");

    fmt::print("    StartRegs = new uint[] {{ ");
    for (int i = 0; i < 15; i++) {
        fmt::print("0x{:08x}, ", start_regs[i]);
    }
    fmt::print("0x{:08x}", start_cpsr);
    fmt::print(" }},\n");

    fmt::print("    FinalRegs = new uint[] {{ ");
    for (int i = 0; i < 15; i++) {
        fmt::print("0x{:08x}, ", jit.Regs()[i]);
    }
    fmt::print("0x{:08x}", jit.Cpsr());
    fmt::print(" }},\n");


    fmt::print("}},\n");
}

void GenerateShortTestCase() {
    std::vector<u16> instructions;

    for (size_t i = 0; i < 1000; i++) {
        const std::vector<u16> inst = GenRandomThumbInst(static_cast<u32>(instructions.size() * sizeof(u16)), false);
        instructions.insert(instructions.end(), inst.begin(), inst.end());
    }

    instructions.push_back(0x4770); // bx lr

    ExecuteTest(instructions);
}

void GenerateTestCaseWithIT() {
    std::vector<u16> instructions;

    while (instructions.size() < 1000) {
        const size_t instructions_this_pass = RandInt<size_t>(0, 25);

        for (size_t i = 0; i < instructions_this_pass; i++) {
            const std::vector<u16> inst = GenRandomThumbInst(static_cast<u32>(instructions.size() * sizeof(u16)), false);
            instructions.insert(instructions.end(), inst.begin(), inst.end());
        }

        // Emit IT instruction
        A32::ITState it_state = [&] {
            while (true) {
                const u16 imm8 = RandInt<u16>(0, 0xFF);
                if (Common::Bits<0, 3>(imm8) == 0b0000 || Common::Bits<4, 7>(imm8) == 0b1111 || (Common::Bits<4, 7>(imm8) == 0b1110 && Common::BitCount(Common::Bits<0, 3>(imm8)) != 1)) {
                    continue;
                }
                instructions.push_back(0b1011111100000000 | imm8);
                return A32::ITState{static_cast<u8>(imm8)};
            }
        }();

        while (it_state.IsInITBlock()) {
            const std::vector<u16> inst = GenRandomThumbInst(static_cast<u32>(instructions.size() * sizeof(u16)), false, it_state);
            instructions.insert(instructions.end(), inst.begin(), inst.end());
            it_state = it_state.Advance();
        }
    }

    instructions.push_back(0x4770); // bx lr

    ExecuteTest(instructions);
}

void GenerateIT() {
    std::vector<u16> instructions;

    // Emit IT instruction
    A32::ITState it_state = [&] {
        while (true) {
            const u16 imm8 = RandInt<u16>(0, 0xFF);
            if (Common::Bits<0, 3>(imm8) == 0b0000 || Common::Bits<4, 7>(imm8) == 0b1111 || (Common::Bits<4, 7>(imm8) == 0b1110 && Common::BitCount(Common::Bits<0, 3>(imm8)) != 1)) {
                continue;
            }
            instructions.push_back(0b1011111100000000 | imm8);
            return A32::ITState{static_cast<u8>(imm8)};
        }
    }();

    while (it_state.IsInITBlock()) {
        const std::vector<u16> inst = GenRandomThumbInst(static_cast<u32>(instructions.size() * sizeof(u16)), false, it_state);
        instructions.insert(instructions.end(), inst.begin(), inst.end());
        it_state = it_state.Advance();
    }

    instructions.push_back(0x4770); // bx lr

    ExecuteTest(instructions);
}

void GenerateTestCaseForInstruction(std::string_view inst_name) {
    auto gen = GenGenRandomThumbInst({inst_name});

    std::vector<u16> instructions;

    for (size_t i = 0; i < 1; i++) {
        const std::vector<u16> inst = gen(static_cast<u32>(instructions.size() * sizeof(u16)), false);
        instructions.insert(instructions.end(), inst.begin(), inst.end());
    }
    instructions.push_back(0x4770);  // bx lr

    ExecuteTest(instructions);
}

int main(int, char**) {
    fmt::print("// TST (reg)");
    for (int i = 0; i < 5; i++)
        GenerateTestCaseForInstruction("thumb32_TST_reg");
    fmt::print("// AND (reg)");
    for (int i = 0; i < 5; i++)
        GenerateTestCaseForInstruction("thumb32_AND_reg");
    fmt::print("// BIC (reg)");
    for (int i = 0; i < 5; i++)
        GenerateTestCaseForInstruction("thumb32_BIC_reg");
    fmt::print("// MOV (reg)");
    for (int i = 0; i < 5; i++)
        GenerateTestCaseForInstruction("thumb32_MOV_reg");
    fmt::print("// ORR (reg)");
    for (int i = 0; i < 5; i++)
        GenerateTestCaseForInstruction("thumb32_ORR_reg");
    fmt::print("// MVN (reg)");
    for (int i = 0; i < 5; i++)
        GenerateTestCaseForInstruction("thumb32_MVN_reg");
    fmt::print("// ORN (reg)");
    for (int i = 0; i < 5; i++)
        GenerateTestCaseForInstruction("thumb32_ORN_reg");
    fmt::print("// TEQ (reg)");
    for (int i = 0; i < 5; i++)
        GenerateTestCaseForInstruction("thumb32_TEQ_reg");
    fmt::print("// EOR (reg)");
    for (int i = 0; i < 5; i++)
        GenerateTestCaseForInstruction("thumb32_EOR_reg");
    fmt::print("// CMN (reg)");
    for (int i = 0; i < 5; i++)
        GenerateTestCaseForInstruction("thumb32_CMN_reg");
    fmt::print("// ADD (reg)");
    for (int i = 0; i < 5; i++)
        GenerateTestCaseForInstruction("thumb32_ADD_reg");
    fmt::print("// ADC (reg)");
    for (int i = 0; i < 5; i++)
        GenerateTestCaseForInstruction("thumb32_ADC_reg");
    fmt::print("// SBC (reg)");
    for (int i = 0; i < 5; i++)
        GenerateTestCaseForInstruction("thumb32_SBC_reg");
    fmt::print("// CMP (reg)");
    for (int i = 0; i < 5; i++)
        GenerateTestCaseForInstruction("thumb32_CMP_reg");
    fmt::print("// SUB (reg)");
    for (int i = 0; i < 5; i++)
        GenerateTestCaseForInstruction("thumb32_SUB_reg");
    fmt::print("// RSB (reg)");
    for (int i = 0; i < 5; i++)
        GenerateTestCaseForInstruction("thumb32_RSB_reg");
    return 0;
}
