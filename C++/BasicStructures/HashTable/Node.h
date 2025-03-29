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

		Node(const Node&) = delete;
		Node& operator=(const Node&) = delete;
		Node(Node&&) = delete;
		Node& operator=(Node&&) = delete;

    K getKey() const;
    T& getValue() const;
		void setValue(T&& value);

  private:
    K _key;
    unique_ptr<T> value_ptr;
    unique_ptr<Node<K,T>> previous;
    unique_ptr<Node<K,T>> next;
};

template <typename K, typename T>
Node<K,T>::Node(const K& key, T&& value) : 
	_key(key), value_ptr(make_unique<T>(move(value))), previous(nullptr), next(nullptr)
{

}

template <typename K, typename T>
K Node<K,T>::getKey() const
{
  return _key;
}

template <typename K, typename T>
T& Node<K,T>::getValue() const
{
  return *value_ptr;
}

template <typename K, typename T>
void Node<K,T>::setValue(T&& value)
{
	value_ptr = make_unique<T>(move(value));
}

#endif
