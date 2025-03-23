#ifndef __NODE__
#define __NODE__

#include <memory>

using std::unique_ptr;
using std::make_unique;
using std::move;

template <typename K, typename T>
class Node
{
  public:
    Node(const K& key, T&& value);
    virtual ~Node() = default;

    K getKey() const;
    T getValue() const;

  private:
    K _key;
    unique_ptr<T> value_ptr;
};

template <typename K, typename T>
Node<K,T>::Node(const K& key, T&& value) : _key(key), value_ptr(make_unique(move(value)))
{

}

template <typename K, typename T>
K Node<K,T>::getKey() const
{
  return _key;
}

template <typename K, typename T>
T Node<T,T>::getValue() const
{
  return *value_ptr;
}
#endif
