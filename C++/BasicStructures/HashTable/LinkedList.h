#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <memory>
#include "LinkedListNode.h"

using std::unique_ptr;
using std::make_unique;
using std::move;
using std::shared_ptr;
using std::make_shared;

template <typename K, typename T>
class LinkedList
{
  public:
    LinkedList();
    virtual ~LinkedList() = default;

    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;
    LinkedList(LinkedList&&) = delete;
    LinkedList& operator=(LinkedList&&) = delete;

    shared_ptr<LinkedListNode<K,T>> search(const T& element) const;
    shared_ptr<LinkedListNode<K,T>> searchByKey(const K& key) const;
    void prepend(const K& key, const T& element);
    bool remove(const T& element);
    bool removeByKey(const K& key);
    bool empty() const;
    size_t size() const;
    shared_ptr<LinkedListNode<K,T>> first() const;
    shared_ptr<LinkedListNode<K,T>> last() const;

  private:
    void remove(shared_ptr<LinkedListNode<K,T>> node);
    
    size_t _size;
    shared_ptr<LinkedListNode<K,T>> head;
    shared_ptr<LinkedListNode<K,T>> tail;
};

template <typename K, typename T>
LinkedList<K,T>::LinkedList() : head(nullptr), tail(nullptr), _size(0)
{

}

template <typename K, typename T>
shared_ptr<LinkedListNode<K,T>> LinkedList<K,T>::search(const T& element) const
{
  auto node = head;

  while (node != nullptr && (*node).getValue() != element) {
    node = node->getNext();
  }

  return node;
}

template <typename K, typename T>
shared_ptr<LinkedListNode<K,T>> LinkedList<K,T>::searchByKey(const K& key) const
{
  auto node = head;

  while (node != nullptr && (*node).getKey() != key) {
    node = node->getNext();
  }

  return node;
}

template <typename K, typename T>
shared_ptr<LinkedListNode<K,T>> LinkedList<K,T>::first() const
{
  return head;
}

template <typename K, typename T>
shared_ptr<LinkedListNode<K,T>> LinkedList<K,T>::last() const
{
  return tail;
}

template <typename K, typename T>
void LinkedList<K,T>::prepend(const K& key, const T& value)
{
  auto node = make_shared<LinkedListNode<K,T>>(key, value);
  node->setNext(head);
  node->setPrevious(nullptr);

  if (head != nullptr) {
    head->setPrevious(node);
  }

  head = node;

  if (tail == nullptr) {
    tail = node;
  }

  _size++;
}

template <typename K, typename T>
void LinkedList<K,T>::remove(shared_ptr<LinkedListNode<K,T>> node)
{
  if (node->getPrevious() != nullptr) {
    node->getPrevious()->setNext(node->getNext());
  } else {
    head = node->getNext();
  }

  if (node->getNext() != nullptr) {
    node->getNext()->setPrevious(node->getPrevious());
  }

  _size--;
}

template <typename K, typename T>
bool LinkedList<K,T>::remove(const T& value)
{
  auto node = search(value);
  if (node != nullptr) {
    remove(node);
		return true;
  }

	return false;
}

template <typename K, typename T>
bool LinkedList<K,T>::removeByKey(const K& key)
{
  auto node = searchByKey(key);
  if (node != nullptr) {
    remove(node);
		return true;
  }

	return false;
}

template <typename K, typename T>
bool LinkedList<K,T>::empty() const
{
  return head == nullptr;
}

template <typename K, typename T>
size_t LinkedList<K,T>::size() const
{
  return _size;
}
#endif
