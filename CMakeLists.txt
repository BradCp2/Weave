cmake_minimum_required(VERSION 4.3)
project(Weave2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(Weave2
        main.cpp
        src/WeaveApp.cpp

        src/cli/CommandParser.cpp
        src/cli/CommandDispatcher.cpp
        src/cli/CLIRenderer.cpp

        src/commands/data/CommandRegistry.cpp
        src/commands/TestCommand.cpp

        src/core/Repository.cpp
        src/events/EventQueue.cpp
        src/workers/WorkerManager.cpp
)

set_target_properties(Weave2 PROPERTIES
        WIN32_EXECUTABLE FALSE
)

target_include_directories(Weave2 PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)
