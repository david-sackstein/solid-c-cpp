#include "ConsoleWriter.h"

#include <iostream>

namespace composition_of_derived {
    void ConsoleWriter::writeMessage(const std::string& message) {
        std::cout << message << std::endl;
    }
}
