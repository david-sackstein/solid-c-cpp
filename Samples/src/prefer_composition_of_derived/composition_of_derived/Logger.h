#pragma once

#include "LogLevel.h"

#include <string>

#include "IMessageWriter.h"

namespace composition_of_derived {
    class Logger final {
        LogLevel logLevel_;
        IMessageWriter& writer_;

        std::string to_string(LogLevel);

    public:
        Logger(LogLevel, IMessageWriter&);

        virtual ~Logger() = default;

        void log(LogLevel logLevel, const std::string& msg);
    };
}
