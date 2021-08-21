/* This file is part of the dynarmic project.
 * Copyright (c) 2021 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#include "dynarmic/backend/arm64/reg_alloc.h"

#include <algorithm>
#include <iterator>
#include <tuple>

#include "dynarmic/ir/basic_block.h"
#include "dynarmic/ir/microinstruction.h"

namespace Dynarmic::Backend::Arm64 {

InstLifetimeAnalysis::InstLifetimeAnalysis(IR::Block& block) {
    for (IR::Inst& inst : block) {
        const size_t inst_index = index_to_inst.size();
        index_to_inst.push_back(&inst);

        inst_to_info.emplace(&inst, InstLifetimeInfo{inst_index, {}});

        for (size_t arg_index = 0; arg_index < inst.NumArgs(); arg_index++) {
            const IR::Value arg = inst.GetArg(arg_index);
            if (!arg.IsImmediate()) {
                inst_to_info.at(arg.GetInst()).use_indexes.push_back(inst_index);
            }
        }
    }
}

bool HostLocInfo::Has(IR::Inst* inst) const {
    return std::find(values.begin(), values.end(), inst) != values.end();
}

void RegAlloc::Realize() {
    // Do Read constraints first
    for (auto& constraint : constraints) {
        if (constraint.rws != RAConstraint::RWS::Read)
            continue;

        const auto location = *GetValueLocation(constraint.inst);

        if (constraint.type == std::get<RARegType>(location)) {
            constraint.assigned_register = std::get<size_t>(location);
        } else {
            const auto new_location = GetEmptyRegister(constraint.type, constraint.rws);
            EmitMove(new_location, location);
            constraint.assigned_register = std::get<size_t>(new_location);
        }
    }

    // Do Write and Scratch constraints next
    for (auto& constraint : constraints) {
        if (constraint.rws == RAConstraint::RWS::Read)
            continue;

        const auto new_location = GetEmptyRegister(constraint.type, constraint.rws);
        constraint.assigned_register = std::get<size_t>(new_location);
        if (constraint.rws == RAConstraint::RWS::Write) {
            AddValueToInfo(constraint.inst, new_location);
        }
    }

    // Cleanup
    const size_t current_inst_index = lifetime.GetInfo(current_inst).inst_index;
    const auto update_info = [&](HostLocInfo& info) {
        info.locked = false;

        if (info.values.empty())
            return;

        const auto first_use_after_current_inst = std::upper_bound(info.use_indexes.begin(), info.use_indexes.end(), current_inst_index);
        info.use_indexes.erase(info.use_indexes.begin(), first_use_after_current_inst);

        if (info.use_indexes.empty())
            info = {};
    };
    for (HostLocInfo& info : regs_info)
        update_info(info);
    for (HostLocInfo& info : vecs_info)
        update_info(info);
}

void RegAlloc::ReadLockValueLocation(IR::Inst* inst) {
    const auto has_inst = [inst](const HostLocInfo& info) { return info.Has(inst); };

    if (const auto regs_iter = std::find_if(regs_info.begin(), regs_info.end(), has_inst); regs_iter != regs_info.end()) {
        regs_iter->locked = true;
        return;
    }

    if (const auto vecs_iter = std::find_if(vecs_info.begin(), vecs_info.end(), has_inst); vecs_iter != vecs_info.end()) {
        vecs_iter->locked = true;
        return;
    }

    ASSERT_FALSE("Unable to find inst to read-lock 0x{:016x}", reinterpret_cast<uptr>(inst));
}

std::optional<std::tuple<RARegType, size_t>> RegAlloc::GetValueLocation(IR::Inst* inst) const {
    const auto has_inst = [inst](const HostLocInfo& info) { return info.Has(inst); };

    if (const auto regs_iter = std::find_if(regs_info.begin(), regs_info.end(), has_inst); regs_iter != regs_info.end()) {
        return std::make_tuple(RARegType::Reg, static_cast<size_t>(std::distance(regs_info.begin(), regs_iter)));
    }

    if (const auto vecs_iter = std::find_if(vecs_info.begin(), vecs_info.end(), has_inst); vecs_iter != vecs_info.end()) {
        return std::make_tuple(RARegType::Vec, static_cast<size_t>(std::distance(vecs_info.begin(), vecs_iter)));
    }

    return std::nullopt;
}

HostLocInfo& RegAlloc::GetInfo(std::tuple<RARegType, size_t> location) {
    const auto [type, index] = location;
    switch (type) {
    case RARegType::Reg:
        return regs_info.at(index);
    case RARegType::Vec:
        return vecs_info.at(index);
    }
    ASSERT_FALSE("Invalid RARegType");
}

std::tuple<RARegType, size_t> GetEmptyRegister(RARegType type, RAConstraint::RWS rws) {
    ASSERT_FALSE("Unimplemented {} {}", type, rws);
}

void RegAlloc::AddValueToInfo(IR::Inst* inst, std::tuple<RARegType, size_t> location) {
    auto& info = GetInfo(location);
    info.values.push_back(inst);

    std::vector<size_t> tmp;
    const auto& new_uses = lifetime.GetInfo(inst).use_indexes;
    const auto& old_uses = info.use_indexes;
    std::set_union(old_uses.begin(), old_uses.end(), new_uses.begin(), new_uses.end(), tmp.begin());
    info.use_indexes = tmp;
}

// x16, x17 are reserved by the macroassembler
// x18 is reserved by the platform
// x27 is the cycles_remaining register
// x28 is the JitState register
// x29, x30 and x31 are FP, LR, and SP respectively
const std::array<vixl::aarch64::Register, RegAlloc::allocatable_regs_count> RegAlloc::allocatable_regs{
    vixl::aarch64::x0,
    vixl::aarch64::x1,
    vixl::aarch64::x2,
    vixl::aarch64::x3,
    vixl::aarch64::x4,
    vixl::aarch64::x5,
    vixl::aarch64::x6,
    vixl::aarch64::x7,
    vixl::aarch64::x8,
    vixl::aarch64::x9,
    vixl::aarch64::x10,
    vixl::aarch64::x11,
    vixl::aarch64::x12,
    vixl::aarch64::x13,
    vixl::aarch64::x14,
    vixl::aarch64::x15,
    vixl::aarch64::x19,
    vixl::aarch64::x20,
    vixl::aarch64::x21,
    vixl::aarch64::x22,
    vixl::aarch64::x23,
    vixl::aarch64::x24,
    vixl::aarch64::x25,
    vixl::aarch64::x26,
};

// v31 reserved by the macroassembler
const std::array<vixl::aarch64::VRegister, RegAlloc::allocatable_vecs_count> RegAlloc::allocatable_vecs{
    vixl::aarch64::v0,
    vixl::aarch64::v1,
    vixl::aarch64::v2,
    vixl::aarch64::v3,
    vixl::aarch64::v4,
    vixl::aarch64::v5,
    vixl::aarch64::v6,
    vixl::aarch64::v7,
    vixl::aarch64::v8,
    vixl::aarch64::v9,
    vixl::aarch64::v10,
    vixl::aarch64::v11,
    vixl::aarch64::v12,
    vixl::aarch64::v13,
    vixl::aarch64::v14,
    vixl::aarch64::v15,
    vixl::aarch64::v16,
    vixl::aarch64::v17,
    vixl::aarch64::v18,
    vixl::aarch64::v19,
    vixl::aarch64::v20,
    vixl::aarch64::v21,
    vixl::aarch64::v22,
    vixl::aarch64::v23,
    vixl::aarch64::v24,
    vixl::aarch64::v25,
    vixl::aarch64::v26,
    vixl::aarch64::v27,
    vixl::aarch64::v28,
    vixl::aarch64::v29,
    vixl::aarch64::v30,
};

}  // namespace Dynarmic::Backend::Arm64
