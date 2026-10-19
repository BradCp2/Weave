//
// Created by mrble on 19/10/2026.
//

#include "TestCommand.h"

#include <iostream>

std::string TestCommand::name() const {
    return "test";
}

int TestCommand::execute(
    const weave::cli::data::parsedCommand &parsedCommand,
    CommandContext &context
) {
    std::cout << "Executing test command: " << parsedCommand.command << std::endl;
    return 0;
}
