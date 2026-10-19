//
// Created by mrble on 19/10/2026.
//

#ifndef WEAVE2_ICOMMAND_H
#define WEAVE2_ICOMMAND_H

#include "cli/data/ParsedCommand.h"
#include "commands/data/CommandContext.h"

namespace weave::commands::data {
class ICommand {
    public:
    virtual ~ICommand() = default;
    virtual std::string name() const = 0;
    virtual int execute(
        const cli::data::parsedCommand& parsedCommand,
        CommandContext& context
    ) = 0;
};
}

#endif //WEAVE2_ICOMMAND_H
