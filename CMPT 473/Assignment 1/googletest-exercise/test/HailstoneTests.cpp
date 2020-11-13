#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Hailstone.h"

using namespace sequence;
using namespace testing;

// Tests for base cases

TEST(HailstoneTests, baseCase0) {
    ASSERT_FALSE(satisfiesHailstone(0));
}

TEST(HailstoneTests, baseCase1) {
    ASSERT_TRUE(satisfiesHailstone(1));
}

// Tests for when number is even

TEST(HailstoneTests, evenNum) {
    ASSERT_TRUE(satisfiesHailstone(2));
}

TEST(HailstoneTests, largeEvenNum) {
    ASSERT_TRUE(satisfiesHailstone(999998));
}

// Tests for when number is odd

TEST(HailstoneTests, oddNum) {
    ASSERT_TRUE(satisfiesHailstone(1));
}

TEST(HailstoneTests, largeOddNum) {
    ASSERT_TRUE(satisfiesHailstone(999999));
}

// Test for when number is negative

TEST(HailstoneTests, negativeNum) {
    ASSERT_TRUE(satisfiesHailstone(-1));
}