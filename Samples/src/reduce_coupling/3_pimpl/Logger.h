#pragma once

#include "LogLevel.h"

#include <string>

namespace pimpl {

    class Logger {
    private:
        LogLevel logLevel_;

        std::string to_string(LogLevel logLevel);

    public:
        explicit Logger(LogLevel level);

        void log(LogLevel, const std::string& msg);
    };

}
