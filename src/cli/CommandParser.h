/**
 * @file CommandParser.h
 * @brief Declares the command-line argument parser.
 */

#ifndef WEAVE2_COMMANDPARSER_H
#define WEAVE2_COMMANDPARSER_H

#include "cli/data/ParsedCommand.h"
#include "cli/data/FlagRegister.h"

namespace weave::cli
{
    /**
     * @brief Parses the command-line tokens into a structured command data class.
     *
     * Identifies the command, arguments, flags and their possible args from pre-processed
     * CLI tokens from @ref weave::WeaveApp and configures directory metadata required for subsequent command processing.
     */
    class CommandParser
    {
        public:
        /**
         * @brief Constructs a CommandParser.
         */
        CommandParser();

        /**
         * @brief Parses an ordered sequence of CLI tokens.
         * @param tokens Ordered command-line tokens to be parsed.
         */
        void parse(const std::vector<std::string> &tokens);

        /**
         * @brief Returns the parsed command.
         * @return Const reference to the internally stored ParsedCommand.
         *
         * Prevents modification of command data created from parsing.
         */
        const data::parsedCommand& getParsedCommand() const;

        private:
        data::parsedCommand _parsedCommand;
        std::unordered_map<std::string, data::FlagArgumentType> _flagRegister = data::getFlagTypes();
    };
} // cli

#endif //WEAVE2_COMMANDPARSER_H
