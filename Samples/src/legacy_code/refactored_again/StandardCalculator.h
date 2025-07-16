#pragma once

#include "Memory.h"

#include <injected/ILogger.h>

#include <string>

namespace refactored_again {
    // Calculator for general operations without inheritance
    class StandardCalculator {
    public:
        StandardCalculator(injected::ILogger& logger, Memory& memory);

        void calculateAndStore(int a, int b);
        void performScientificCalculation(std::string operation);
        void setMode(std::string mode);
        void reset();

    private:
        int performOperation(int a, int b);
        void storeInMemory(int value);

        injected::ILogger& logger;
        Memory& memory;
        std::string currentMode = "standard";
    };
}
