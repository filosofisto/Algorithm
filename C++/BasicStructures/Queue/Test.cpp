#include <iostream>
#include <memory>
#include "gtest/gtest.h"
#include "QueueArray.h"
//#include "StackVector.h"

using std::unique_ptr;
using std::make_unique;
using std::underflow_error;
using std::overflow_error;

TEST(QUEUE_ARRAY, empty)
{
  auto queue = make_unique<QueueArray<int>>();

  EXPECT_TRUE(queue->empty());

  queue->enqueue(10);
  EXPECT_FALSE(queue->empty());
}

TEST(QUEUE_ARRAY, enqueue)
{
  auto queue = make_unique<QueueArray<int>>();
  queue->enqueue(1);
  queue->enqueue(2);
  queue->enqueue(3);

  EXPECT_EQ(3, queue->size());
}

TEST(QUEUE_ARRAY, dequeue)
{
  auto queue = make_unique<QueueArray<int>>();
  queue->enqueue(1);
  queue->enqueue(2);
  queue->enqueue(3);

  EXPECT_EQ(1, queue->dequeue());
  EXPECT_EQ(2, queue->size());
}

TEST(QUEUE_ARRAY, dequeue_underflow)
{
  auto queue = make_unique<QueueArray<int>>();
  
  EXPECT_THROW(queue->dequeue(), std::underflow_error);

  queue->enqueue(1);
  queue->enqueue(2);
  queue->dequeue();
  queue->dequeue();

  EXPECT_EQ(0, queue->size());
  EXPECT_THROW(queue->dequeue(), std::underflow_error);
}

TEST(QUEUE_ARRAY, enqueue_overflow)
{
  auto queue = make_unique<QueueArray<int>>();
  
  for (int i = 0; i < 100; i++) {
    queue->enqueue(i);
  }

  EXPECT_THROW(queue->enqueue(100), std::overflow_error);
}
