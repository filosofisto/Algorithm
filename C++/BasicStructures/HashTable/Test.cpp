#include <iostream>
#include <memory>
#include "gtest/gtest.h"
#include "HashTable.h"
#include "DirectAdressHashTable.h"

using std::overflow_error;
using std::underflow_error;

TEST(DirectAdressHashTable, empty_true)
{
  DirectAddressHashTable<int, int, 10> hashTable;

  EXPECT_TRUE(hashTable.empty());
}

TEST(DirectAdressHashTable, empty_false)
{
  DirectAddressHashTable<int, int, 10> hashTable;
  hashTable.insert(0, 1000);

  EXPECT_FALSE(hashTable.empty());
}

TEST(DirectAdressHashTable, empty_after_delete_last_element)
{
  DirectAddressHashTable<int, int, 10> hashTable;
  hashTable.insert(0, 1000);
  hashTable.remove(0);

  EXPECT_TRUE(hashTable.empty());
}

TEST(DirectAdressHashTable, size_zero)
{
  DirectAddressHashTable<int, int, 10> hashTable;

  EXPECT_EQ(0, hashTable.size());
}

TEST(DirectAdressHashTable, size_non_zero)
{
  DirectAddressHashTable<int, int, 10> hashTable;
  hashTable.insert(0, 1000);

  EXPECT_EQ(1, hashTable.size());
}

TEST(DirectAdressHashTable, insert_overflow)
{
  DirectAddressHashTable<int, int, 2> hashTable;
  hashTable.insert(0, 1);
  hashTable.insert(1, 2);

  EXPECT_THROW(hashTable.insert(2, 3), overflow_error);
}

TEST(DirectAdressHashTable, insert_underflow)
{
  DirectAddressHashTable<int, int, 2> hashTable;

  EXPECT_THROW(hashTable.insert(-1, 1), underflow_error);
}

TEST(DirectAdressHashTable, remove_existent)
{
  DirectAddressHashTable<int, int, 2> hashTable;
  hashTable.insert(0, 1);
  hashTable.insert(1, 2);

  hashTable.remove(0);

  EXPECT_EQ(1, hashTable.size());

  hashTable.remove(1);
  EXPECT_EQ(0, hashTable.size());
}

TEST(DirectAdressHashTable, remove_non_existent)
{
  DirectAddressHashTable<int, int, 10> hashTable;
  hashTable.insert(0, 1);
  hashTable.insert(1, 2);

  hashTable.remove(9);

  EXPECT_EQ(2, hashTable.size());
}

TEST(DirectAdressHashTable, remove_overflow)
{
  DirectAddressHashTable<int, int, 10> hashTable;

  EXPECT_THROW(hashTable.remove(11), overflow_error);
}

TEST(DirectAdressHashTable, remove_underflow)
{
  DirectAddressHashTable<int, int, 10> hashTable;

  EXPECT_THROW(hashTable.remove(-1), underflow_error);
}

