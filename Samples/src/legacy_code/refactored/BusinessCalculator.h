#pragma once

#include "CalculatorBase.h"

namespace refactored {
    // Calculator for business domain operations with constraints
    class BusinessCalculator : public CalculatorBase {
    public:
        BusinessCalculator(injected::ILogger& logger, Memory& memory);

        int performOperation(int a, int b) override;

        void storeInMemory(int value) override;
    };
}
