#pragma once

#include <string>
#include <fstream>

namespace inheritance_separate_files {

    enum class LogLevel {
        DEBUG,
        INFO,
        ERROR
    };

    class Logger {
    private:
        LogLevel logLevel_;

        std::string to_string(LogLevel logLevel);

    public:
        explicit Logger(LogLevel logLevel);

        void log(LogLevel logLevel, const std::string& msg);
    };

}
