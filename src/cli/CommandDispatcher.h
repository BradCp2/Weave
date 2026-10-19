//
// Created by mrble on 09/10/2026.
//

#ifndef WEAVE2_COMMANDDISPATCHER_H
#define WEAVE2_COMMANDDISPATCHER_H

#include "data/ParsedCommand.h"
#include "commands/data/CommandRegistry.h"
#include "commands/ICommand.h"
#include "commands/data/CommandContext.h"

namespace weave::cli {
    class CommandDispatcher {
    public:
        explicit CommandDispatcher(const commands::data::CommandRegistry &commandRegistry);

        int dispatch(
            const data::parsedCommand &parsedCommand,
            CommandContext &commandContext
        ) const;

    private:
        const commands::data::CommandRegistry &commandRegistry;
    };
} // cli

#endif //WEAVE2_COMMANDDISPATCHER_H
