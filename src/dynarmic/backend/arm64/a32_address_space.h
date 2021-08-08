/* This file is part of the dynarmic project.
 * Copyright (c) 2021 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#pragma once

#include <aarch64/macro-assembler-aarch64.h>
#include <boost/icl/interval_set.hpp>
#include <tsl/robin_map.h>

#include "dynarmic/backend/arm64/code_buffer.h"
#include "dynarmic/common/common_types.h"
#include "dynarmic/interface/A32/config.h"
#include "dynarmic/ir/location_descriptor.h"

namespace Dynarmic::Backend::Arm64 {

constexpr size_t CODE_BUFFER_SIZE = 128 * 1024 * 1024;  // bytes

class A32AddressSpace final {
public:
    struct BlockDescriptor {
        void* entry_point;
        size_t size;
    };

    A32AddressSpace(const A32::UserConfig& config);
    ~A32AddressSpace();

    BlockDescriptor GetBlock(IR::LocationDescriptor descriptor);

    void ClearCache();

    void InvalidateCacheRanges(const boost::icl::interval_set<u32>& ranges);

private:
    const A32::UserConfig config;

    void EmitPrelude();
    BlockDescriptor EmitBlock(IR::LocationDescriptor ir_descriptor);

    CodeBuffer buffer{CODE_BUFFER_SIZE};
    vixl::aarch64::MacroAssembler code{buffer.GetPointer(), buffer.GetSize()};

    tsl::robin_map<IR::LocationDescriptor, BlockDescriptor> block_descriptors;
};

}  // namespace Dynarmic::Backend::Arm64
