#include <iostream>
#include <memory>
#include "gtest/gtest.h"
#include "IterativeBinaryTree.h"

TEST(IterativeBinaryTree, empty_true)
{
  IterativeBinaryTree<int> tree{};

  EXPECT_TRUE(tree.empty());
}

TEST(IterativeBinaryTree, size_zero)
{
  IterativeBinaryTree<int> tree{};

  EXPECT_EQ(0, tree.size());
}

TEST(IterativeBinaryTree, empty_false)
{
  IterativeBinaryTree<int> tree{};
	tree.insert(10);

  EXPECT_FALSE(tree.empty());
}

TEST(IterativeBinaryTree, size_non_zero)
{
  IterativeBinaryTree<int> tree{};
	tree.insert(10);

  EXPECT_EQ(1, tree.size());
}

TEST(IterativeBinaryTree, search_non_existent)
{
  IterativeBinaryTree<int> tree{};
	tree.insert(10);

  EXPECT_FALSE(tree.search(12));
}

TEST(IterativeBinaryTree, search_existent)
{
  IterativeBinaryTree<int> tree{};
	tree.insert(10);
	tree.insert(5);
	tree.insert(15);

	auto node = tree.search(15);

  EXPECT_TRUE(node);
	EXPECT_EQ(15, node->getData());
}

TEST(IterativeBinaryTree, min_existent)
{
  IterativeBinaryTree<int> tree{};
	tree.insert(10);
	tree.insert(5);
	tree.insert(15);

	auto node = tree.min();

  EXPECT_TRUE(node);
	EXPECT_EQ(5, node->getData());
}

TEST(IterativeBinaryTree, min_empty)
{
  IterativeBinaryTree<int> tree{};

  EXPECT_FALSE(tree.min());
}

TEST(IterativeBinaryTree, max_existent)
{
  IterativeBinaryTree<int> tree{};
	tree.insert(10);
	tree.insert(5);
	tree.insert(15);

	auto node = tree.max();

  EXPECT_TRUE(node);
	EXPECT_EQ(15, node->getData());
}

TEST(IterativeBinaryTree, max_empty)
{
  IterativeBinaryTree<int> tree{};

  EXPECT_FALSE(tree.max());
}

TEST(IterativeBinaryTree, sucessor_existent)
{
  IterativeBinaryTree<int> tree{};
	tree.insert(10);
	tree.insert(5);
	tree.insert(15);

	auto nodeBase = tree.search(5);
	auto node = tree.sucessor(nodeBase);

  EXPECT_TRUE(node);
	EXPECT_EQ(10, node->getData());
}

TEST(IterativeBinaryTree, sucessor_non_existent)
{
  IterativeBinaryTree<int> tree{};
	tree.insert(10);
	tree.insert(5);
	tree.insert(15);

	auto node = tree.sucessor(tree.max());

  EXPECT_FALSE(node);
}

TEST(IterativeBinaryTree, predecessor_existent)
{
  IterativeBinaryTree<int> tree{};
	tree.insert(10);
	tree.insert(5);
	tree.insert(15);

	auto nodeBase = tree.search(15);
	EXPECT_TRUE(nodeBase);

	auto node = tree.predecessor(nodeBase);

  EXPECT_TRUE(node);
	EXPECT_EQ(10, node->getData());
}

TEST(IterativeBinaryTree, predecessor_non_existent)
{
  IterativeBinaryTree<int> tree{};
	tree.insert(10);
	tree.insert(5);
	tree.insert(15);

	auto node = tree.predecessor(tree.min());

  EXPECT_FALSE(node);
}

TEST(IterativeBinaryTree, remove_empty)
{
	IterativeBinaryTree<int> tree{};

	EXPECT_FALSE(tree.remove(10));
}

TEST(IterativeBinaryTree, remove_non_existent)
{
	IterativeBinaryTree<int> tree{};
	tree.insert(10);
	tree.insert(20);
	tree.insert(30);

	EXPECT_FALSE(tree.remove(15));
}

TEST(IterativeBinaryTree, remove_existent)
{
	IterativeBinaryTree<int> tree{};
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

TEST(IterativeBinaryTree, remove_root)
{
	IterativeBinaryTree<int> tree{};
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

TEST(IterativeBinaryTree, remove_complex)
{
	IterativeBinaryTree<int> tree{};
	tree.insert(10);
	tree.insert(7);
	tree.insert(12);
	tree.insert(5);
	tree.insert(9);
	tree.insert(11);
	tree.insert(13);

	EXPECT_TRUE(tree.remove(7));
	EXPECT_FALSE(tree.search(7));
	EXPECT_TRUE(tree.search(5));
	EXPECT_TRUE(tree.search(9));
}
