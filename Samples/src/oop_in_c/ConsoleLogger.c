#include "ConsoleLogger.h"

#include <stdio.h>
#include <stdlib.h>

static const char *log_level_to_string(LogLevel level) {
    switch (level) {
        case LOG_LEVEL_DEBUG: return "DEBUG";
        case LOG_LEVEL_INFO:  return "INFO";
        case LOG_LEVEL_WARN:  return "WARN";
        case LOG_LEVEL_ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}

static int console_open(ILogger *self, const char *target) {
    // No-op for console logger
    (void)self; (void)target;
    return 0;
}

static void console_log(ILogger *self, LogLevel level, const char *message) {
    (void)self;
    if (message) {
        printf("[%s] %s\n", log_level_to_string(level), message);
        fflush(stdout);
    }
}

static void console_close(ILogger *self) {
    // No-op for console logger
    free(self);
}

ConsoleLogger *create_console_logger() {
    ConsoleLogger *clogger = (ConsoleLogger *)malloc(sizeof(ConsoleLogger));
    if (!clogger) {
        return NULL;
    }
    clogger->base.open = console_open;
    clogger->base.log = console_log;
    clogger->base.close = console_close;
    return clogger;
} 