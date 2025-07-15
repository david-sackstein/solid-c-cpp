#pragma once

#include <string>

namespace reduce_coupling_inheritance_one_file {

    enum class LogLevel {
        DEBUG,
        INFO,
        ERROR
    };

    // ================ Logger ==================

    class Logger {
    private:
        LogLevel logLevel_;

        std::string to_string(LogLevel logLevel);

    public:
        explicit Logger(LogLevel logLevel);

        void log(LogLevel logLevel, const std::string& msg);
    };

    // ============= FileProcessor ===============

    class FileProcessor : public Logger {
    public:
        explicit FileProcessor(LogLevel level);

        void processFile(const std::string& filename);
    };

}
