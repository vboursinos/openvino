// Copyright (C) 2018-2025 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//
#pragma once

#include <itt.hpp>
#include <mutex>
#include <unordered_map>

#include "openvino/core/node.hpp"

namespace ov {
namespace pass {
class PerfCounters {
public:
    PerfCounters() = default;
    PerfCounters(const PerfCounters&) = delete;
    PerfCounters& operator=(const PerfCounters&) = delete;

    itt::handle_t operator[](const Node::type_info_t& type_inf);

private:
    using counters_map = std::unordered_map<const Node::type_info_t*, itt::handle_t>;

    std::mutex m_mutex;
    counters_map m_counters;
};
}  // namespace pass
}  // namespace ov