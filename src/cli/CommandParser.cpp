//
// Created by mrble on 09/10/2026.
//

#include "CommandParser.h"
#include "cli/data/ParsedCommand.h"
#include "cli/data/FlagRegister.h"

#include <filesystem>
#include <iostream>
#include <unordered_map>
#include <vector>

namespace weave::cli {
    CommandParser::CommandParser() = default;

    void CommandParser::parse(const std::vector<std::string> &tokens) {
        _parsedCommand.invocationPath = std::filesystem::current_path();
        _parsedCommand.programPath = std::filesystem::canonical(tokens[0]);

        if (tokens.size() == 1)
        {
            // TODO deploy error event (missing command)
            _parsedCommand.command = "N/A";
            return;
        }

        // First item is always the name of COMMAND.
        // TODO add flag validation similar to flags
        _parsedCommand.command = tokens.at(1);

        for (int i = 2; i < tokens.size(); i++)
        {
            if (const std::string& item = tokens.at(i); item.starts_with('-')) {
                // Flags
                if (!_flagRegister.contains(item)) {
                    // TODO deploy error event (invalid flag)
                    std::cout << "ERROR : Invalid flag name " << item << std::endl;
                    return;
                }
                // No-arg flags
                if (_flagRegister[item] == data::FlagArgumentType::None) {
                    _parsedCommand.flags[item] = "";
                }
                else if (_flagRegister[item] == data::FlagArgumentType::Required) {
                    try {
                        // 1-arg flag, arg exists
                        i++;
                        _parsedCommand.flags[item] = tokens.at(i);
                    } catch (const std::out_of_range& e) {
                        // 1-arg flag, missing arg
                        // TODO deploy error event (flag missing arg)
                        std::cout << "ERROR : flag \"" << item << "\" missing arguments" << std::endl;
                        return;
                    }
                }
            } else {
                // Arguments
                _parsedCommand.arguments.push_back(item);
            }
        }
        _parsedCommand.validFlag = true;
    }

    const data::parsedCommand& CommandParser::getParsedCommand() const
    {
        return _parsedCommand;
    }
} // cli