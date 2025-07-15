#pragma once

#include "ILogger.h"

namespace composition_of_base {

    class FileProcessor {
    public:
        explicit FileProcessor(ILogger&);

        void processFile(const std::string& filename) const;

    private:
        ILogger& logger_;
    };

}
