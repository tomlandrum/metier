// Copyright (c) 2019-2024 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <iostream>
#include <string>

#include "metier/common/cli/parser.hpp"
#include "metier/common/cli/processor.hpp"

auto main(int argc, char* argv[]) -> int
{
    const auto parser = metier::common::cli::Parser{};
    const auto options = parser.parse(argc, argv);

    if (options.show_help_) {
        std::cout << parser.help() << '\n';

        return 0;
    }

    auto processor = metier::common::cli::Processor{};
    std::cout << processor.process(options) << '\n';

    return processor.value();
}
