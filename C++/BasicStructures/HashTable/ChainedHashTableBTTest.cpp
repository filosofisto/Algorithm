#include <iostream>
#include <memory>
#include <string>
#include "gtest/gtest.h"
#include "ChainedHashTableBT.h"

using std::string;

TEST(ChainedHashTableBT, empty_true)
{
  auto map = ChainedHashTableBT<int, string, 10>{};

  EXPECT_TRUE(map.empty());
	EXPECT_EQ(0, map.size());
}

TEST(ChainedHashTableBT, empty_false)
{
  auto map = ChainedHashTableBT<int, string, 10>{};
	map.insert(1, "A");

  EXPECT_FALSE(map.empty());
	EXPECT_EQ(1, map.size());
}

TEST(ChainedHashTableBT, insert_with_collision)
{
  auto map = ChainedHashTableBT<int, string, 10>{};
	map.insert(1, "A");
	map.insert(11, "X");

  EXPECT_FALSE(map.empty());
	EXPECT_EQ(2, map.size());
	EXPECT_EQ(1, map.getInternalInfo().collisions);
}

TEST(ChainedHashTableBT, insert_with_replacement)
{
  auto map = ChainedHashTableBT<int, string, 10>{};
	map.insert(1, "A");
	map.insert(1, "B");

  EXPECT_FALSE(map.empty());
	EXPECT_EQ(1, map.size());
	EXPECT_EQ(1, map.getInternalInfo().replacements);
	EXPECT_EQ("B", map.search(1));
}

TEST(ChainedHashTableBT, remove_non_existent)
{
	auto map = ChainedHashTableBT<int, string, 10>{};
	map.insert(1, "A");
	map.remove(2);

	EXPECT_EQ(1, map.size());
	EXPECT_EQ("A", map.search(1));
}

TEST(ChainedHashTableBT, remove_existent)
{
	auto map = ChainedHashTableBT<int, string, 10>{};
	map.insert(1, "A");
	map.remove(1);

	EXPECT_EQ(0, map.size());
}
