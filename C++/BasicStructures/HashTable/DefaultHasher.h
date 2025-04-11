#ifndef __DEFAULTHASHER__
#define __DEFAULTHASHER__

#include <functional>

using std::hash;

template <typename K>
struct DefaultHasher
{
	size_t operator()(const K& key) const;
};

template <typename K>
size_t DefaultHasher<K>::operator()(const K& key) const
{
	return std::hash<K>{}(key);	
};

#endif
