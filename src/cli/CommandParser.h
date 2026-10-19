//
// Created by mrble on 09/10/2026.
//

#ifndef WEAVE2_COMMANDPARSER_H
#define WEAVE2_COMMANDPARSER_H

#include "cli/data/ParsedCommand.h"
#include "cli/data/FlagRegister.h"

namespace weave::cli {
    class CommandParser {
        public:
        CommandParser();
        void parse(const std::vector<std::string> &tokens);

        data::parsedCommand &getParsedCommand();

        private:
        data::parsedCommand _parsedCommand;
        std::unordered_map<std::string, data::FlagArgumentType> _flagRegister = data::getFlagTypes();
    };
} // cli

#endif //WEAVE2_COMMANDPARSER_H
