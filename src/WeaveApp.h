//
// Created by mrble on 09/10/2026.
//

#ifndef WEAVE2_WEAVEAPP_H
#define WEAVE2_WEAVEAPP_H


/*
 * TODO Add class functionality to the following classes...
 */

#include "core/Repository.h"
#include "workers/WorkerManager.h"
#include "events/EventQueue.h"

#include "cli/CommandParser.h"
#include "cli/CommandDispatcher.h"
#include "cli/ClIRenderer.h"

#include "commands/data/CommandRegistry.h"
#include "commands/data/CommandContext.h"

namespace weave {
    class WeaveApp
    {
    public:
        WeaveApp();
        ~WeaveApp();

        int run(const std::vector<std::string>& tokens);

        void temporary();

    private:
        void registerCommands();

        weave::core::Repository repository_;
        weave::workers::WorkerManager workerManager_;
        weave::events::EventQueue eventQueue_;

        weave::cli::CommandParser parser_;
        std::unique_ptr<cli::CommandDispatcher> dispatcher_;
        weave::cli::CLIRenderer renderer_;

        weave::commands::data::CommandRegistry commandRegistry_;
        std::unique_ptr<CommandContext> context_;
    };
}

#endif //WEAVE2_WEAVEAPP_H
