/**
 * @file TestCommand.h
 * @brief Declares test command.
 */

#ifndef WEAVE2_TESTCOMMAND_H
#define WEAVE2_TESTCOMMAND_H

#include "ICommand.h"
#include "cli/data/ParsedCommand.h"
#include "commands/data/CommandContext.h"

namespace weave::commands
{
    /**
     * @brief Test command used for parser and dispatch validation.
     */
    class TestCommand : public weave::commands::data::ICommand
    {
    public:
        /**
         * @brief Returns the name identifying this command.
         * @return The commands unique name.
         *
         * @see ICommand::name()
         */
        std::string name() const override;

    protected:
        /**
         * @brief Validates command-specific arguments and flags.
         * @note Test command has no validation.
         * @return True, this command should always be valid.
         */
        bool validate() const override;

        /**
         * @brief Executes command-specific implementation.
         * @note Test command has no implementation.
         * @return 0, this command should always execute.
         */
        int execute() override;
    };
}

#endif //WEAVE2_TESTCOMMAND_H
