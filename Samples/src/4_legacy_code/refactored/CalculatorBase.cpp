#include "CalculatorBase.h"
#include <sstream>

namespace refactored {
    CalculatorBase::CalculatorBase(injected::ILogger& logger, Memory& memory)
        : currentMode("standard"), logger(logger), memory(memory) {}

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
        memory.store(value);
        logger.log((std::ostringstream() << "[CalculatorBase] Stored " << value << " in memory.").str());
    }

    int CalculatorBase::recallMemory() {
        int value = memory.recall();
        logger.log((std::ostringstream() << "[CalculatorBase] Recalled " << value << " from memory.").str());
        return value;
    }

    void CalculatorBase::clearMemory() {
        memory.clear();
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
