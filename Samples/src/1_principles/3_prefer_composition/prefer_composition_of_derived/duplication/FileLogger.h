#pragma once

#include "LogLevel.h"

#include <string>

namespace duplication {

    class FileLogger {
        LogLevel logLevel_;
        std::string fileName_;

        std::string to_string(LogLevel logLevel);

    public:
        FileLogger(LogLevel logLevel, const std::string& fileName);

        void log(LogLevel, const std::string &msg);
    };

}
