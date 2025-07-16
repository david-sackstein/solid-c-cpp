#include "FileLogger.h"
#include "ConsoleLogger.h"

void run_logger_demo(ILogger *logger) {
    logger->log(logger, LOG_LEVEL_INFO, "Starting application");
    logger->log(logger, LOG_LEVEL_DEBUG, "Debugging step");
    logger->log(logger, LOG_LEVEL_ERROR, "An error occurred");
}

int main() {
    // FileLogger usage
    FileLogger *flogger = create_file_logger("log.txt");
    if (!flogger) {
        return 1;
    }
    ILogger *file_logger = &flogger->base;
    run_logger_demo(file_logger);
    file_logger->close(file_logger);

    // ConsoleLogger usage
    ConsoleLogger *clogger = create_console_logger();
    if (!clogger) {
        return 1;
    }
    ILogger *console_logger = &clogger->base;
    run_logger_demo(console_logger);
    console_logger->close(console_logger);

    return 0;
}
