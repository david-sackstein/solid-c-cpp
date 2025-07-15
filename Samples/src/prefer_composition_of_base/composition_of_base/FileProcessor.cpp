#include "FileProcessor.h"

#include <fstream>

namespace composition_of_base {
    FileProcessor::FileProcessor(ILogger &logger): logger_(logger) {
    }

    void FileProcessor::processFile(const std::string &filename) const {
        std::ifstream file(filename);
        if (!file.is_open()) {
            logger_.log(LogLevel::ERROR, "Failed to open file: " + filename);
            return;
        }

        logger_.log(LogLevel::INFO, "Processing file: " + filename);

        std::string line;
        while (std::getline(file, line)) {
            // Process each line
        }

        logger_.log(LogLevel::INFO, "Finished processing file: " + filename);
    }
}
