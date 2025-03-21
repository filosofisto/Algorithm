#include <iostream>
#include <memory>
#include "gtest/gtest.h"
#include "LinkedList.h"

using std::unique_ptr;
using std::make_unique;

TEST(LinkedList, empty_true)
{
  auto list = make_unique<LinkedList<int>>();

  EXPECT_TRUE(list->empty());
}

TEST(LinkedList, empty_false)
{
  auto list = make_unique<LinkedList<int>>();
  list->prepend(1);

  EXPECT_FALSE(list->empty());
}

TEST(LinkedList, size_empty)
{
  auto list = make_unique<LinkedList<int>>();

  EXPECT_EQ(0, list->size());
}

TEST(LinkedList, size_non_empty)
{
  auto list = make_unique<LinkedList<int>>();
  list->prepend(1);
  list->prepend(2);

  EXPECT_EQ(2, list->size());
}

TEST(LinkedList, search_not_found)
{
  auto list = make_unique<LinkedList<int>>();
  list->prepend(1);
  list->prepend(2);

  auto found = list->search(3);

  EXPECT_EQ(nullptr, found);
}

TEST(LinkedList, remove_existent)
{
  auto list = make_unique<LinkedList<int>>();
  list->prepend(1);
  list->prepend(2);
  list->prepend(3);
  list->prepend(4);
  
  list->remove(3);
  auto found = list->search(3);
  EXPECT_EQ(nullptr, found);
  EXPECT_EQ(3, list->size());
}

TEST(LinkedList, remove_non_existent)
{
  auto list = make_unique<LinkedList<int>>();
  list->prepend(1);
  list->prepend(2);
  list->prepend(3);
  list->prepend(4);
  
  list->remove(5);
  EXPECT_EQ(4, list->size());
}

TEST(LinkedList, first)
{
  auto list = make_unique<LinkedList<int>>();
  list->prepend(2);
  list->prepend(1);
  
  EXPECT_EQ(1, (*list->first()).data());

}

TEST(LinkedList, first_empty)
{
  auto list = make_unique<LinkedList<int>>();
  
  EXPECT_EQ(nullptr, list->first());
}


TEST(LinkedList, last)
{
  auto list = make_unique<LinkedList<int>>();
  list->prepend(2);
  list->prepend(1);
  
  EXPECT_EQ(2, (*list->last()).data());
}

TEST(LinkedList, last_empty)
{
  auto list = make_unique<LinkedList<int>>();
  
  EXPECT_EQ(nullptr, list->last());
}
