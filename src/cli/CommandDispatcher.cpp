//
// Created by mrble on 09/10/2026.
//

#include "CommandDispatcher.h"

#include <iostream>

#include "commands/data/CommandRegistry.h"
#include "CommandParser.h"
#include "commands/ICommand.h"

namespace weave::cli {
    CommandDispatcher::CommandDispatcher(
        const commands::data::CommandRegistry &commandRegistry) : commandRegistry(commandRegistry) {
    }

    int CommandDispatcher::dispatch(
        const data::parsedCommand &parsedCommand,
        CommandContext &commandContext
    ) const {
        commands::data::ICommand *handler = commandRegistry.findCommand(parsedCommand.command);

        if (handler == nullptr) {
            // TODO deploy error message (unknown command)
            std::cout << "Command not found: " << parsedCommand.command << std::endl;
            return 1;
        }

        return handler->execute(parsedCommand, commandContext);
    }
} // cli
