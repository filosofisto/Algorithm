#ifndef __CHAINED_HASHTABLE_BT__
#define __CHAINED_HASHTABLE_BT__

#include <array>
#include <memory>
#include "HashTable.h"
#include "BinaryTree.h"
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
class ChainedHashTableBT : public HashTable<K,T>
{
  public:
    ChainedHashTableBT();
    virtual ~ChainedHashTableBT() override = default;

    ChainedHashTableBT(const ChainedHashTableBT&) = delete;
    ChainedHashTableBT& operator=(const ChainedHashTableBT&) = delete;
    ChainedHashTableBT(ChainedHashTableBT&&) = delete;
    ChainedHashTableBT& operator=(ChainedHashTableBT&&) = delete;

    T search(const K& key) const override;
    void insert(const K& key, const T& data) override;
    void remove(const K& key) override;
    size_t size() const override;
    bool empty() const override;
		HashTableInternalInfo getInternalInfo() const override;

  private:
		size_t getBucket(const K& key) const;
    array<unique_ptr<BinaryTree<K,T>>, N> elements;
    int count;
		HashTableInternalInfo internalInfo;
};

template <typename K, typename T, size_t N, typename Hasher>
ChainedHashTableBT<K,T,N, Hasher>::ChainedHashTableBT() : count(0)
{
	internalInfo.collisions = 0;
	internalInfo.replacements = 0;
}
 
template <typename K, typename T, size_t N, typename Hasher>
T ChainedHashTableBT<K,T,N,Hasher>::search(const K& key) const
{
	auto bucket = getBucket(key);

	if (elements[bucket] != nullptr) {
		auto node_ptr = elements[bucket]->search(key);
		if (node_ptr != nullptr) {
			return node_ptr->getData();
		}
	}

  return nullptr;
}

template <typename K, typename T, size_t N, typename Hasher>
size_t ChainedHashTableBT<K,T,N,Hasher>::getBucket(const K& key) const
{
	// Calculate the key hash
	auto hashValue = Hasher{}(key);
	
	// Calculate the bucket
	return hashValue % N;
}

template <typename K, typename T, size_t N, typename Hasher>
void ChainedHashTableBT<K,T,N,Hasher>::insert(const K& key, const T& data) 
{
	auto bucket = getBucket(key);

	// Create the BinaryTree if it does not exist
	if (elements[bucket] == nullptr) {
		elements[bucket] = make_unique<BinaryTree<K,T>>();
	} else {
		internalInfo.collisions++; // collision
	}

	auto& tree = elements[bucket];

	// Search by key to check if already exists an item with this key, in this case replace it
	auto existentData = tree->search(key);
	
	if (existentData != nullptr) {
		existentData->setData(data);
		internalInfo.replacements++;		
	} else {
  	// insert it into tree
		tree->insert(key, data);
  	++count;
	}
}
 
template <typename K, typename T, size_t N, typename Hasher>
void ChainedHashTableBT<K,T,N,Hasher>::remove(const K& key)
{
	auto bucket = getBucket(key);

	if (elements[bucket] == nullptr) return;

	if (elements[bucket]->remove(key)) {
		--count;
	} 
} 

template <typename K, typename T, size_t N, typename Hasher>
size_t ChainedHashTableBT<K,T,N,Hasher>::size() const
{
  return static_cast<size_t>(count);
}
 
template <typename K, typename T, size_t N, typename Hasher>
bool ChainedHashTableBT<K,T,N,Hasher>::empty() const
{
  return count == 0;
}

template <typename K, typename T, size_t N, typename Hasher>
HashTableInternalInfo ChainedHashTableBT<K,T,N,Hasher>::getInternalInfo() const
{
	return internalInfo;
}
#endif
