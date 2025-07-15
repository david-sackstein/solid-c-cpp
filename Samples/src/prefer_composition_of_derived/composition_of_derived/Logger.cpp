#include "Logger.h"

namespace composition_of_derived {
    Logger::Logger(LogLevel logLevel, IMessageWriter &writer)
        : logLevel_(logLevel),
          writer_(writer) {
    }

    void Logger::log(LogLevel logLevel, const std::string &msg) {
        if (logLevel_ > logLevel) {
            return;
        }

        const std::string message = "[" + to_string(logLevel) + "]: " + msg;

        writer_.writeMessage(message);
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
