//
// Created by Eduardo_Ribeiro on 24/04/2020.
//
#include "gtest/gtest.h"
#include "PolishReverseCalculator.h"

TEST(POLISH_REVERSE_CALCULATOR, SingleNumber)
{
    PolishReverseCalculator calculator;

    int result = calculator.calc("1");
    EXPECT_EQ(1, result);
}

TEST(POLISH_REVERSE_CALCULATOR, TwoAdd)
{
    PolishReverseCalculator calculator;

    int result = calculator.calc("1 2 +");
    EXPECT_EQ(3, result);
}

TEST(POLISH_REVERSE_CALCULATOR, TwoMinusPositive)
{
    PolishReverseCalculator calculator;

    int result = calculator.calc("2 1 -");
    EXPECT_EQ(1, result);
}

TEST(POLISH_REVERSE_CALCULATOR, TwoMinusNegative)
{
    PolishReverseCalculator calculator;

    int result = calculator.calc("1 2 -");
    EXPECT_EQ(-1, result);
}

TEST(POLISH_REVERSE_CALCULATOR, ThreeAddPositive)
{
    PolishReverseCalculator calculator;

    int result = calculator.calc("1 2 + 3 +");
    EXPECT_EQ(6, result);
}

TEST(POLISH_REVERSE_CALCULATOR, ThreeNegative)
{
    PolishReverseCalculator calculator;

    int result = calculator.calc("1 2 - 1 +");
    EXPECT_EQ(0, result);
}

TEST(POLISH_REVERSE_CALCULATOR, TwoMultiply)
{
    PolishReverseCalculator calculator;

    int result = calculator.calc("2 3 *");
    EXPECT_EQ(6, result);
}

TEST(POLISH_REVERSE_CALCULATOR, ThreeMultiply)
{
    PolishReverseCalculator calculator;

    int result = calculator.calc("2 3 * 4 *");
    EXPECT_EQ(24, result);
}

TEST(POLISH_REVERSE_CALCULATOR, TwoDivision)
{
    PolishReverseCalculator calculator;

    int result = calculator.calc("4 2 /");
    EXPECT_EQ(2, result);
}

TEST(POLISH_REVERSE_CALCULATOR, ThreeDivision)
{
    PolishReverseCalculator calculator;

    int result = calculator.calc("4 2 / 2 /");
    EXPECT_EQ(1, result);
}

TEST(POLISH_REVERSE_CALCULATOR, ComplexMixOperations)
{
    PolishReverseCalculator calculator;

    int result = calculator.calc("2 3 + 4 * 10 - 2 /");
    EXPECT_EQ(5, result);
}