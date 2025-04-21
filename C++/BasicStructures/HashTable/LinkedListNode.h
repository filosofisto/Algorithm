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
    LinkedListNode(const K& key, const T& value);
    virtual ~LinkedListNode() = default;

		LinkedListNode(const LinkedListNode&) = delete;
		LinkedListNode& operator=(const LinkedListNode&) = delete;
		LinkedListNode(LinkedListNode&&) = delete;
		LinkedListNode& operator=(LinkedListNode&&) = delete;

    K getKey() const;
    T getValue() const;
		void setValue(const T& value);

		shared_ptr<LinkedListNode<K,T>> getPrevious() const;
		shared_ptr<LinkedListNode<K,T>> getNext() const;
		void setPrevious(shared_ptr<LinkedListNode<K,T>> previous);
		void setNext(shared_ptr<LinkedListNode<K,T>> next);
  private:
    K key;
    T value;
    shared_ptr<LinkedListNode<K,T>> previous;
    shared_ptr<LinkedListNode<K,T>> next;
};

template <typename K, typename T>
LinkedListNode<K,T>::LinkedListNode(const K& key, const T& value) : 
	key(key), value(value), previous(nullptr), next(nullptr)
{

}

template <typename K, typename T>
K LinkedListNode<K,T>::getKey() const
{
  return key;
}

template <typename K, typename T>
T LinkedListNode<K,T>::getValue() const
{
  return value;
}

template <typename K, typename T>
void LinkedListNode<K,T>::setValue(const T& value)
{
	this->value = value;
}

template <typename K, typename T>
shared_ptr<LinkedListNode<K,T>> LinkedListNode<K,T>::getPrevious() const
{
	return previous;
}

template <typename K, typename T>
shared_ptr<LinkedListNode<K,T>> LinkedListNode<K,T>::getNext() const
{
	return next;
}

template <typename K, typename T>
void LinkedListNode<K,T>::setPrevious(shared_ptr<LinkedListNode<K,T>> previous)
{
	this->previous = previous;
}
		
template <typename K, typename T>
void LinkedListNode<K,T>::setNext(shared_ptr<LinkedListNode<K,T>> next)
{
	this->next = next;
}
#endif
