//
// Created by eduardo on 19.04.20.
//
#include "gtest/gtest.h"
#include <string>
#include "Queue.h"

TEST(QUEUE, EmptySize)
{
    auto queue = new Queue<string>();
    EXPECT_EQ(0, queue->getSize());
    delete queue;
}
