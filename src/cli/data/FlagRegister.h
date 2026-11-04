/**
 * @file FlagRegister.h
 * @brief Declares flag argument types and their associated definitions.
 */

#ifndef WEAVE2_FLAGTYPE_H
#define WEAVE2_FLAGTYPE_H

#include <string>
#include <unordered_map>

namespace weave::cli::data
{
    /**
     * @brief Defines the argument requirements of a command-line flag.
     *
     * Determines how the command parser handles tokens following a known flag.
     */
    enum class FlagArgumentType
    {
        None,       ///< Flag does not require an argument.
        Required,   ///< Flag requires the next token as its value.
        Message     ///< Flag accepts a message composed of quoted tokens (DEPRECATED).
    };

    /**
     * @brief Returns the registered flag argument types.
     *
     * Provides a mapping between recognised flag identifiers and
     * their expected argument types.
     *
     * The mapping is initialised once and shared across subsequent token calls.
     *
     * @return A constant reference to the flag type mapping.
     *
     * @see FlagArgumentType
     * @see weave::cli::CommandParser
     */
    inline const std::unordered_map<std::string, FlagArgumentType>& getFlagTypes()
    {
        static const std::unordered_map<std::string, FlagArgumentType> flagTypeMap
        {
            {"-v", FlagArgumentType::None},
            {"--verbose", FlagArgumentType::None},
            {"--test", FlagArgumentType::Required}
        };

        return flagTypeMap;
    }
}

#endif // WEAVE2_FLAGTYPE_H