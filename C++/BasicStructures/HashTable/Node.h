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
    Node(const K& key, const T& value);
    virtual ~Node() = default;

    K getKey() const;
    T getValue() const;

  private:
    K _key;
    T _value;
    unique_ptr<Node<K,T>> previous;
    unique_ptr<Node<K,T>> next;
};

template <typename K, typename T>
Node<K,T>::Node(const K& key, const T& value) : _key(key), _value(value), previous(nullptr), next(nullptr)
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
  return _value;
}
#endif
