#include "StandardCalculator.h"
#include <iostream>

namespace legacy {
    StandardCalculator::StandardCalculator() = default;

    int StandardCalculator::performOperation(int a, int b) {
        int product = a * b;
        std::cout << "[StandardCalculator] Multiplying " << a << " * " << b << " = " << product << std::endl;
        return product;
    }

    void StandardCalculator::storeInMemory(int value) {
        CalculatorBase::storeInMemory(value);
        std::cout << "[StandardCalculator] Additionally logging storage of " << value << std::endl;
    }

    void StandardCalculator::performScientificCalculation(std::string operation) {
        std::cout << "[StandardCalculator] Performing " << operation << " in mode " << currentMode << std::endl;
    }

    void StandardCalculator::setMode(std::string mode) {
        CalculatorBase::setMode(mode);
        std::cout << "[StandardCalculator] Mode additionally set to " << mode << std::endl;
    }

    void StandardCalculator::reset() {
        clearMemory();
        currentMode = "standard";
        std::cout << "[StandardCalculator] Calculator reset to standard mode.\n";
    }
}