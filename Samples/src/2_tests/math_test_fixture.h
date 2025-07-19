#pragma once

#include <gtest/gtest.h>

class MathTestFixture : public ::testing::Test {
protected:
    int a = 0;
    int b = 0;

    static void SetUpTestSuite();
    static void TearDownTestSuite();

    void SetUp() override;
    void TearDown() override;
};
