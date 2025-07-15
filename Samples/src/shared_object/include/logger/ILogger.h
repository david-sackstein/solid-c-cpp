#pragma once

#include <Exported.h>

#include <string>
#include <memory>

namespace shared_object {

    enum class LogLevel {
        DEBUG,
        INFO,
        ERROR
    };

    class ILogger {
    public:
        virtual ~ILogger() = default;

        virtual void log(LogLevel, const std::string& msg) = 0;
    };

    EXPORTED std::unique_ptr<ILogger> create_logger(LogLevel);

    extern "C"
    EXPORTED ILogger* create_logger_unmangled(LogLevel);
}
