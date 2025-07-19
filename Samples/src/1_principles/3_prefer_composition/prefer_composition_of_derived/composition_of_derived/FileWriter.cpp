#include "FileWriter.h"

#include <fstream>

namespace composition_of_derived {
    FileWriter::FileWriter(const std::string &fileName)
        : fileName_(fileName) {
    }

    void FileWriter::writeMessage(const std::string &message) {
        std::ofstream logFile(fileName_, std::ios::app);
        if (!logFile.is_open()) {
            return;
        }
        logFile << message << std::endl;
    }
}
