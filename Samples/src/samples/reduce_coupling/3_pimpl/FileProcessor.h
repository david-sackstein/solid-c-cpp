#pragma once

#include "LogLevel.h"

#include <string>

namespace pimpl {

    class Logger;

    class FileProcessor {
    public:
        explicit FileProcessor(LogLevel logLevel);
        ~FileProcessor();

        void processFile(const std::string& filename) const;

    private:
        Logger* logger_;
    };

}
