#include "FileLogger.h"

int main() {
    FileLogger *flogger = create_file_logger();
    ILogger *logger = &flogger->base;

    if (logger->open(logger, "log.txt") != 0) {
        return 1;
    }

    logger->log(logger, LOG_LEVEL_INFO, "Starting application");
    logger->log(logger, LOG_LEVEL_DEBUG, "Debugging step X");
    logger->log(logger, LOG_LEVEL_ERROR, "An error occurred");

    logger->close(logger);

    return 0;
}
