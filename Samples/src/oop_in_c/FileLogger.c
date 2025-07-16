#include "FileLogger.h"

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

static void file_log(ILogger *self, LogLevel level, const char *message) {
    FileLogger *flogger = (FileLogger *)self;
    if (flogger->file && message) {
        fprintf(flogger->file, "[%s] %s\n", log_level_to_string(level), message);
        fflush(flogger->file);
    }
}

static void file_close(ILogger *self) {
    FileLogger *flogger = (FileLogger *)self;
    if (flogger->file && flogger->file != stdout && flogger->file != stderr) {
        fclose(flogger->file);
        flogger->file = NULL;
    }
    free(flogger);
}

FileLogger *create_file_logger(const char *filename) {
    FileLogger *flogger = (FileLogger *)malloc(sizeof(FileLogger));
    if (!flogger) {
        return NULL;
    }
    flogger->file = fopen(filename, "a");
    if (!flogger->file) {
        free(flogger);
        return NULL;
    }
    flogger->base.log = file_log;
    flogger->base.close = file_close;
    return flogger;
}
