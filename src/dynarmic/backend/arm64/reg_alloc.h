/* This file is part of the dynarmic project.
 * Copyright (c) 2021 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#pragma once

#include <optional>
#include <ranges>
#include <tuple>
#include <vector>

#include <aarch64/registers-aarch64.h>
#include <tsl/robin_map.h>

#include "dynarmic/common/assert.h"
#include "dynarmic/common/forceinline.h"

namespace Dynarmic::IR {
class Block;
class Inst;
}  // namespace Dynarmic::IR

namespace Dynarmic::Backend::Arm64 {

class RAReg;
class RAVec;
class RegAlloc;

struct InstLifetimeInfo {
    size_t inst_index;
    std::vector<size_t> use_indexes;
};

class InstLifetimeAnalysis final {
public:
    InstLifetimeAnalysis(IR::Block& block);

    forceinline IR::Inst* GetInst(size_t inst_index) const {
        return index_to_inst.at(inst_index);
    }

    forceinline const InstLifetimeInfo& GetInfo(IR::Inst* inst) const {
        return inst_to_info.at(inst);
    }

    forceinline const InstLifetimeInfo& GetInfo(size_t inst_index) const {
        return GetInfo(GetInst(inst_index));
    }

private:
    std::vector<IR::Inst*> index_to_inst;
    tsl::robin_map<IR::Inst*, InstLifetimeInfo> inst_to_info;
};

class RAReg final {
public:
    const vixl::aarch64::Register& operator*() const;
    const vixl::aarch64::Register* operator->() const;

private:
    friend class RegAlloc;

    RAReg(RegAlloc& reg_alloc, size_t constraint_index)
            : reg_alloc(reg_alloc), constraint_index(constraint_index) {}

    RegAlloc& reg_alloc;
    size_t constraint_index;
};

class RAVec final {
public:
    const vixl::aarch64::VRegister& operator*() const;
    const vixl::aarch64::VRegister* operator->() const;

private:
    friend class RegAlloc;

    RAVec(RegAlloc& reg_alloc, size_t constraint_index)
            : reg_alloc(reg_alloc), constraint_index(constraint_index) {}

    RegAlloc& reg_alloc;
    size_t constraint_index;
};

enum class RARegType {
    Reg,
    Vec,
};

struct RAConstraint {
    enum class RWS {
        Read,
        Write,
        Scratch,
    };

    RAConstraint(RWS rws, RARegType type, IR::Inst* inst)
            : rws(rws), type(type), inst(inst) {}

    RWS rws;
    RARegType type;
    IR::Inst* inst;
    std::optional<size_t> assigned_register;
};

struct HostLocInfo {
    std::vector<IR::Inst*> values;
    std::vector<size_t> use_indexes;
    bool locked = false;

    bool IsEmpty() const { return values.empty(); }
    bool Has(IR::Inst* value) const;
    size_t GetNextUseInstIndex() const {
        ASSERT(!use_indexes.empty());
        return use_indexes.front();
    }
};

class RegAlloc {
public:
    RegAlloc(InstLifetimeAnalysis& lifetime)
            : lifetime(lifetime) {}

    forceinline void SetCurrentInstruction(IR::Inst* inst) {
        current_inst = inst;
    }

    forceinline RAReg ReadReg(IR::Inst* inst) {
        ReadLockValueLocation(inst);
        const size_t constraint_index = constraints.size();
        constraints.emplace_back(RAConstraint::RWS::Read, RARegType::Reg, inst);
        return {*this, constraint_index};
    }
    forceinline RAVec ReadVec(IR::Inst* inst) {
        ReadLockValueLocation(inst);
        const size_t constraint_index = constraints.size();
        constraints.emplace_back(RAConstraint::RWS::Read, RARegType::Vec, inst);
        return {*this, constraint_index};
    }
    forceinline RAReg WriteReg(IR::Inst* inst) {
        ASSERT(!GetValueLocation(inst).has_value());
        const size_t constraint_index = constraints.size();
        constraints.emplace_back(RAConstraint::RWS::Write, RARegType::Reg, inst);
        return {*this, constraint_index};
    }
    forceinline RAVec WriteVec(IR::Inst* inst) {
        ASSERT(!GetValueLocation(inst).has_value());
        const size_t constraint_index = constraints.size();
        constraints.emplace_back(RAConstraint::RWS::Write, RARegType::Vec, inst);
        return {*this, constraint_index};
    }
    forceinline RAReg ScratchReg() {
        const size_t constraint_index = constraints.size();
        constraints.emplace_back(RAConstraint::RWS::Scratch, RARegType::Reg, nullptr);
        return {*this, constraint_index};
    }
    forceinline RAVec ScratchVec() {
        const size_t constraint_index = constraints.size();
        constraints.emplace_back(RAConstraint::RWS::Scratch, RARegType::Vec, nullptr);
        return {*this, constraint_index};
    }

    void Realize();

private:
    friend class RAReg;
    friend class RAVec;
    constexpr static size_t allocatable_regs_count = 24;
    constexpr static size_t allocatable_vecs_count = 31;
    const static std::array<vixl::aarch64::Register, allocatable_regs_count> allocatable_regs;
    const static std::array<vixl::aarch64::VRegister, allocatable_vecs_count> allocatable_vecs;

    forceinline const vixl::aarch64::Register& GetRARegLocation(size_t constraint_index) const {
        return allocatable_regs[*constraints[constraint_index].assigned_register];
    }

    forceinline const vixl::aarch64::VRegister& GetRAVecLocation(size_t constraint_index) const {
        return allocatable_vecs[*constraints[constraint_index].assigned_register];
    }

    void ReadLockValueLocation(IR::Inst* inst);
    std::optional<std::tuple<RARegType, size_t>> GetValueLocation(IR::Inst* inst) const;
    HostLocInfo& GetInfo(std::tuple<RARegType, size_t> location);

    std::tuple<RARegType, size_t> GetEmptyRegister(RARegType type, RAConstraint::RWS rws);
    void AddValueToInfo(IR::Inst* inst, std::tuple<RARegType, size_t> location);

    void EmitMove(std::tuple<RARegType, size_t> new_location, std::tuple<RARegType, size_t> old_location);

    std::array<HostLocInfo, allocatable_regs_count> regs_info;
    std::array<HostLocInfo, allocatable_vecs_count> vecs_info;

    IR::Inst* current_inst = nullptr;
    InstLifetimeAnalysis& lifetime;

    std::vector<RAConstraint> constraints;
};

forceinline inline const vixl::aarch64::Register& RAReg::operator*() const {
    return reg_alloc.GetRARegLocation(constraint_index);
}

forceinline inline const vixl::aarch64::Register* RAReg::operator->() const {
    return &reg_alloc.GetRARegLocation(constraint_index);
}

forceinline inline const vixl::aarch64::VRegister& RAVec::operator*() const {
    return reg_alloc.GetRAVecLocation(constraint_index);
}

forceinline inline const vixl::aarch64::VRegister* RAVec::operator->() const {
    return &reg_alloc.GetRAVecLocation(constraint_index);
}

}  // namespace Dynarmic::Backend::Arm64
