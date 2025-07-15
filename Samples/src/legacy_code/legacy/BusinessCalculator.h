#pragma once

#include "CalculatorBase.h"
#include <iostream>

namespace legacy {
    // Calculator for business domain operations with constraints
    class BusinessCalculator : public CalculatorBase {
    public:
        BusinessCalculator();

        virtual ~BusinessCalculator() = default;

        int performOperation(int a, int b) override;

        void storeInMemory(int value) override;
    };
}