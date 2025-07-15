#include <gtest/gtest.h>

#include <string>
#include <vector>

TEST(TestSuite, Addition) {
    constexpr int sum = 2 + 3;
    EXPECT_EQ(sum, 5);
}

TEST(TestSuite, StringConcatenation) {
    const std::string hello = "Hello, ";
    const std::string world = "world!";
    ASSERT_EQ(hello + world, "Hello, world!");
}

TEST(TestSuite, VectorSize) {
    const std::vector<int> nums = {1, 2, 3, 4};
    EXPECT_EQ(nums.size(), 4u);
}

TEST(TestSuite, BooleanCondition) {
    constexpr bool condition = (10 > 5);
    EXPECT_TRUE(condition);
}
