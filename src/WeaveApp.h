//
// Created by mrble on 09/10/2026.
//

#ifndef WEAVE2_WEAVEAPP_H
#define WEAVE2_WEAVEAPP_H


/*
 * TODO Add class functionality to the following classes...
 */

#include "cli/CommandParser.h"
#include "cli/CommandDispatcher.h"
#include "workers/WorkerManager.h"
#include "events/EventQueue.h"
#include "cli/ClIRenderer.h"

namespace weave {
    class WeaveApp
    {
    public:
        WeaveApp();
        ~WeaveApp();

        int run(int argc, char *argv[]);

    private:
        void registerCommands();

        weave::cli::CommandParser parser_;
        weave::cli::CommandDispatcher dispatcher_;
        weave::cli::CLIRenderer renderer_;
        weave::workers::WorkerManager workerManager_;
        weave::events::EventQueue eventQueue_;
    };
}

#endif //WEAVE2_WEAVEAPP_H
