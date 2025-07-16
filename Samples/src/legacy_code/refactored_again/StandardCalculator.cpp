#include "StandardCalculator.h"

#include <sstream>

namespace refactored_again {
    StandardCalculator::StandardCalculator(injected::ILogger& logger, Memory& memory)
        : logger(logger), memory(memory) {}

    int StandardCalculator::performOperation(int a, int b) {
        int product = a * b;
        logger.log((std::ostringstream() << "[StandardCalculator] Multiplying " << a << " * " << b << " = " << product).str());
        return product;
    }

    void StandardCalculator::storeInMemory(int value) {
        memory.store(value);
        logger.log((std::ostringstream() << "[CalculatorBase] Stored " << value << " in memory.").str());
        logger.log((std::ostringstream() << "[StandardCalculator] Additionally logging storage of " << value).str());
    }

    void StandardCalculator::performScientificCalculation(std::string operation) {
        logger.log((std::ostringstream() << "[StandardCalculator] Performing " << operation << " in mode " << currentMode).str());
    }

    void StandardCalculator::setMode(std::string mode) {
        currentMode = mode;
        logger.log((std::ostringstream() << "[CalculatorBase] Mode set to " << mode).str());
        logger.log((std::ostringstream() << "[StandardCalculator] Mode additionally set to " << mode).str());
    }

    void StandardCalculator::reset() {
        memory.clear();
        currentMode = "standard";
        logger.log("[StandardCalculator] Calculator reset to standard mode.");
    }

    void StandardCalculator::calculateAndStore(int a, int b) {
        int result = performOperation(a, b);
        storeInMemory(result);
    }
}
