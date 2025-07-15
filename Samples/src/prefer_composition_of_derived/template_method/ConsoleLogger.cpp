#include "ConsoleLogger.h"

#include <iostream>

namespace template_method {

    ConsoleLogger::ConsoleLogger(LogLevel logLevel) : BaseLogger(logLevel) {
    }

    void ConsoleLogger::writeMessage(const std::string& message) {
        std::cout << message << std::endl;
    }
}
