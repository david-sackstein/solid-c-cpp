#include <inject_logger/StandardCalculator.h>
#include <inject_logger/BusinessCalculator.h>

#include <refactored/StandardCalculator.h>
#include <refactored/BusinessCalculator.h>

#include <recorder/RecordingLogger.h>

#include <gtest/gtest.h>
#include <vector>
#include <string>

const std::vector<std::string> expected_logs = {
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

using namespace injected;

TEST(CharacteristicTests, VerifyOriginalLogSnapshot) {
    using namespace inject_logger;

    RecordingLogger recLogger;

    StandardCalculator stdCalc(recLogger);
    BusinessCalculator bizCalc(recLogger);

    stdCalc.calculateAndStore(3, 4); // multiply
    stdCalc.setMode("engineering");

    bizCalc.calculateAndStore(10, 5); // subtract
    bizCalc.calculateAndStore(3, 7);  // subtract negative

    // Snapshot output verification
    const auto& logs = recLogger.getLogs();

    ASSERT_EQ(logs, expected_logs);
}

TEST(CharacteristicTests, VerifyRefactoredLogSnapshot) {
    using namespace refactored;

    RecordingLogger recLogger;

    StandardCalculator stdCalc(recLogger);
    BusinessCalculator bizCalc(recLogger);

    stdCalc.calculateAndStore(3, 4); // multiply
    stdCalc.setMode("engineering");

    bizCalc.calculateAndStore(10, 5); // subtract
    bizCalc.calculateAndStore(3, 7);  // subtract negative

    // Snapshot output verification
    const auto& logs = recLogger.getLogs();

    ASSERT_EQ(logs, expected_logs);
}
