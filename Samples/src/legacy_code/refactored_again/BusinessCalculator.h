#pragma once

#include "Memory.h"

#include <injected/ILogger.h>

namespace refactored_again {
    // Calculator for business domain operations without inheritance
    class BusinessCalculator {
    public:
        BusinessCalculator(injected::ILogger& logger, Memory& memory);

        void calculateAndStore(int a, int b);

    private:
        int performOperation(int a, int b);
        void storeInMemory(int value);

        injected::ILogger& logger;
        Memory& memory;
    };
}
