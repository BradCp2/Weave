cmake_minimum_required(VERSION 4.3)
project(Weave2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Weave2
        main.cpp
        src/WeaveApp.cpp
        src/cli/CommandParser.cpp
        src/cli/CommandDispatcher.cpp
        src/cli/CLIRenderer.cpp
        src/events/EventQueue.cpp
        src/workers/WorkerManager.cpp
)

target_include_directories(Weave2 PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)
