//
// Created by mrble on 09/10/2026.
//

#include "WeaveApp.h"

#include <iostream>
#include <ostream>

weave::WeaveApp::WeaveApp() :
    eventQueue_(),
    renderer_(eventQueue_),
    workerManager_(eventQueue_),
    parser_(),
    dispatcher_(workerManager_)
{
    /*
     * TODO add constructor initialiser list to call implemented work classes.
     */
    WeaveApp::registerCommands();
    std::cout << "Initializing WeaveApp ..." << std::endl;
}

weave::WeaveApp::~WeaveApp() = default;

void weave::WeaveApp::registerCommands()
{
    /*
     * TODO register implemented commands to `dispatcher_`
     */
    std::cout << "WeaveApp::registerCommands" << std::endl;
}
