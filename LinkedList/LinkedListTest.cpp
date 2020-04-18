//
// Created by eduardo on 12.04.20.
//
#include "gtest/gtest.h"
#include "LinkedList.h"

TEST(LINKEDLIST, EmptySize)
{
    auto list = new LinkedList<int>();
    EXPECT_EQ(0, list->getSize());
    delete list;
}

TEST(LINKEDLIST, Empty)
{
    auto list = new LinkedList<int>();
    EXPECT_TRUE(list->empty());
    list->add(1);
    EXPECT_FALSE(list->empty());
    delete list;
}

TEST(LINKEDLIST, Add)
{
    auto list = new LinkedList<int>();

    list->add(1);
    EXPECT_FALSE(list->empty());
    EXPECT_TRUE(list->contains(1));
    EXPECT_FALSE(list->contains(2));

    delete list;
}

TEST(LINKEDLIST, Remove)
{
    auto list = new LinkedList<int>();

    list->add(1);
    EXPECT_EQ(1, list->getSize());

    list->remove(2);
    EXPECT_EQ(1, list->getSize());

    list->remove(1);
    EXPECT_EQ(0, list->getSize());

    delete list;
}

TEST(LINKEDLIST, Contains)
{
    auto list = new LinkedList<int>();

    list->add(1);

    EXPECT_TRUE(list->contains(1));
    EXPECT_FALSE(list->contains(2));

    delete list;
}

TEST(LINKEDLIST, Search)
{
    auto list = new LinkedList<int>();

    list->add(1);

    EXPECT_EQ(list->search(1), 1);

    auto listString = new LinkedList<string>();
    listString->add("Eduardo")->add("Djovana")->add("Hiago")->add("Hanna");
    EXPECT_EQ(listString->search("Hiago"), "Hiago");

    delete list;
}

