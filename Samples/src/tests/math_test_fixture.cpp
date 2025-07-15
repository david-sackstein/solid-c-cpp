#include "math_test_fixture.h"

#include <iostream>

TEST_F(MathTestFixture, AdditionTest) {
    std::cout << "AdditionTest" << std::endl;
    EXPECT_EQ(a + b, 15);
}

TEST_F(MathTestFixture, SubtractionTest) {
    std::cout << "SubtractionTest" << std::endl;
    EXPECT_EQ(a - b, 5);
}

TEST_F(MathTestFixture, MultiplicationTest) {
    std::cout << "MultiplicationTest" << std::endl;
    EXPECT_EQ(a * b, 50);
}

TEST_F(MathTestFixture, DivisionTest) {
    std::cout << "DivisionTest" << std::endl;
    ASSERT_NE(b, 0); // Prevent division by zero
    EXPECT_EQ(a / b, 2);
}

TEST_F(MathTestFixture, GreaterThanTest) {
    std::cout << "GreaterThanTest" << std::endl;
    EXPECT_GT(a, b);
}

void MathTestFixture::SetUpTestSuite() {
    std::cout << "SetUpTestSuite legacy all tests" << std::endl;
}

void MathTestFixture::TearDownTestSuite() {
    std::cout << "TearDownTestSuite after all tests" << std::endl;
}

void MathTestFixture::SetUp() {
    std::cout << "SetUp" << std::endl;
    a = 10;
    b = 5;
}

void MathTestFixture::TearDown() {
    std::cout << "TearDown" << std::endl;
}
