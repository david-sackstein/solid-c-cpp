#include "CalculatorBase.h"
#include <sstream>

namespace inject_logger {
    CalculatorBase::CalculatorBase(injected::ILogger& logger) : memory(0), currentMode("standard"), logger(logger) {}

    void CalculatorBase::calculateAndStore(int a, int b) {
        int result = performOperation(a, b);
        storeInMemory(result);
    }

    int CalculatorBase::performOperation(int a, int b) {
        int sum = a + b;
        logger.log((std::ostringstream() << "[CalculatorBase] Default adding " << a << " + " << b << " = " << sum).str());
        return sum;
    }

    void CalculatorBase::storeInMemory(int value) {
        memory = value;
        logger.log((std::ostringstream() << "[CalculatorBase] Stored " << value << " in memory.").str());
    }

    int CalculatorBase::recallMemory() {
        std::ostringstream oss;
        oss << "[CalculatorBase] Recalled " << memory << " from memory.";
        logger.log((std::ostringstream() << "[CalculatorBase] Recalled " << memory << " from memory.").str());
        return memory;
    }

    void CalculatorBase::clearMemory() {
        memory = 0;
        logger.log((std::ostringstream() << "[CalculatorBase] Memory cleared.").str());
    }

    void CalculatorBase::setMode(std::string mode) {
        currentMode = mode;
        logger.log((std::ostringstream() << "[CalculatorBase] Mode set to " << mode).str());
    }

    std::string CalculatorBase::getMode() {
        return currentMode;
    }
}