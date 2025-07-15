#include "FileProcessor.h"
#include "Logger.h"

#include <fstream>

namespace pimpl {

    FileProcessor::FileProcessor(LogLevel logLevel): logger_(new Logger(logLevel)) {
    }

    FileProcessor::~FileProcessor() {
        delete logger_;
    }

    void FileProcessor::processFile(const std::string &filename) const {
        std::ifstream file(filename);
        if (!file.is_open()) {
            logger_->log(LogLevel::ERROR, "Failed to open file: " + filename);
            return;
        }

        logger_->log(LogLevel::INFO, "Processing file: " + filename);

        std::string line;
        while (std::getline(file, line)) {
            // Process each line
        }

        logger_->log(LogLevel::INFO, "Finished processing file: " + filename);
    }
}
