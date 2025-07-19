#pragma once

#include "CalculatorBase.h"

namespace inject_logger {
    // Calculator for business domain operations with constraints
    class BusinessCalculator : public CalculatorBase {
    public:
        BusinessCalculator(injected::ILogger& logger);

        virtual ~BusinessCalculator() = default;

        int performOperation(int a, int b) override;

        void storeInMemory(int value) override;
    };
}