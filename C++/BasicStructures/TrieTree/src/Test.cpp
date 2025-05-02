#include <iostream>
#include <algorithm>
#include "gtest/gtest.h"
#include "TrieTree.h"

using std::find;

TEST(TrieTree, insert)
{
  TrieTree tree{};

	tree.insert("toy");

	EXPECT_EQ(3, tree.size());
}

TEST(TrieTree, searchByKey_empty)
{
  TrieTree tree{};

	tree.insert("toy");

	EXPECT_FALSE(tree.searchByKey("x"));
}

TEST(TrieTree, searchByKey_non_empty)
{
  TrieTree tree{};

	tree.insert("toy");

	EXPECT_TRUE(tree.searchByKey("t"));
	EXPECT_TRUE(tree.searchByKey("to"));
	EXPECT_TRUE(tree.searchByKey("toy"));
}

TEST(TrieTree, typeahead_empty)
{
	TrieTree tree{};

	auto result = tree.typeahead("a", 3);

	EXPECT_TRUE(result.empty());
}

TEST(TrieTree, typeahead_not_empty)
{
	TrieTree tree{};

	for (int i{0}; i < 10; ++i) {
		tree.insert("tree");
	}
	for (int i{0}; i < 20; ++i) {
		tree.insert("true");
	}
	for (int i{0}; i < 15; ++i) {
		tree.insert("try");
	}

	auto result = tree.typeahead("tr", 3);

	EXPECT_EQ(3, result.size());

	auto it = find(result.begin(), result.end(), "tree");
	EXPECT_NE(it, result.end());
	it = find(result.begin(), result.end(), "true");
	EXPECT_NE(it, result.end());
	it = find(result.begin(), result.end(), "try");
	EXPECT_NE(it, result.end());

	EXPECT_EQ("true", result[0]);
	EXPECT_EQ("try", result[1]);
	EXPECT_EQ("tree", result[2]);
}
