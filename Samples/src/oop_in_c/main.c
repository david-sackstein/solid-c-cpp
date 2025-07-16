#include "FileLogger.h"
#include "ConsoleLogger.h"

int main() {
    // FileLogger usage
    FileLogger *flogger = create_file_logger();
    ILogger *logger = &flogger->base;

    if (logger->open(logger, "log.txt") != 0) {
        return 1;
    }

    logger->log(logger, LOG_LEVEL_INFO, "Starting application (file)");
    logger->log(logger, LOG_LEVEL_DEBUG, "Debugging step X (file)");
    logger->log(logger, LOG_LEVEL_ERROR, "An error occurred (file)");

    logger->close(logger);

    // ConsoleLogger usage
    ConsoleLogger *clogger = create_console_logger();
    ILogger *console = &clogger->base;

    console->open(console, NULL); // No-op
    console->log(console, LOG_LEVEL_INFO, "Starting application (console)");
    console->log(console, LOG_LEVEL_DEBUG, "Debugging step Y (console)");
    console->log(console, LOG_LEVEL_ERROR, "An error occurred (console)");
    console->close(console);

    return 0;
}
