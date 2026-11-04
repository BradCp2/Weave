/**
 * @file ICommand.h
 * @brief Declares command interface.
 */

#ifndef WEAVE2_ICOMMAND_H
#define WEAVE2_ICOMMAND_H

#include "cli/data/ParsedCommand.h"
#include "commands/data/CommandContext.h"

namespace weave::commands::data
{
    /**
     * @brief Abstract base class for Weave2 commands.
     *
     * Concrete command classes implement this interface to provide command-specific behaviour.
     * Commands are invoked through the command dispatcher rather than directly from the CLI.
     *
     * Each concrete command must provide a unique command name, args and flags, alongside implementing
     * its own validation and execution logic.
     *
     * @see CommandRegistry
     * @see weave::cli::CommandDispatcher
     */
    class ICommand
    {
    public:
        /**
         * @brief Virtual deconstructor for polymorphic deconstruction.
         *
         * Ensures that derived command objects are destroyed correctly when accessed via a pointer.
         */
        virtual ~ICommand() = default;

        /**
         * @brief Returns the name identifying this command.
         *
         * The command name is used by the @ref CommandRegistry and @ref CommandDispatcher to identify and link
         * the appropriate command implementation with its unique name. Implementing this in command reduces
         * non-command class dependencies.
         *
         * @see weave::WeaveApp::registerCommands()
         *
         * @return The commands unique name.
         */
        virtual std::string name() const = 0;

        /**
         * @brief Validates and executes a command.
         *
         * Validates the parsed command based on its argument count and flags before execution begins.
         *
         * @param parsedCommand The parsed command data containing command name, args, flags and metadata.
         * @param context The context provides access to common resources the command may require.
         *
         * @return 0 on success; non-zero if validation or execution fails.
         */
        int tryExecute(const cli::data::parsedCommand& parsedCommand, CommandContext& context)
        {
            if (!validate()) {
                return 1;
            }

            return execute();
        }

    protected:
        /**
         * @brief Validates command-specific arguments and flags.
         *
         * Implementations should check argument counts, supported flags for the specific command, and
         * possible flag conflicts.
         *
         * @return True if command is valid; otherwise, false.
         */
        virtual bool validate() const = 0;

        /**
         * @brief Executes command-specific implementation.
         *
         * @return 0 on successful execution; non-zero if execution fails.
         */
        virtual int execute() = 0;
    };
}

#endif //WEAVE2_ICOMMAND_H
