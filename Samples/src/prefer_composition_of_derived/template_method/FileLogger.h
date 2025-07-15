#pragma once

#include "BaseLogger.h"

namespace template_method {

    class FileLogger final : public BaseLogger {
        std::string fileName_;

        void writeMessage(const std::string& message) override;

    public:
        FileLogger(LogLevel logLevel, const std::string& fileName);
    };

}
