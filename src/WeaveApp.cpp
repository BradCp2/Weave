//
// Created by mrble on 09/10/2026.
//

#include "WeaveApp.h"

#include "commands/TestCommand.h"

#include <iostream>
#include <ostream>
#include <memory>

#include "cli/CommandDispatcher.h"

weave::WeaveApp::WeaveApp() :
    workerManager_(eventQueue_),
    renderer_(eventQueue_)
{
    registerCommands();
    dispatcher_ = std::make_unique<cli::CommandDispatcher>(commandRegistry_);
    context_ = std::make_unique<commands::data::CommandContext>
    (
        commands::data::CommandContext
        {
            .repository = repository_,
            .workerManager = workerManager_,
            .renderer = renderer_
        }
    );
}

weave::WeaveApp::~WeaveApp() = default;

void weave::WeaveApp::registerCommands()
{
    commandRegistry_.registerCommand(std::make_unique<commands::TestCommand>());
}

int weave::WeaveApp::run(const std::vector<std::string>& tokens)
{
    parser_.parse(tokens);
    temporary(); // DELETE AFTER DEBUGGING

    if (!parser_.getParsedCommand().validFlag) { std::cout << "Terminating..." << std::endl; return 1;}

    return dispatcher_->dispatch(parser_.getParsedCommand(), *context_);
}

void weave::WeaveApp::temporary()
{
    std::cout << "inv : " << parser_.getParsedCommand().invocationPath << std::endl;
    std::cout << "pgm : " << parser_.getParsedCommand().programPath << std::endl;
    std::cout << "cmd : " <<parser_.getParsedCommand().command << std::endl;
    for (std::string p : parser_.getParsedCommand().arguments) {
        std::cout << "arg : " << p << std::endl;
    }
    for (auto f : parser_.getParsedCommand().flags) {
        std::cout << "flg : " << f.first << " | arg? : " << f.second << std::endl;
    }
}
