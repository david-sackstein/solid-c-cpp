#include "BusinessCalculator.h"

#include <sstream>

namespace refactored_again {
    int BusinessCalculator::performOperation(int a, int b) {
        int diff = a - b;
        logger.log((std::ostringstream() << "[BusinessCalculator] Subtracting " << a << " - " << b << " = " << diff).str());
        return diff;
    }

    void BusinessCalculator::storeInMemory(int value) {
        if (value < 0) {
            logger.log("[BusinessCalculator] Negative results not stored. Memory unchanged.");
        } else {
            memory.store(value);
            logger.log((std::ostringstream() << "[CalculatorBase] Stored " << value << " in memory.").str());
        }
    }

    BusinessCalculator::BusinessCalculator(injected::ILogger& logger, Memory& memory)
        : logger(logger), memory(memory) {}

    void BusinessCalculator::calculateAndStore(int a, int b) {
        int result = performOperation(a, b);
        storeInMemory(result);
    }
}
