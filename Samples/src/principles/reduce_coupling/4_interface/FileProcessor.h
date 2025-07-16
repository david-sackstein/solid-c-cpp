#pragma once

#include "ILogger.h"

namespace prefer_composition {

    class FileProcessor {
    public:
        explicit FileProcessor(ILogger&);

        void processFile(const std::string& filename) const;

    private:
        ILogger& logger_;
    };

}
