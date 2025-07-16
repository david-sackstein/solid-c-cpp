#include "characteristic_test.h"

#include <inject_logger/BusinessCalculator.h>
#include <inject_logger/StandardCalculator.h>

#include <refactored/BusinessCalculator.h>
#include <refactored/StandardCalculator.h>

const std::vector<std::string> CharacteristicTest::expected_logs = {
    "[StandardCalculator] Multiplying 3 * 4 = 12",
    "[CalculatorBase] Stored 12 in memory.",
    "[StandardCalculator] Additionally logging storage of 12",
    "[CalculatorBase] Mode set to engineering",
    "[StandardCalculator] Mode additionally set to engineering",
    "[BusinessCalculator] Subtracting 10 - 5 = 5",
    "[CalculatorBase] Stored 5 in memory.",
    "[BusinessCalculator] Subtracting 3 - 7 = -4",
    "[BusinessCalculator] Negative results not stored. Memory unchanged."
};

TEST_F(CharacteristicTest, VerifyOriginal) {
    using namespace inject_logger;

    injected::RecordingLogger recLogger{};

    StandardCalculator stdCalc(recLogger);
    BusinessCalculator busCalc(recLogger);

    runTest(stdCalc, busCalc, recLogger);
}

TEST_F(CharacteristicTest, VerifyRefactored) {
    using namespace refactored;

    injected::RecordingLogger recLogger{};

    Memory mem{};
    StandardCalculator stdCalc(recLogger, mem);
    BusinessCalculator busCalc(recLogger, mem);

    runTest(stdCalc, busCalc, recLogger);
}
