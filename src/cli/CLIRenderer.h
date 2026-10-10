//
// Created by mrble on 09/10/2026.
//

#ifndef WEAVE2_CLIRENDERER_H
#define WEAVE2_CLIRENDERER_H

#include "events/EventQueue.h"

namespace weave::cli {
    class CLIRenderer {
        public:
        CLIRenderer(events::EventQueue& eventQueue);

        private:
        events::EventQueue& eventQueue;
    };
}

#endif //WEAVE2_CLIRENDERER_H
