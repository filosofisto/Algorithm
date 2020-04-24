//
// Created by eduardo on 12.04.20.
//
#include "gtest/gtest.h"
#include "LinkedList.h"

TEST(LINKEDLIST, EmptySize)
{
    auto list = new LinkedList<int>();
    EXPECT_EQ(0, list->getSize());
}

TEST(LINKEDLIST, Empty)
{
    auto list = new LinkedList<int>();
    EXPECT_TRUE(list->empty());
    list->add(new int(1));
    EXPECT_FALSE(list->empty());
}

TEST(LINKEDLIST, Add)
{
    auto list = new LinkedList<int>();

    int* one = new int(1);
    int* two = new int(2);

    list->add(one);
    EXPECT_FALSE(list->empty());
    EXPECT_TRUE(list->contains(one));
    EXPECT_FALSE(list->contains(two));
}

TEST(LINKEDLIST, Remove)
{
    auto list = new LinkedList<int>();

    int* one = new int(1);
    list->add(one);
    EXPECT_EQ(1, list->getSize());

    list->remove(new int(2));
    EXPECT_EQ(1, list->getSize());

    list->remove(one);
    EXPECT_EQ(0, list->getSize());
}

TEST(LINKEDLIST, Contains)
{
    auto list = new LinkedList<int>();

    int* one = new int(1);
    list->add(one);

    EXPECT_TRUE(list->contains(one));
    EXPECT_FALSE(list->contains(new int(2)));
}

TEST(LINKEDLIST, Search)
{
    auto list = new LinkedList<int>();

    int* one = new int(1);
    list->add(one);

    EXPECT_EQ(list->search(one), 1);
}

