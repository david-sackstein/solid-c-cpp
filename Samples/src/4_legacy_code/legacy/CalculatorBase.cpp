#include "CalculatorBase.h"
#include <iostream>

namespace legacy {
    CalculatorBase::CalculatorBase() : memory(0), currentMode("standard") {}

    void CalculatorBase::calculateAndStore(int a, int b) {
        int result = performOperation(a, b);
        storeInMemory(result);
    }

    int CalculatorBase::performOperation(int a, int b) {
        int sum = a + b;
        std::cout << "[CalculatorBase] Default adding " << a << " + " << b << " = " << sum << std::endl;
        return sum;
    }

    void CalculatorBase::storeInMemory(int value) {
        memory = value;
        std::cout << "[CalculatorBase] Stored " << value << " in memory.\n";
    }

    int CalculatorBase::recallMemory() {
        std::cout << "[CalculatorBase] Recalled " << memory << " from memory.\n";
        return memory;
    }

    void CalculatorBase::clearMemory() {
        memory = 0;
        std::cout << "[CalculatorBase] Memory cleared.\n";
    }

    void CalculatorBase::setMode(std::string mode) {
        currentMode = mode;
        std::cout << "[CalculatorBase] Mode set to " << mode << std::endl;
    }

    std::string CalculatorBase::getMode() {
        return currentMode;
    }
}