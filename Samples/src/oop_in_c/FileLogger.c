#include "FileLogger.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    FILE *file;
} FileLoggerImpl;

static void file_log(ILogger *self, LogLevel level, const char *message) {
    FileLoggerImpl *impl = (FileLoggerImpl *)self->impl;
    if (impl && impl->file && message) {
        fprintf(impl->file, "[%s] %s\n", log_level_to_string(level), message);
        fflush(impl->file);
    }
}

static void file_close(ILogger *self) {
    FileLoggerImpl *impl = (FileLoggerImpl *)self->impl;
    if (impl && impl->file && impl->file != stdout && impl->file != stderr) {
        fclose(impl->file);
        impl->file = NULL;
    }
    free(impl);
    free(self);
}

ILogger *create_file_logger(const char *filename) {
    ILogger *logger = (ILogger *)malloc(sizeof(ILogger));
    if (!logger) {
        return NULL;
    }
    FileLoggerImpl *impl = (FileLoggerImpl *)malloc(sizeof(FileLoggerImpl));
    if (!impl) {
        free(logger);
        return NULL;
    }
    impl->file = fopen(filename, "a");
    if (!impl->file) {
        free(impl);
        free(logger);
        return NULL;
    }
    logger->log = file_log;
    logger->close = file_close;
    logger->impl = impl;
    return logger;
}
