#include "ConsoleLogger.h"

#include <stdio.h>
#include <stdlib.h>

static void console_log(ILogger *self, LogLevel level, const char *message) {
    (void)self;
    if (message) {
        printf("[%s] %s\n", log_level_to_string(level), message);
        fflush(stdout);
    }
}

static void console_close(ILogger *self) {
    if (self->impl) {
        free(self->impl);
    }
    free(self);
}

ILogger *create_console_logger() {
    ILogger *logger = (ILogger *)malloc(sizeof(ILogger));
    if (!logger) {
        return NULL;
    }
    logger->log = console_log;
    logger->close = console_close;
    logger->impl = 0;
    return logger;
} 