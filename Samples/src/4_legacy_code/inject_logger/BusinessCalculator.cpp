#include "BusinessCalculator.h"
#include <sstream>

namespace inject_logger {
    BusinessCalculator::BusinessCalculator(injected::ILogger& logger) : CalculatorBase(logger) {}

    int BusinessCalculator::performOperation(int a, int b) {
        int diff = a - b;
        logger.log((std::ostringstream() << "[BusinessCalculator] Subtracting " << a << " - " << b << " = " << diff).str());
        return diff;
    }

    void BusinessCalculator::storeInMemory(int value) {
        if (value < 0) {
            logger.log((std::ostringstream() << "[BusinessCalculator] Negative results not stored. Memory unchanged.").str());
        } else {
            CalculatorBase::storeInMemory(value);
        }
    }
}