#include "ConsoleLogger.h"

#include <iostream>

namespace duplication {

    ConsoleLogger::ConsoleLogger(LogLevel logLevel) : logLevel_(logLevel) {
    }

    void ConsoleLogger::log(LogLevel logLevel, const std::string& msg) {
        if (logLevel_ > logLevel) {
            return;
        }

        const std::string message = "[" + to_string(logLevel) + "]: " + msg;

        std::cout << message << std::endl;
    }

    std::string ConsoleLogger::to_string(LogLevel logLevel) {
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
