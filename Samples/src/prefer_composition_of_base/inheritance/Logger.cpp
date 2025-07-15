#include "Logger.h"

#include <string>
#include <iostream>

namespace inheritance {
    Logger::Logger(LogLevel logLevel) : logLevel_(logLevel) {
    }

    void Logger::log(LogLevel logLevel, const std::string &msg) {
        if (logLevel_ > logLevel) {
            return;
        }

        const std::string message = "[" + to_string(logLevel) + "]: " + msg;

        if (logLevel == LogLevel::ERROR) {
            std::cerr << message << std::endl;
        } else {
            std::cout << message << std::endl;
        }
    }

    std::string Logger::to_string(LogLevel logLevel) {
        switch (logLevel) {
            case LogLevel::DEBUG:
                return "DEBUG";
            case LogLevel::INFO:
                return "INFO";
            case LogLevel::ERROR:
                return "ERROR";
        }
        return "Unknown log level";
    }
}
