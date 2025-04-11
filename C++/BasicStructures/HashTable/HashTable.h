#ifndef __HASHTABLE__
#define __HASHTABLE__

struct HashTableInternalInfo
{
	int collisions;
	int replacements;
};

template <typename K, typename T>
class HashTable
{
  public:
    HashTable() = default;
    virtual ~HashTable() = default;

    HashTable(const HashTable&) = delete;
    HashTable& operator=(const HashTable&) = delete;
    HashTable(HashTable&&) = delete;
    HashTable& operator=(HashTable&&) = delete;

    virtual T search(const K& key) const = 0;
    virtual void insert(const K& key, T&& element) = 0;
    virtual void remove(const K& key) = 0;
    virtual size_t size() const = 0;
    virtual bool empty() const = 0;
		virtual HashTableInternalInfo getInternalInfo() const = 0;
};

#endif
