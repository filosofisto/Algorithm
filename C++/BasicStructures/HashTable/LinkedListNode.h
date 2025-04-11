#ifndef __LINKEDLISTNODE__
#define __LINKEDLISTNODE__

#include <memory>
#include <utility>

using std::unique_ptr;
using std::make_unique;
using std::shared_ptr;
using std::make_shared;
using std::move;
using std::forward;

template <typename K, typename T>
class LinkedListNode
{
  public:
		template <typename U>
    LinkedListNode(const K& key, U&& value);
    virtual ~LinkedListNode() = default;

		LinkedListNode(const LinkedListNode&) = delete;
		LinkedListNode& operator=(const LinkedListNode&) = delete;
		LinkedListNode(LinkedListNode&&) = delete;
		LinkedListNode& operator=(LinkedListNode&&) = delete;

    K getKey() const;
    T getValue() const;
		void setValue(T&& value);

		shared_ptr<LinkedListNode<K,T>> getPrevious() const;
		shared_ptr<LinkedListNode<K,T>> getNext() const;
		void setPrevious(shared_ptr<LinkedListNode<K,T>> previous);
		void setNext(shared_ptr<LinkedListNode<K,T>> next);
  private:
    K _key;
    unique_ptr<T> value_ptr;
    shared_ptr<LinkedListNode<K,T>> _previous;
    shared_ptr<LinkedListNode<K,T>> _next;
};

template <typename K, typename T>
template <typename U>
LinkedListNode<K,T>::LinkedListNode(const K& key, U&& value) : 
	_key(key), value_ptr(make_unique<T>(forward<U>(value))), _previous(nullptr), _next(nullptr)
{

}

template <typename K, typename T>
K LinkedListNode<K,T>::getKey() const
{
  return _key;
}

template <typename K, typename T>
T LinkedListNode<K,T>::getValue() const
{
  return *value_ptr;
}

template <typename K, typename T>
void LinkedListNode<K,T>::setValue(T&& value)
{
	value_ptr = make_unique<T>(move(value));
}

template <typename K, typename T>
shared_ptr<LinkedListNode<K,T>> LinkedListNode<K,T>::getPrevious() const
{
	return _previous;
}

template <typename K, typename T>
shared_ptr<LinkedListNode<K,T>> LinkedListNode<K,T>::getNext() const
{
	return _next;
}

template <typename K, typename T>
void LinkedListNode<K,T>::setPrevious(shared_ptr<LinkedListNode<K,T>> previous)
{
	_previous = previous;
}
		
template <typename K, typename T>
void LinkedListNode<K,T>::setNext(shared_ptr<LinkedListNode<K,T>> next)
{
	_next = next;
}

#endif
