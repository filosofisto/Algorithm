#include <iostream>
#include <memory>
#include "gtest/gtest.h"
#include "StackArray.h"
#include "StackVector.h"

using std::unique_ptr;
using std::make_unique;
using std::underflow_error;
using std::overflow_error;

TEST(STACK_ARRAY, empty)
{
  auto stack = make_unique<StackArray<int>>();

  EXPECT_TRUE(stack->empty());

  stack->push(10);
  EXPECT_FALSE(stack->empty());
}

TEST(STACK_ARRAY, size)
{
  auto stack = make_unique<StackArray<int>>();

  EXPECT_EQ(0, stack->size());

  stack->push(1);
  stack->push(2);
  stack->pop();

  EXPECT_EQ(1, stack->size());
}

TEST(STACK_ARRAY, underflow)
{
  auto stack = make_unique<StackArray<int>>();

  EXPECT_THROW(stack->pop(), underflow_error);
}

TEST(STACK_ARRAY, overflow)
{
  auto stack = make_unique<StackArray<int>>();

  for (int i = 1; i < 101; i++) {
    stack->push(i);
  }

  EXPECT_THROW(stack->push(0), overflow_error);
}

TEST(STACK_ARRAY, push_pop)
{
  auto stack = make_unique<StackArray<int>>();

  stack->push(1);
  stack->push(2);
  stack->push(3);

  EXPECT_EQ(3, stack->pop());
  EXPECT_EQ(2, stack->pop());
  EXPECT_EQ(1, stack->pop());
}

TEST(STACK_VECTOR, empty)
{
  auto stack = make_unique<StackVector<int>>();

  EXPECT_TRUE(stack->empty());

  stack->push(10);
  EXPECT_FALSE(stack->empty());
}

TEST(STACK_VECTOR, size)
{
  auto stack = make_unique<StackVector<int>>();

  EXPECT_EQ(0, stack->size());

  stack->push(1);
  stack->push(2);
  stack->pop();

  EXPECT_EQ(1, stack->size());
}

TEST(STACK_VECTOR, push_pop)
{
  auto stack = make_unique<StackVector<int>>();

  stack->push(1);
  stack->push(2);
  stack->push(3);

  EXPECT_EQ(3, stack->pop());
  EXPECT_EQ(2, stack->pop());
  EXPECT_EQ(1, stack->pop());
}

TEST(STACK_VECTOR, underflow)
{
  auto stack = make_unique<StackVector<int>>();

  EXPECT_THROW(stack->pop(), underflow_error);
}


