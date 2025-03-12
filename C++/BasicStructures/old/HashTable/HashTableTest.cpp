//
// Created by eduardo on 12.04.20.
//
#include "gtest/gtest.h"
#include "HashTable.h"
#include "Person.h"

TEST(HASHTABLE, EmptySize)
{
    auto hashTable = new HashTable<string, Person>();
    EXPECT_EQ(0, hashTable->getSize());

    hashTable->put(new string("Eduardo"), new Person("Eduardo"));
    EXPECT_NE(0, hashTable->getSize());
}

TEST(HASHTABLE, Put)
{
    auto hashTable = new HashTable<string, Person>();

    hashTable->put(new string("Eduardo"), new Person("Eduardo"));
    EXPECT_EQ(1, hashTable->getSize());
}

TEST(HASHTABLE, Remove)
{
    auto hashTable = new HashTable<string, Person>();

    hashTable->put(new string("Eduardo"), new Person("Eduardo"));
    hashTable->remove(new string("Eduardo"));
    EXPECT_TRUE(hashTable->empty());
}

TEST(HASHTABLE, Get)
{
    auto hashTable = new HashTable<string, Person>();

    hashTable->put(new string("Eduardo"), new Person("Eduardo", 48));

    auto node = hashTable->get(new string("Eduardo"));
    EXPECT_NE(nullptr, node);

    auto person = node->data();
    EXPECT_EQ("Eduardo", person->getName());
    EXPECT_EQ(48, person->getAge());
}

TEST(HASHTABLE, CollisionBySameKey)
{
    auto hashTable = new HashTable<string, Person>();

    hashTable->put(new string("Eduardo"), new Person("Eduardo", 48));
    hashTable->put(new string("Eduardo"), new Person("Eduardo", 30));

    auto node = hashTable->get(new string("Eduardo"));
    EXPECT_NE(nullptr, node);

    auto person = node->data();
    EXPECT_EQ(1, hashTable->getSize());
    EXPECT_EQ(30, person->getAge());
}

//
// Function to calculate a fix hash code to aim force a collision with different keys
//
size_t forceCollision(string* key) {
    return 1;
}

TEST(HASHTABLE, CollisionByDifferentKey)
{
    auto hashTable = new HashTable<string, Person>();
    hashTable->setHashCalculator(&forceCollision);

    hashTable->put(new string("X"), new Person("Eduardo X", 48));
    hashTable->put(new string("Y"), new Person("Eduardo Y", 30));

    // Size 2 due to different keys
    EXPECT_EQ(2, hashTable->getSize());

    auto node = hashTable->get(new string("X"));
    EXPECT_NE(nullptr, node);
    auto person = node->data();
    EXPECT_EQ("Eduardo X", person->getName());
    EXPECT_EQ(48, person->getAge());

    node = hashTable->get(new string("Y"));
    EXPECT_NE(nullptr, node);
    person = node->data();
    EXPECT_EQ("Eduardo Y", person->getName());
    EXPECT_EQ(30, person->getAge());
}

