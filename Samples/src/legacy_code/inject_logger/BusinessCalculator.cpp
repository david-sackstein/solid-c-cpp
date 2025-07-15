#include "BusinessCalculator.h"
#include <iostream>

namespace inject_logger {
    BusinessCalculator::BusinessCalculator(ILogger& logger) : CalculatorBase(logger) {}

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