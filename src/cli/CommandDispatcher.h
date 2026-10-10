//
// Created by mrble on 09/10/2026.
//

#ifndef WEAVE2_COMMANDDISPATCHER_H
#define WEAVE2_COMMANDDISPATCHER_H

#include "workers/WorkerManager.h"

namespace weave::cli {
    class CommandDispatcher {
        public:
        CommandDispatcher(workers::WorkerManager& workerManager) : workerManager(workerManager)
        {
            /*
             * TODO Implement dispatcher logic.
             */
        }

    private:
        workers::WorkerManager& workerManager;
    };
} // cli

#endif //WEAVE2_COMMANDDISPATCHER_H
