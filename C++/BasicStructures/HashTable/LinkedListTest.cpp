#include <iostream>
#include <memory>
#include <string>
#include "gtest/gtest.h"
#include "LinkedList.h"

using std::string;

TEST(LinkedList, empty_true)
{
  auto list = LinkedList<int, string>{};

  EXPECT_TRUE(list.empty());
}

TEST(LinkedList, empty_false)
{
  auto list = LinkedList<int, string>{};
  list.prepend(1, "A");

  EXPECT_FALSE(list.empty());
}

TEST(LinkedList, size_empty)
{
  auto list = LinkedList<int, string>{};

  EXPECT_EQ(0, list.size());
}

TEST(LinkedList, size_non_empty)
{
  auto list = LinkedList<int, string>{};
  list.prepend(1, "A");
  list.prepend(2, "B");

  EXPECT_EQ(2, list.size());
}

TEST(LinkedList, search_not_found)
{
  auto list = LinkedList<int, string>{};
  list.prepend(1, "A");
  list.prepend(2, "B");

  auto found = list.search("C");

  EXPECT_EQ(nullptr, found);
}

TEST(LinkedList, remove_existent)
{
  auto list = LinkedList<int, string>{};
  list.prepend(1, "A");
  list.prepend(2, "B");
  list.prepend(3, "C");
  list.prepend(4, "D");
  
  list.removeByKey(3);
  auto found = list.searchByKey(3);
  
	EXPECT_EQ(nullptr, found);
  EXPECT_EQ(3, list.size());
}

TEST(LinkedList, remove_non_existent)
{
  auto list = LinkedList<int, string>{};
  list.prepend(1, "A");
  list.prepend(2, "B");
  list.prepend(3, "C");
  list.prepend(4, "D");
  
  list.remove("X");
  
	EXPECT_EQ(4, list.size());
}

TEST(LinkedList, first)
{
  auto list = LinkedList<int, string>{};
  list.prepend(2, "B");
  list.prepend(1, "A");
  
	auto node_ptr = list.first();
	EXPECT_TRUE(node_ptr);
	
	LinkedListNode<int, string>& node = *node_ptr;
  EXPECT_EQ(1, node.getKey());
	EXPECT_EQ("A", node.getValue());
}

TEST(LinkedList, first_empty)
{
  auto list = LinkedList<int, string>{};
  
  EXPECT_FALSE(list.first());
}

TEST(LinkedList, last)
{
  auto list = LinkedList<int, string>{};
  list.prepend(2, "B");
  list.prepend(1, "A");
  
	auto node_ptr = list.last();
	EXPECT_TRUE(node_ptr);

	LinkedListNode<int, string>& node = *node_ptr;
  EXPECT_EQ(2, node.getKey());
	EXPECT_EQ("B", node.getValue());
}

TEST(LinkedList, last_empty)
{
  auto list = LinkedList<int, string>{};
  
  EXPECT_FALSE(list.last());
}


