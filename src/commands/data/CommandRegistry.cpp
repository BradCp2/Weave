//
// Created by mrble on 19/10/2026.
//

#include "CommandRegistry.h"

namespace weave::commands::data {
    void CommandRegistry::registerCommand(std::unique_ptr<ICommand> command) {
        if (!command) {
            // TODO throw debug error (cannot register null command)
            return;
        }

        const std::string commandName = command->name();

        if (commandName.empty()) {
            // TODO throw debug error (command name is empty)
            return;
        }

        const auto [it, inserted] = commandSet.emplace(
            commandName,
            std::move(command)
        );

        if (!inserted) {
            // TODO throw debug error (command already registered)
        }
    }

    ICommand *CommandRegistry::findCommand(const std::string &name) const {
        const auto it = commandSet.find(name);

        if (it == commandSet.end()) {
            return nullptr;
        }

        return it->second.get();
    }
} // commands