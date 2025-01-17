// Copyright (c) 2019-2024 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "metier/common/app.hpp"

int main(int argc, char* argv[])
{
    const auto output = metier::common::App::Get(argc, argv)->run();
    metier::common::App::Cleanup();

    return output;
}
