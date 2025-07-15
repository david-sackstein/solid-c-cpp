#pragma once

#include "LogLevel.h"

#include <string>

namespace duplication {

    class ConsoleLogger {
        LogLevel logLevel_;

        std::string to_string(LogLevel logLevel);

    public:
        explicit ConsoleLogger(LogLevel logLevel);

        void log(LogLevel, const std::string &msg);
    };

}