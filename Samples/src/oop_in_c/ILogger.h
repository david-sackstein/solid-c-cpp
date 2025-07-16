#pragma once

typedef enum {
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARN,
    LOG_LEVEL_ERROR
} LogLevel;

// Logger interface struct
typedef struct ILogger {
    void (*log)(struct ILogger *self, LogLevel level, const char *message);
    void (*close)(struct ILogger *self);
} ILogger;