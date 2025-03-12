//
// Created by eduardo on 03.05.20.
//

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

#include <type_traits>
#include <iostream>

#include "DoubleLinkedList.h"

using namespace std;

constexpr int DEFAULT_CAPACITY = 100;

template <typename K, typename T>
class HashTable
{
public:
    HashTable();

    explicit HashTable(size_t capacity);

    virtual ~HashTable();

    void put(K* key, T* data);

    void remove(K* key);

    Node<K, T>* get(K* key) const;

    bool exists(K* key) const;

    double percentualFull() const;

    size_t getSize() const;

    bool empty() const;

    void setHashCalculator(size_t (*hashCalculator)(K*));

private:
    size_t calcPosFromHash(K* key) const;

    DoubleLinkedList<K, T> *getDoubleLinkedList(size_t pos) ;

    DoubleLinkedList<K, T>** slots;

    size_t capacity;
    size_t slotsCount;
    size_t (*hashCalculator)(K*);
};

template <typename K, typename T>
HashTable<K, T>::HashTable(): capacity(DEFAULT_CAPACITY), slotsCount(0), hashCalculator(nullptr)
{
    slots = new DoubleLinkedList<K, T>*[capacity];
}

template <typename K, typename T>
HashTable<K, T>::HashTable(size_t capacity): capacity(capacity), slotsCount(0)
{
    slots = new DoubleLinkedList<K, T>*[capacity];
}

template <typename K, typename T>
HashTable<K, T>::~HashTable()
{
    for (int i = 0; i < capacity; i++) {
        if (slots[i] != nullptr) {
            delete slots[i];
        }
    }

    delete[] slots;
}

template <typename K, typename T>
void HashTable<K, T>::put(K* key, T* data)
{
    // Calculate the bucked
    size_t pos = calcPosFromHash(key);
    DoubleLinkedList<K, T> *linkedList = getDoubleLinkedList(pos);

    // Locate the key
    // If already exist, replace by the new data (collision by same key)
    // If doesn't exist just insert new data (collision by different key)
    auto node = linkedList->search(key);
    if (node != nullptr) {
        linkedList->remove(node);
    }
    linkedList->insert(data, key);
}

template <typename K, typename T>
DoubleLinkedList<K, T>* HashTable<K, T>::getDoubleLinkedList(size_t pos) {
    DoubleLinkedList<K, T>* linkedList = slots[pos];
    if (linkedList == nullptr) {
        linkedList = new DoubleLinkedList<K, T>();
        slots[pos] = linkedList;
        slotsCount++;
    }
    return linkedList;
}

template <typename K, typename T>
void HashTable<K, T>::remove(K* key)
{
    size_t pos = calcPosFromHash(key);

    DoubleLinkedList<K, T>* linkedList = slots[pos];
    if (linkedList == nullptr) {
        return;
    }

    auto node = linkedList->search(key);
    if (node != nullptr) {
        linkedList->remove(node);
    }
}

template <typename K, typename T>
Node<K, T>* HashTable<K, T>::get(K* key) const
{
    size_t pos = calcPosFromHash(key);
    DoubleLinkedList<K, T>* linkedList = slots[pos];
    if (linkedList == nullptr) {
        return nullptr;
    }

    return linkedList->search(key);
}

template <typename K, typename T>
bool HashTable<K, T>::exists(K* key) const
{
    return get(key) != nullptr;
}

template <typename K, typename T>
size_t HashTable<K, T>::calcPosFromHash(K* key) const {
    if (hashCalculator != nullptr) {
        return hashCalculator(key) % capacity;
    }

    return hash<K>{}(*key) % capacity;
}

/*template <typename K, typename T>
ostream& operator<<(ostream& os, const HashTable<K, T>& hashTable)
{
    DoubleLinkedList<K, T>* linkedList;

    for (int i = 0; i < hashTable.capacity; i++) {
        linkedList = hashTable.slots[i];

        if (linkedList != nullptr) {
            os << "[" << i << "]: " << (*linkedList) << endl;
        }
    }

    return os;
}*/

template<typename K, typename T>
double HashTable<K, T>::percentualFull() const {
    return (static_cast<double>(slotsCount)/capacity)*100;
}

template<typename K, typename T>
size_t HashTable<K, T>::getSize() const {
    size_t total = 0;
    DoubleLinkedList<K, T>* linkedList;

    for (int i = 0; i < capacity; i++) {
        linkedList = slots[i];

        if (linkedList != nullptr) {
            total += linkedList->getSize();
        }
    }

    return total;
}

template<typename K, typename T>
bool HashTable<K, T>::empty() const {
    return getSize() == 0;
}

template<typename K, typename T>
void HashTable<K, T>::setHashCalculator(size_t (*hashCalculator)(K*)) {
    this->hashCalculator = hashCalculator;
}

#endif //HASHTABLE_HASHTABLE_H
