#ifndef __CHAINED_HASHTABLE__
#define __CHAINED_HASHTABLE__

#include <array>
#include <memory>
#include "HashTable.h"
#include "LinkedList.h"
#include "DefaultHasher.h"

using std::array;
using std::move;
using std::unique_ptr;
using std::make_unique;
using std::overflow_error;
using std::underflow_error;
using std::size_t;
using std::hash;

template <typename K, typename T, size_t N, typename Hasher = DefaultHasher<K>>
class ChainedHashTable : public HashTable<K,T>
{
  public:
    ChainedHashTable();
    virtual ~ChainedHashTable() override = default;

    ChainedHashTable(const ChainedHashTable&) = delete;
    ChainedHashTable& operator=(const ChainedHashTable&) = delete;
    ChainedHashTable(ChainedHashTable&&) = delete;
    ChainedHashTable& operator=(ChainedHashTable&&) = delete;

    T search(const K& key) const override;
    void insert(const K& key, const T& element) override;
    void remove(const K& key) override;
    size_t size() const override;
    bool empty() const override;
		HashTableInternalInfo getInternalInfo() const override;

  private:
		size_t getBucket(const K& key) const;
    array<unique_ptr<LinkedList<K,T>>, N> elements;
    int count;
		HashTableInternalInfo internalInfo;
};

template <typename K, typename T, size_t N, typename Hasher>
ChainedHashTable<K,T,N, Hasher>::ChainedHashTable() : count(0)
{
	internalInfo.collisions = 0;
	internalInfo.replacements = 0;
}
 
template <typename K, typename T, size_t N, typename Hasher>
T ChainedHashTable<K,T,N,Hasher>::search(const K& key) const
{
	auto hashValue = Hasher{}(key);
	auto bucket = hashValue % N;

	if (elements[bucket] != nullptr) {
		auto node_ptr = elements[bucket]->searchByKey(key);
		if (node_ptr != nullptr) {
			return node_ptr->getValue();
		}
	}

  return nullptr;
}

template <typename K, typename T, size_t N, typename Hasher>
size_t ChainedHashTable<K,T,N,Hasher>::getBucket(const K& key) const
{
	// Calculate the key hash
	auto hashValue = Hasher{}(key);
	
	// Calculate the bucket
	return hashValue % N;
}

template <typename K, typename T, size_t N, typename Hasher>
void ChainedHashTable<K,T,N,Hasher>::insert(const K& key, const T& data) 
{
	auto bucket = getBucket(key);

	// Create the LinkedList if it does not exist
	if (elements[bucket] == nullptr) {
		elements[bucket] = make_unique<LinkedList<K,T>>();
	} else {
		internalInfo.collisions++; // collision
	}

	auto& list = elements[bucket];

	// Search by key to check if already exists an item with this key, in this case replace it
	auto existentData = list->searchByKey(key);
	
	if (existentData != nullptr) {
		existentData->setValue(data);
		internalInfo.replacements++;		
	} else {
		// Prepend the new element on LinkedList
  	elements[bucket]->prepend(key, data);
  	++count;
	}
}
 
template <typename K, typename T, size_t N, typename Hasher>
void ChainedHashTable<K,T,N,Hasher>::remove(const K& key)
{
	auto bucket = getBucket(key);

	if (elements[bucket] == nullptr) return;

	if (elements[bucket]->removeByKey(key)) {
		--count;
	} 
} 

template <typename K, typename T, size_t N, typename Hasher>
size_t ChainedHashTable<K,T,N,Hasher>::size() const
{
  return static_cast<size_t>(count);
}
 
template <typename K, typename T, size_t N, typename Hasher>
bool ChainedHashTable<K,T,N,Hasher>::empty() const
{
  return count == 0;
}

template <typename K, typename T, size_t N, typename Hasher>
HashTableInternalInfo ChainedHashTable<K,T,N,Hasher>::getInternalInfo() const
{
	return internalInfo;
}
#endif
