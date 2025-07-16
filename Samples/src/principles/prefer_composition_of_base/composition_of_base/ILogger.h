#pragma once

#include <string>

namespace composition_of_base {

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

}