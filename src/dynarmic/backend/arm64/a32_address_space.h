/* This file is part of the dynarmic project.
 * Copyright (c) 2021 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#pragma once

#include <aarch64/macro-assembler-aarch64.h>
#include <boost/icl/interval_set.hpp>
#include <tsl/robin_map.h>

#include "dynarmic/backend/arm64/code_buffer.h"
#include "dynarmic/backend/arm64/prelude_info.h"
#include "dynarmic/common/common_types.h"
#include "dynarmic/interface/A32/config.h"
#include "dynarmic/ir/location_descriptor.h"

namespace Dynarmic::Backend::Arm64 {

constexpr size_t CODE_BUFFER_SIZE = 128 * 1024 * 1024;          // bytes
constexpr size_t MINIMUM_REMAINING_CODESIZE = 1 * 1024 * 1024;  // bytes

class A32AddressSpace final {
public:
    struct BlockDescriptor {
        void* entry_point;
        size_t size;
    };

    A32AddressSpace(const A32::UserConfig& conf);
    ~A32AddressSpace();

    BlockDescriptor GetBlock(IR::LocationDescriptor descriptor);

    u64 GetCacheGeneration() const { return cache_generation; }
    const PreludeInfo& GetPreludeInfo() const { return prelude; }

    void ClearCache();

    void InvalidateCacheRanges(const boost::icl::interval_set<u32>& ranges);

private:
    const A32::UserConfig conf;

    void EmitPrelude();
    BlockDescriptor EmitBlock(IR::LocationDescriptor ir_descriptor);

    /// Generation number for current cache state.
    /// This is used when external state relies on coherency with the code cache.
    u64 cache_generation = 0;

    CodeBuffer buffer{CODE_BUFFER_SIZE};
    vixl::aarch64::MacroAssembler code{buffer.GetPointer(), buffer.GetSize()};
    PreludeInfo prelude;

    tsl::robin_map<IR::LocationDescriptor, BlockDescriptor> block_descriptors;
};

}  // namespace Dynarmic::Backend::Arm64
