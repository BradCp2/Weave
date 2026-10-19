//
// Created by mrble on 19/10/2026.
//

#ifndef WEAVE2_COMMANDREGISTRY_H
#define WEAVE2_COMMANDREGISTRY_H

#include <memory>
#include "commands/ICommand.h"

namespace weave::commands::data {
    class CommandRegistry {
    public:
        void registerCommand(std::unique_ptr<ICommand> command);

        ICommand* findCommand(const std::string& name) const;

    private:
        std::unordered_map<std::string, std::unique_ptr<ICommand>> commandSet;
    };
} // commands

#endif //WEAVE2_COMMANDREGISTRY_H
