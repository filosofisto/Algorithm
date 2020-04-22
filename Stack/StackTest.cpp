//
// Created by eduardo on 22.04.20.
//
#include "gtest/gtest.h"
#include "Stack.h"

TEST(STACK, Size)
{
    auto stack = new Stack<int>();
    EXPECT_EQ(0, stack->getSize());
    stack->push(new int(1));
    EXPECT_NE(0, stack->getSize());
}

TEST(STACK, Empty)
{
    auto stack = new Stack<int>();
    EXPECT_TRUE(stack->empty());
    stack->push(new int(1));
    EXPECT_FALSE(stack->empty());
}

TEST(STACK, PushPop)
{
    auto stack = new Stack<int>();
    EXPECT_TRUE(stack->empty());
    stack->push(new int(1));
    EXPECT_FALSE(stack->empty());
    int value = *stack->pop();
    EXPECT_TRUE(stack->empty());
    EXPECT_EQ(1, value);
}

TEST(STACK, Peek)
{
    auto stack = new Stack<int>();
    EXPECT_TRUE(stack->empty());
    stack->push(new int(1));
    EXPECT_FALSE(stack->empty());
    int value = *stack->peek();
    EXPECT_FALSE(stack->empty());
    EXPECT_EQ(1, value);
}