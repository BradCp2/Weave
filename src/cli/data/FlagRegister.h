//
// Created by mrble on 13/10/2026.
//

#ifndef WEAVE2_FLAGTYPE_H
#define WEAVE2_FLAGTYPE_H

#include <string>
#include <unordered_map>

namespace weave::cli::data {
    enum class FlagArgumentType {
        None,       // Flag does not have and parameters.
        Required,   // Flag requires next argument in command as value.
        Message,    // Flag will combine tokens surrounded by "" as argument.
    };

    inline const std::unordered_map<std::string, FlagArgumentType>& getFlagTypes() {
        static std::unordered_map<std::string, FlagArgumentType> flagTypeMap;
        flagTypeMap["-v"] = FlagArgumentType::None;
        flagTypeMap["--verbose"] = FlagArgumentType::None;
        flagTypeMap["-test"] = FlagArgumentType::Required;
        return flagTypeMap;
    }
}

#endif //WEAVE2_FLAGTYPE_H
