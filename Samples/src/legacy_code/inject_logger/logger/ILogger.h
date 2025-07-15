#pragma once

#include <string>

namespace inject_logger {
    class ILogger {
    public:
        virtual ~ILogger() = default;

        virtual void log(const std::string &message) = 0;
    };
}