// Copyright (c) 2019-2024 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#include <functional>

namespace metier::common
{
class ScopeGuard
{
public:
    using Callback = std::function<void()>;

    ScopeGuard(Callback cb) noexcept
        : cb_(cb)
    {
    }
    ~ScopeGuard()
    {
        try {
            if (cb_) { cb_(); }
        } catch (...) {
        }
    }

private:
    const Callback cb_;
};
}  // namespace metier::common