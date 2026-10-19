//
// Created by mrble on 19/10/2026.
//

#ifndef WEAVE2_TESTCOMMAND_H
#define WEAVE2_TESTCOMMAND_H

#include "ICommand.h"
#include "cli/data/ParsedCommand.h"
#include "commands/data/CommandContext.h"


class TestCommand : public weave::commands::data::ICommand
{
public:
    std::string name() const override;

    int execute(
        const weave::cli::data::parsedCommand &parsedCommand,
        CommandContext &context
    ) override;
};


#endif //WEAVE2_TESTCOMMAND_H
