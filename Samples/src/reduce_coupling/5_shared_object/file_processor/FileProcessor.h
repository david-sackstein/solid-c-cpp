#pragma once

#include "../include/logger/ILogger.h"

namespace shared_object {

    class FileProcessor {
    public:
        explicit FileProcessor(ILogger&);

        void processFile(const std::string& filename) const;

    private:
        ILogger& logger_;
    };

}
