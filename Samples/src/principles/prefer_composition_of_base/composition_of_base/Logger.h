#pragma once

#include "ILogger.h"

#include <string>

namespace composition_of_base {

    class Logger final : public ILogger {
    private:
        LogLevel logLevel_;

        std::string to_string(LogLevel logLevel);

    public:
        explicit Logger(LogLevel level);

        void log(LogLevel, const std::string& msg) override;
    };

}
