#include "Calculator.h"

#include <sstream>

namespace refactored_again {
    Calculator::Calculator(injected::ILogger& logger, Memory& memory,
                           OperationStrategy operation,
                           StoreStrategy storeStrategy)
        : logger(logger), memory(memory),
          operation(operation), storeStrategy(storeStrategy),
          currentMode("standard") {}

    void Calculator::calculateAndStore(int a, int b) {
        int result = operation(a, b);
        storeStrategy(result);
    }

    int Calculator::recallMemory() {
        int value = memory.recall();
        logger.log((std::ostringstream() << "[Calculator] Recalled " << value << " from memory.").str());
        return value;
    }

    void Calculator::clearMemory() {
        memory.clear();
        logger.log("[Calculator] Memory cleared.");
    }

    void Calculator::setMode(std::string mode) {
        currentMode = mode;
        logger.log((std::ostringstream() << "[Calculator] Mode set to " << mode).str());
    }

    std::string Calculator::getMode() {
        return currentMode;
    }
}
