#include "BaseLogger.h"

namespace template_method {
    BaseLogger::BaseLogger(LogLevel logLevel): logLevel_(logLevel) {
    }

    void BaseLogger::log(LogLevel logLevel, const std::string& msg) {
        if (logLevel_ > logLevel) {
            return;
        }

        const std::string message = "[" + to_string(logLevel) + "]: " + msg;

        writeMessage(message);
    }

    std::string BaseLogger::to_string(LogLevel logLevel) {
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
