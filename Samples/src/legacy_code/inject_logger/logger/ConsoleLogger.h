#include "ILogger.h"

#include <iostream>

namespace inject_logger {
    class ConsoleLogger : public ILogger {
    public:
        void log(const std::string &message) override {
            std::cout << message << std::endl;
        }
    };
}