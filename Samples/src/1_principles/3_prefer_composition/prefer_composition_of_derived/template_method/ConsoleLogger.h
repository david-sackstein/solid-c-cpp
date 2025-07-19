#pragma once

#include "BaseLogger.h"

namespace template_method {

    class ConsoleLogger final : public BaseLogger {

        void writeMessage(const std::string& message) override;

    public:
        explicit ConsoleLogger(LogLevel logLevel);
    };

}
