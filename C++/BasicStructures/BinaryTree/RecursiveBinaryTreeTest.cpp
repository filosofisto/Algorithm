#include <iostream>
#include <memory>
#include "gtest/gtest.h"
#include "RecursiveBinaryTree.h"

TEST(RecursiveBinaryTree, empty_true)
{
  RecursiveBinaryTree<int> tree{};

  EXPECT_TRUE(tree.empty());
}

TEST(RecursiveBinaryTree, size_zero)
{
  RecursiveBinaryTree<int> tree{};

  EXPECT_EQ(0, tree.size());
}

TEST(RecursiveBinaryTree, empty_false)
{
  RecursiveBinaryTree<int> tree{};
	tree.insert(10);

  EXPECT_FALSE(tree.empty());
}

TEST(RecursiveBinaryTree, size_non_zero)
{
  RecursiveBinaryTree<int> tree{};
	tree.insert(10);

  EXPECT_EQ(1, tree.size());
}

TEST(RecursiveBinaryTree, search_non_existent)
{
  RecursiveBinaryTree<int> tree{};
	tree.insert(10);

  EXPECT_FALSE(tree.search(12));
}

TEST(RecursiveBinaryTree, search_existent)
{
  RecursiveBinaryTree<int> tree{};
	tree.insert(10);
	tree.insert(5);
	tree.insert(15);

	auto node = tree.search(15);

  EXPECT_TRUE(node);
	EXPECT_EQ(15, node->getData());
}

TEST(RecursiveBinaryTree, min_existent)
{
  RecursiveBinaryTree<int> tree{};
	tree.insert(10);
	tree.insert(5);
	tree.insert(15);

	auto node = tree.min();

  EXPECT_TRUE(node);
	EXPECT_EQ(5, node->getData());
}

TEST(RecursiveBinaryTree, min_empty)
{
  RecursiveBinaryTree<int> tree{};

  EXPECT_FALSE(tree.min());
}

TEST(RecursiveBinaryTree, max_existent)
{
  RecursiveBinaryTree<int> tree{};
	tree.insert(10);
	tree.insert(5);
	tree.insert(15);

	auto node = tree.max();

  EXPECT_TRUE(node);
	EXPECT_EQ(15, node->getData());
}

TEST(RecursiveBinaryTree, max_empty)
{
  RecursiveBinaryTree<int> tree{};

  EXPECT_FALSE(tree.max());
}

TEST(RecursiveBinaryTree, sucessor_existent)
{
  RecursiveBinaryTree<int> tree{};
	tree.insert(10);
	tree.insert(5);
	tree.insert(15);

	auto nodeBase = tree.search(5);
	auto node = tree.sucessor(nodeBase);

  EXPECT_TRUE(node);
	EXPECT_EQ(10, node->getData());
}

TEST(RecursiveBinaryTree, sucessor_non_existent)
{
  RecursiveBinaryTree<int> tree{};
	tree.insert(10);
	tree.insert(5);
	tree.insert(15);

	auto node = tree.sucessor(tree.max());

  EXPECT_FALSE(node);
}

TEST(RecursiveBinaryTree, predecessor_existent)
{
  RecursiveBinaryTree<int> tree{};
	tree.insert(10);
	tree.insert(5);
	tree.insert(15);

	auto nodeBase = tree.search(15);
	EXPECT_TRUE(nodeBase);

	auto node = tree.predecessor(nodeBase);

  EXPECT_TRUE(node);
	EXPECT_EQ(10, node->getData());
}

TEST(RecursiveBinaryTree, predecessor_non_existent)
{
  RecursiveBinaryTree<int> tree{};
	tree.insert(10);
	tree.insert(5);
	tree.insert(15);

	auto node = tree.predecessor(tree.min());

  EXPECT_FALSE(node);
}

TEST(RecursiveBinaryTree, remove_empty)
{
	RecursiveBinaryTree<int> tree{};

	EXPECT_FALSE(tree.remove(10));
}

TEST(RecursiveBinaryTree, remove_non_existent)
{
	RecursiveBinaryTree<int> tree{};
	tree.insert(10);
	tree.insert(20);
	tree.insert(30);

	EXPECT_FALSE(tree.remove(15));
}

TEST(RecursiveBinaryTree, remove_existent)
{
	RecursiveBinaryTree<int> tree{};
	tree.insert(10);
	tree.insert(20);
	tree.insert(30);

	EXPECT_EQ(3, tree.size());
	EXPECT_TRUE(tree.remove(30));
	EXPECT_EQ(2, tree.size());

	auto ten = tree.search(10);
	EXPECT_TRUE(ten);
	EXPECT_EQ(10, ten->getData());

	auto twenty = tree.search(20);
	EXPECT_TRUE(twenty);
	EXPECT_EQ(20, twenty->getData());
}

TEST(RecursiveBinaryTree, remove_root)
{
	RecursiveBinaryTree<int> tree{};
	tree.insert(10);
	tree.insert(20);
	tree.insert(30);

	auto root = tree.getRoot();
	EXPECT_TRUE(root);
	EXPECT_EQ(10, root->getData());

	EXPECT_EQ(3, tree.size());
	EXPECT_TRUE(tree.remove(10));
	EXPECT_EQ(2, tree.size());

	auto twenty = tree.search(20);
	EXPECT_TRUE(twenty);
	EXPECT_EQ(20, twenty->getData());

	auto thirty = tree.search(30);
	EXPECT_TRUE(thirty);
	EXPECT_EQ(30, thirty->getData());

	root = tree.getRoot();
	EXPECT_TRUE(root);
	EXPECT_NE(10, root->getData());
}

TEST(RecursiveBinaryTree, remove_complex)
{
	RecursiveBinaryTree<int> tree{};
	tree.insert(10);
	tree.insert(7);
	tree.insert(12);
	tree.insert(5);
	tree.insert(9);
	tree.insert(11);
	tree.insert(13);

	EXPECT_TRUE(tree.remove(7));
	//EXPECT_FALSE(tree.search(7));
	//EXPECT_TRUE(tree.search(5));
	//EXPECT_TRUE(tree.search(9));
}
