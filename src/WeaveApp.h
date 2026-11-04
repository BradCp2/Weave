/**
 * @file WeaveApp.h
 * @brief Declares the main Weave2 application.
 */

#ifndef WEAVE2_WEAVEAPP_H
#define WEAVE2_WEAVEAPP_H

#include "core/Repository.h"
#include "workers/WorkerManager.h"
#include "events/EventQueue.h"

#include "cli/CommandParser.h"
#include "cli/CommandDispatcher.h"
#include "cli/ClIRenderer.h"

#include "commands/data/CommandRegistry.h"
#include "commands/data/CommandContext.h"

namespace weave
{
    /**
     * @brief Coordinates the main Weave2 application components.
     *
     * Acts as a central application controller, managing command parsing, registration
     * dispatching, repository access and CLI output.
     *
     * Responsible for initialising application components, inter-component access, and
     * coordinates their interaction during execution.
     *
     * @see weave::cli::CommandParser
     * @see weave::cli::CommandDispatcher
     * @see weave::cli::CLIRenderer
     * @see weave::commands::data::CommandRegistry
     * @see weave::commands::data::CommandContext
     * @see weave::core::Repository
     * @see weave::workers::WorkerManager
     * @see weave::events::EventQueue
     */
    class WeaveApp
    {
    public:
        /**
         * @brief Constructs the Weave2 application.
         *
         * Initialises application components and prepares the command execution environment.
         */
        WeaveApp();

        /**
         * @brief Destroys Weave2 application.
         *
         * Releases application resources safely and destroys all owned components.
         */
        ~WeaveApp();

        /**
         * @brief Runs the application using supplied command line tokens.
         *
         * Coordinates command parsing, dispatch and execution.
         *
         * @param tokens The command line tokens supplied to the application.
         * @return An exit code indicating application execution results.
         */
        int run(const std::vector<std::string>& tokens);

        /**
         * @brief Performs temporary debug functionality.
         *
         * Displays components of parsed command for debugging purposes.
         *
         * @note DELETE once debug utility flag and module is implemented.
         */
        void temporary();

    private:
        /**
         * @brief Registers the available commands with the command registry.
         *
         * Creates and registers the command implementations supported by Weave2,
         * associating each implementation with its own unique name.
         *
         * Called during application initialization so dispatcher can locate commands
         * when processing user input.
         *
         * @see weave::commands::data::CommandRegistry
         * @see weave::commands:ICommand
         * @see weave::cli::CommandDispatcher
         */
        void registerCommands();

        weave::core::Repository repository_;
        weave::workers::WorkerManager workerManager_;
        weave::events::EventQueue eventQueue_;

        weave::cli::CommandParser parser_;
        std::unique_ptr<cli::CommandDispatcher> dispatcher_;
        weave::cli::CLIRenderer renderer_;

        weave::commands::data::CommandRegistry commandRegistry_;
        std::unique_ptr<commands::data::CommandContext> context_;
    };
}

#endif //WEAVE2_WEAVEAPP_H
