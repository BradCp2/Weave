/**
 * @file CommandDispatcher.h
 * @brief Declares the command dispatcher.
 */

#ifndef WEAVE2_COMMANDDISPATCHER_H
#define WEAVE2_COMMANDDISPATCHER_H

#include "data/ParsedCommand.h"
#include "commands/data/CommandRegistry.h"
#include "commands/ICommand.h"
#include "commands/data/CommandContext.h"

namespace weave::cli
{
    /**
     * @brief Dispatches parsed commands to their registered handlers.
     *
     * Uses @ref weave::commands::data::CommandRegistry to locate the
     * corresponding command handler implementation and executes it using
     * the supplied @ref weave::commands::data::CommandContext
     *
     * Works with commands parsed by @ref CommandParser
     */
    class CommandDispatcher
    {
    public:
        /**
         * @brief Constructs a CommandDispatcher.
         * @param commandRegistry Registry containing the available command handler implementations.
         *
         * Command handlers are registered to prior to construction in @ref weave::WeaveApp::registerCommands()
         */
        explicit CommandDispatcher(const commands::data::CommandRegistry &commandRegistry);

        /**
         * @brief Dispatches a parsed command for execution.
         *
         * Locates the appropriate command handler and executes it using supplied command data and context.
         *
         * @param parsedCommand Parsed command containing command name, args, flags, and metadata.
         * @param commandContext Context providing command resources and dependencies for command execution.
         *
         * @return 0 on success; non-zero if dispatch or execution fails.
         */
        int dispatch(
            const data::parsedCommand &parsedCommand,
            commands::data::CommandContext &commandContext) const;

    private:
        const commands::data::CommandRegistry &commandRegistry;
    };
} // cli

#endif //WEAVE2_COMMANDDISPATCHER_H
