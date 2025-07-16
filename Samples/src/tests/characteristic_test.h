#pragma once

#include <injected/RecordingLogger.h>

#include <gtest/gtest.h>
#include <vector>
#include <string>

class CharacteristicTest : public ::testing::Test {
protected:

    const static std::vector<std::string> expected_logs;

    template<typename Standard, typename Business>
    void runTest(
        Standard &stdCalc, Business &bizCalc, injected::RecordingLogger& recLogger) {

        stdCalc.calculateAndStore(3, 4); // multiply
        stdCalc.setMode("engineering");

        bizCalc.calculateAndStore(10, 5); // subtract
        bizCalc.calculateAndStore(3, 7);  // subtract negative

        // Snapshot output verification
        const auto &logs = recLogger.getLogs();

        ASSERT_EQ(logs, expected_logs);
    }
};
