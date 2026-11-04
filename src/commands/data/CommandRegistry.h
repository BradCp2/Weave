/**
 * @file CommandRegistry.h
 * @brief Declares the command registry.
 */

#ifndef WEAVE2_COMMANDREGISTRY_H
#define WEAVE2_COMMANDREGISTRY_H

#include <memory>
#include "commands/ICommand.h"

namespace weave::commands::data
{
    /**
     * @brief Maps command names to their corresponding implementation.
     *
     * The registry owns the registered command objects and provides lookup access by command name.
     * Allows dispatcher to locate commands without individual command class dependencies.
     *
     * @see ICommand
     * @see weave::cli::CommandDispatcher
     * @see weave::WeaveApp::registerCommands()
     */
    class CommandRegistry
    {
    public:
        /**
         * @brief Registers a command to the registry.
         *
         * Takes ownership of the supplied command and associates it with the name
         * returned by @ref weave::commands::ICommand::name()
         *
         * @param command The command implementation to register.
         *
         * @note Implementation should reject null commands, commands with missing names,
         * and commands with duplicate names.
         */
        void registerCommand(std::unique_ptr<ICommand> command);

        /**
         * @brief Finds registered command by name.
         *
         * Searches the registry for a command matching the supplied name.
         * Returns a pointer to the command without transferring ownership.
         *
         * @param name Name of the command to find.
         * @return Pointer to command if found; otherwise, nullptr.
         */
        ICommand* findCommand(const std::string& name) const;

    private:
        /**
         * @brief Stores registered commands indexed by command name.
         *
         * The registry owns each command through a unique pointer, all which
         * inherit from @ref weave::commands:ICommand
         */
        std::unordered_map<std::string, std::unique_ptr<ICommand>> commandSet;
    };
} // commands

#endif //WEAVE2_COMMANDREGISTRY_H
