#include "BusinessCalculator.h"
#include <sstream>

namespace refactored {
    BusinessCalculator::BusinessCalculator(injected::ILogger& logger, Memory& memory)
        : CalculatorBase(logger, memory) {}

    int BusinessCalculator::performOperation(int a, int b) {
        int diff = a - b;
        logger.log((std::ostringstream() << "[BusinessCalculator] Subtracting " << a << " - " << b << " = " << diff).str());
        return diff;
    }

    void BusinessCalculator::storeInMemory(int value) {
        if (value < 0) {
            logger.log("[BusinessCalculator] Negative results not stored. Memory unchanged.");
        } else {
            CalculatorBase::storeInMemory(value);
        }
    }
}
