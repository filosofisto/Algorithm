#ifndef __CHAINED_HASHTABLE__
#define __CHAINED_HASHTABLE__

#include <array>
#include <memory>
#include "HashTable.h"
#include "LinkedList.h"

using std::array;
using std::move;
using std::unique_ptr;
using std::make_unique;
using std::overflow_error;
using std::underflow_error;

template <typename K, typename T, int N>
class ChainedHashTable : public HashTable<K,T>
{
  public:
    ChainedHashTable();
    virtual ~ChainedHashTable() override = default;

    ChainedHashTable(const ChainedHashTable&) = delete;
    ChainedHashTable& operator=(const ChainedHashTable&) = delete;
    ChainedHashTable(ChainedHashTable&&) = delete;
    ChainedHashTable& operator=(ChainedHashTable&&) = delete;

    T* search(const K& key) const override;
    void insert(const K& key, T&& element) override;
    void remove(const K& key) override;
    size_t size() const override;
    bool empty() const override;

  private:
    array<unique_ptr<T>, N> elements;
    int count;
};

template <typename K, typename T, int N>
ChainedHashTable<K,T,N>::ChainedHashTable() : count(0)
{
  for (int i = 0; i < N; ++i) {
    elements[i] = nullptr;
  }
}
 
template <typename K, typename T, int N>
T* ChainedHashTable<K,T,N>::search(const K& key) const
{
  return elements[key].get();
}
 
template <typename K, typename T, int N>
void ChainedHashTable<K,T,N>::insert(const K& key, T&& element) 
{
  if (key < 0) {
    throw underflow_error{ "Underflow on min element, should be ZERO" };
  }

  if (key > N-1) {
    throw overflow_error{ "Overflow on max capacity" };
  }

  elements[key] = make_unique<T>(move(element));
  ++count;
}
 
template <typename K, typename T, int N>
void ChainedHashTable<K,T,N>::remove(const K& key)
{
  if (key > N-1) {
    throw overflow_error{ "Overflow on max capacity" };
  }
  if (key < 0) {
    throw underflow_error{ "Underflow on min element, should be ZERO" };
  }
  if (elements[key] == nullptr) {
    return;
  }

  elements[key] = nullptr;
  --count;
} 

template <typename K, typename T, int N>
size_t ChainedHashTable<K,T,N>::size() const
{
  return static_cast<size_t>(count);
}
 
template <typename K, typename T, int N>
bool ChainedHashTable<K,T,N>::empty() const
{
  return count == 0;
}

#endif
