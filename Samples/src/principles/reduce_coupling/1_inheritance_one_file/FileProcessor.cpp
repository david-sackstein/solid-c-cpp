#include "FileProcessor.h"

#include <iostream>
#include <fstream>

namespace reduce_coupling_inheritance_one_file {

    // ================ Logger ==================

    Logger::Logger(LogLevel logLevel) : logLevel_(logLevel) {
    }

    void Logger::log(LogLevel logLevel, const std::string &msg) {
        if (logLevel_ > logLevel) {
            return;
        }

        const std::string message = "[" + to_string(logLevel) + "]: " + msg;

        if (logLevel == LogLevel::ERROR) {
            std::cerr << message << std::endl;
        } else {
            std::cout << message << std::endl;
        }
    }

    std::string Logger::to_string(LogLevel logLevel) {
        switch (logLevel) {
            case LogLevel::DEBUG:
                return "DEBUG";
            case LogLevel::INFO:
                return "INFO";
            case LogLevel::ERROR:
                return "ERROR";
        }
        return "Unknown log level";
    }

    // ============= FileProcessor ===============

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
