/* This file is part of the dynarmic project.
 * Copyright (c) 2021 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#include "dynarmic/backend/arm64/a32_address_space.h"

#include <boost/icl/interval_set.hpp>

#include "dynarmic/common/assert.h"
#include "dynarmic/common/common_types.h"
#include "dynarmic/interface/A32/config.h"
#include "dynarmic/ir/location_descriptor.h"

namespace Dynarmic::Backend::Arm64 {

A32AddressSpace::A32AddressSpace(const A32::UserConfig& config)
        : config(config) {}

A32AddressSpace::~A32AddressSpace() = default;

A32AddressSpace::BlockDescriptor A32AddressSpace::GetBlock(IR::LocationDescriptor) {
    ASSERT_FALSE("Unimplemented");
}

void A32AddressSpace::ClearCache() {
    ASSERT_FALSE("Unimplemented");
}

void A32AddressSpace::InvalidateCacheRanges(const boost::icl::interval_set<u32>& /*ranges*/) {
    ASSERT_FALSE("Unimplemented");
}

void A32AddressSpace::EmitPrelude() {
    ASSERT_FALSE("Unimplemented");
}

A32AddressSpace::BlockDescriptor A32AddressSpace::EmitBlock(IR::LocationDescriptor) {
    ASSERT_FALSE("Unimplemented");
}

}  // namespace Dynarmic::Backend::Arm64
