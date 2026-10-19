//
// Created by mrble on 19/10/2026.
//

#ifndef WEAVE2_COMMANDCONTEXT_H
#define WEAVE2_COMMANDCONTEXT_H
#include "cli/ClIRenderer.h"
#include "core/Repository.h"
#include "workers/WorkerManager.h"

struct CommandContext {
    weave::core::Repository& repository;
    weave::workers::WorkerManager& workerManager;
    weave::cli::CLIRenderer& renderer;
};

#endif //WEAVE2_COMMANDCONTEXT_H
