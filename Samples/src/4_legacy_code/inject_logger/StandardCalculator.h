#pragma once

#include "CalculatorBase.h"

#include <string>

namespace inject_logger {
    // Calculator for general operations
    class StandardCalculator : public CalculatorBase {
    public:
        StandardCalculator(injected::ILogger& logger);

        virtual ~StandardCalculator() = default;

        int performOperation(int a, int b) override;

        void storeInMemory(int value) override;

        void performScientificCalculation(std::string operation);

        void setMode(std::string mode) override;

        void reset();
    };
}