#pragma once

#include "ILogger.h"

#include <vector>
#include <string>

namespace injected {

    class RecordingLogger : public ILogger {
    public:
        void log(const std::string &message) override {
            logs.push_back(message);
        }

        const std::vector<std::string> &getLogs() const {
            return logs;
        }

    private:
        std::vector<std::string> logs;
    };
}
