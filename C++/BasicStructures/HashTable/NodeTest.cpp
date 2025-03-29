#include <iostream>
#include <string>
#include "gtest/gtest.h"
#include "Node.h"

using std::string;

TEST(Node, getters)
{
	Node<int, string> node{1, "Cristo"};

  EXPECT_EQ(1, node.getKey());
  EXPECT_EQ("Cristo", node.getValue());
}

TEST(Node, setValue)
{
	Node<int, string> node{1, "A"};

	EXPECT_EQ(1, node.getKey());
	EXPECT_EQ("A", node.getValue());

	node.setValue("B");

	EXPECT_EQ("B", node.getValue());
}
