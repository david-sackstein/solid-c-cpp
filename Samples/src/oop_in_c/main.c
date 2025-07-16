#include "FileLogger.h"
#include "ConsoleLogger.h"

void run_logger_demo(ILogger *logger) {
    logger->log(logger, LOG_LEVEL_INFO, "Starting application");
    logger->log(logger, LOG_LEVEL_DEBUG, "Debugging step");
    logger->log(logger, LOG_LEVEL_ERROR, "An error occurred");
}

int main() {
    // FileLogger usage
    ILogger *file_logger = create_file_logger("log.txt");
    if (!file_logger) {
        return 1;
    }

    run_logger_demo(file_logger);
    file_logger->close(file_logger);

    // ConsoleLogger usage
    ILogger *console_logger = create_console_logger();
    if (!console_logger) {
        return 1;
    }

    run_logger_demo(console_logger);
    console_logger->close(console_logger);

    return 0;
}
