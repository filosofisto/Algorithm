#ifndef __HASHTABLE__
#define __HASHTABLE__

template <typename K, typename T>
class HashTable
{
  public:
    HashTable() = default;
    virtual ~HashTable() = default;

    virtual T* search(const K& key) const = 0;
    virtual void insert(const K& key, T&& element) = 0;
    virtual void remove(const K& key) = 0;
    virtual size_t size() const = 0;
    virtual bool empty() const = 0;
};

#endif
