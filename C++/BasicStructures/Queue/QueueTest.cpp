//
// Created by eduardo on 19.04.20.
//
#include "gtest/gtest.h"
#include "Queue.h"

TEST(QUEUE, Size)
{
    auto queue = new Queue<int>();
    EXPECT_EQ(0, queue->getSize());
    queue->enqueue(new int(1));
    EXPECT_NE(0, queue->getSize());
}

TEST(QUEUE, Empty)
{
    auto queue = new Queue<int>();
    EXPECT_TRUE(queue->empty());
    queue->enqueue(new int(1));
    EXPECT_FALSE(queue->empty());
}

TEST(QUEUE, enqueue_dequeue)
{
    auto queue = new Queue<int>();
    queue->enqueue(new int(1));
    queue->enqueue(new int(2));
    EXPECT_EQ(1, *queue->dequeue());
    EXPECT_EQ(2, *queue->dequeue());
    EXPECT_TRUE(queue->empty());
    EXPECT_EQ(0, queue->getSize());
}
