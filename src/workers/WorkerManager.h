//
// Created by mrble on 09/10/2026.
//

#ifndef WEAVE2_WORKERMANAGER_H
#define WEAVE2_WORKERMANAGER_H

#include "events/EventQueue.h"

namespace weave::workers {
    class WorkerManager {
        public:
        WorkerManager(events::EventQueue& eventQueue);

        private:
        events::EventQueue& eventQueue;
    };
} // workers

#endif //WEAVE2_WORKERMANAGER_H
