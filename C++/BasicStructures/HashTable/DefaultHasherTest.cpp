#include <iostream>
#include <string>
#include "gtest/gtest.h"
#include "DefaultHasher.h"

using std::cout;
using std::hash;
using std::string;

TEST(DefaultHasher, int)
{
	auto hasher = DefaultHasher<int>{};
	auto hashValue = hasher(10);
	auto hashFn = hash<int>{};

	EXPECT_EQ(hashFn(10), hashValue);
}

TEST(DefaultHasher, string)
{
	auto hasher = DefaultHasher<string>{};
	auto hashValue = hasher("This is a sample text");
	auto hashFn = hash<string>{};

	EXPECT_EQ(hashFn("This is a sample text"), hashValue);
}
