#include "FileLogger.h"

#include <fstream>

namespace duplication {
    FileLogger::FileLogger(LogLevel logLevel, const std::string &fileName)
        : logLevel_(logLevel),
          fileName_(fileName) {
    }

    void FileLogger::log(LogLevel logLevel, const std::string &msg) {
        if (logLevel_ > logLevel) {
            return;
        }

        std::ofstream logFile(fileName_, std::ios::app);
        if (!logFile.is_open()) {
            return;
        }

        const std::string message = "[" + to_string(logLevel) + "]: " + msg;

        logFile << message << std::endl;
    }

    std::string FileLogger::to_string(LogLevel logLevel) {
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
}
