// Copyright (c) 2019-2024 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <utility>

namespace metier::common
{
auto qml_default_size() noexcept -> std::pair<int, int>;
auto qml_maximum_size() noexcept -> std::pair<int, int>;
auto qml_minimum_size() noexcept -> std::pair<int, int>;
}  // namespace metier::common
