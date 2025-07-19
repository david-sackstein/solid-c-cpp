#pragma once

#include <string>

namespace injected {
    class ILogger {
    public:
        virtual ~ILogger() = default;

        virtual void log(const std::string &message) = 0;
    };
}