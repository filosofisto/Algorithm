#include <iostream>
#include <string>
#include "gtest/gtest.h"
#include "LinkedListNode.h"

using std::string;

TEST(LinkedListNode, getters)
{
	LinkedListNode<int, string> node{1, string("Cristo")};

  EXPECT_EQ(1, node.getKey());
  EXPECT_EQ("Cristo", node.getValue());
}

TEST(LinkedListNode, setValue)
{
	LinkedListNode<int, string> node{1, string("A")};

	EXPECT_EQ(1, node.getKey());
	EXPECT_EQ("A", node.getValue());

	node.setValue("B");

	EXPECT_EQ("B", node.getValue());
}
