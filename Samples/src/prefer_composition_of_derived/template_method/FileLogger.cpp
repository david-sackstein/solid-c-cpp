#include "FileLogger.h"

#include <fstream>

namespace template_method {
    FileLogger::FileLogger(LogLevel logLevel, const std::string &fileName)
        : BaseLogger(logLevel),
          fileName_(fileName) {
    }

    void FileLogger::writeMessage(const std::string &message) {
        std::ofstream logFile(fileName_, std::ios::app);
        if (!logFile.is_open()) {
            return;
        }
        logFile << message << std::endl;
    }
}
