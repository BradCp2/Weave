/**
 * @file ParsedCommand.h
 * @brief Declares ParsedCommand data structure.
 */

#ifndef WEAVE2_PARSEDCOMMAND_H
#define WEAVE2_PARSEDCOMMAND_H


#include <filesystem>
#include <unordered_map>
#include <vector>

namespace weave::cli::data
{
    /**
     * @brief Stores parsed data for a Weave2 command.
     *
     * Holds information extracted from command line input,
     * including: command name, arguments, flags, and directory metadata
     *
     * This structure provides a application wide common data representation that can be passed
     * between the parser, dispatcher and individual command implementations.
     *
     * @see weave::cli::CommandParser::parse()
     * @see weave::commands::ICommand::tryExecute()
     */
    struct parsedCommand
    {
        /**
         * @brief Directory from which the command was invoked.
         *
         * Represents the working project directory of the users command invokation.
         */
        std::filesystem::path invocationPath;

        /**
         * @brief Location of the running Weave2 executable.
         *
         * Used to identify the programs installation location.
         */
        std::filesystem::path programPath;

        /**
         * @brief Name of the called command.
         *
         * Identifies the name of the command to be located in @ref weave::commands::data::CommandRegistry::commandSet
         *
         * @see weave::commands::ICommand::name()
         */
        std::string command;

        /**
         * @brief Positional arguments to be supplied to the command.
         *
         * Stores arguments in original order, excludes command name and separately parsed flags.
         */
        std::vector<std::string> arguments;

        /**
         * @brief Flags supplied to the command and their associated values.
         *
         * Maps valid flags identifiers to their corresponding values.
         * Flags without an associated value will store an empty string.
         *
         * @see weave::cli::data::FlagRegister
         */
        std::unordered_map<std::string, std::string> flags;

        /**
         * @brief Indicates whether the command is valid
         *
         * Used to record if command parsing ran into any errors.
         * These include: missing command, unknown flag, flag missing associated value.
         */
        bool validFlag = false;
    };
}


#endif //WEAVE2_PARSEDCOMMAND_H
