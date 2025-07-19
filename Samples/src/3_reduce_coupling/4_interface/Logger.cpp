#include "Logger.h"

#include <iostream>

namespace prefer_composition {
    Logger::Logger(LogLevel logLevel) : logLevel_(logLevel) {}

    void Logger::log(LogLevel logLevel, const std::string& msg) {
        if (logLevel_ > logLevel) {
            return;
        }

        const std::string message = "[" + to_string(logLevel) + "]: " + msg;

        std::cout << message << std::endl;
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