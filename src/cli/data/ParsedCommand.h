//
// Created by mrble on 13/10/2026.
//

#ifndef WEAVE2_PARSEDCOMMAND_H
#define WEAVE2_PARSEDCOMMAND_H


#include <filesystem>
#include <unordered_map>
#include <vector>

namespace weave::cli::data {
    struct parsedCommand {
        std::filesystem::path invocationPath;
        std::filesystem::path programPath;
        std::string command;
        std::vector<std::string> arguments;
        std::unordered_map<std::string, std::string> flags;
        bool validFlag = false;
    };
}


#endif //WEAVE2_PARSEDCOMMAND_H
