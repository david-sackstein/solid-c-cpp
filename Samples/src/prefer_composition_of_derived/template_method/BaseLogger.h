#pragma once

#include "LogLevel.h"

#include <string>

namespace template_method {
    class BaseLogger {
        LogLevel logLevel_;

        std::string to_string(LogLevel);

        virtual void writeMessage(const std::string& message) = 0;

    public:
        explicit BaseLogger(LogLevel);
        virtual ~BaseLogger() = default;

        void log(LogLevel logLevel, const std::string& msg);
    };
}
