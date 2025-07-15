#pragma once

#include "Logger.h"

namespace inheritance {

    class FileProcessor : public Logger {
    public:
        explicit FileProcessor(LogLevel level);

        void processFile(const std::string& filename);
    };

}
