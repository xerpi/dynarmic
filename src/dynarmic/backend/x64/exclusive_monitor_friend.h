/* This file is part of the dynarmic project.
 * Copyright (c) 2022 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#include "dynarmic/interface/exclusive_monitor.h"

namespace Dynarmic {

inline Vector* GetExclusiveMonitorValuePointer(ExclusiveMonitor* monitor, size_t index) {
    return monitor->exclusive_values.data() + index;
}

}  // namespace Dynarmic
