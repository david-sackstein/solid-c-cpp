#include "BusinessCalculator.h"
#include <iostream>

namespace legacy {
    BusinessCalculator::BusinessCalculator() = default;

    int BusinessCalculator::performOperation(int a, int b) {
        int diff = a - b;
        std::cout << "[BusinessCalculator] Subtracting " << a << " - " << b << " = " << diff << std::endl;
        return diff;
    }

    void BusinessCalculator::storeInMemory(int value) {
        if (value < 0) {
            std::cout << "[BusinessCalculator] Negative results not stored. Memory unchanged.\n";
        } else {
            CalculatorBase::storeInMemory(value);
        }
    }
}