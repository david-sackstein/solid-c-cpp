#pragma once

#include <string>

namespace prefer_composition {

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