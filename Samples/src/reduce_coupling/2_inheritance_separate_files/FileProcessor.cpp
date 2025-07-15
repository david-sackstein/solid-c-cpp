#include "FileProcessor.h"

namespace inheritance_separate_files {
    FileProcessor::FileProcessor(LogLevel level)
        : Logger(level) {
    }

    void FileProcessor::processFile(const std::string &filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            log(LogLevel::ERROR, "Failed to open file: " + filename);
            return;
        }

        log(LogLevel::INFO, "Processing file: " + filename);

        std::string line;
        while (std::getline(file, line)) {
            // Process each line
        }

        log(LogLevel::INFO, "Finished processing file: " + filename);
    }
}
