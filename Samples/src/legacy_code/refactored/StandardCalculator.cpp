#include "StandardCalculator.h"
#include <sstream>

namespace refactored {
    StandardCalculator::StandardCalculator(injected::ILogger& logger, Memory& memory)
        : CalculatorBase(logger, memory) {}

    int StandardCalculator::performOperation(int a, int b) {
        int product = a * b;
        logger.log((std::ostringstream() << "[StandardCalculator] Multiplying " << a << " * " << b << " = " << product).str());
        return product;
    }

    void StandardCalculator::storeInMemory(int value) {
        CalculatorBase::storeInMemory(value);
        logger.log((std::ostringstream() << "[StandardCalculator] Additionally logging storage of " << value).str());
    }

    void StandardCalculator::performScientificCalculation(std::string operation) {
        logger.log((std::ostringstream() << "[StandardCalculator] Performing " << operation << " in mode " << currentMode).str());
    }

    void StandardCalculator::setMode(std::string mode) {
        CalculatorBase::setMode(mode);
        logger.log((std::ostringstream() << "[StandardCalculator] Mode additionally set to " << mode).str());
    }

    void StandardCalculator::reset() {
        clearMemory();
        currentMode = "standard";
        logger.log("[StandardCalculator] Calculator reset to standard mode.");
    }
}
