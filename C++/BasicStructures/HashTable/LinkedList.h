#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <memory>
#include "Node.h"

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

    shared_ptr<Node<K,T>> search(const T& element) const;
    shared_ptr<Node<k,T>> searchByKey(const K& key) const;
    void prepend(const T& element);
    void postpend(const T& element);
    void remove(const T& element);
    void removeByKey(const K& key)
    bool empty() const;
    size_t size() const;
    shared_ptr<Node<K,T>> first() const;
    shared_ptr<Node<K,T>> last() const;

  private:
    void remove(shared_ptr<Node<K,T>> node);
    
    size_t _size;
    shared_ptr<Node<K,T>> head;
    shared_ptr<Node<K,T>> tail;
};

template <typename K, typename T>
LinkedList<K,T>::LinkedList() : head(nullptr), tail(nullptr), _size(0)
{

}

template <typename K, typename T>
shared_ptr<Node<K,T>> LinkedList<K,T>::search(const T& element) const
{
  auto nodePtr = head;

  while (nodePtr != nullptr && (*nodePtr).getValue() != element) {
    nodePtr = nodePtr->next;
  }

  return nodePtr;
}

template <typename K, typename T>
shared_ptr<Node<K,T>> LinkedList<K,T>::searchByKey(const K& key) const
{
  auto nodePtr = head;

  while (nodePtr != nullptr && (*nodePtr).getKey() != key) {
    nodePtr = nodePtr->next;
  }

  return nodePtr;
}

template <typename K, typename T>
std::shared_ptr<Node<K,T>> LinkedList<K,T>::first() const
{
  return head;
}

template <typename K, typename T>
std::shared_ptr<Node<K,T>> LinkedList<K,T>::last() const
{
  return tail;
}

template <typename K, typename T>
void LinkedList<K,T>::prepend(const K& key, const T& value)
{
  auto node = make_shared<Node<K,T>>(key, value);
  node->next = head;
  node->previous = nullptr;

  if (head != nullptr) {
    head->previous = node;
  }

  head = node;

  if (tail == nullptr) {
    tail = node;
  }

  _size++;
}

template <typename K, typename T>
void LinkedList<K,T>::remove(shared_ptr<Node<K,T>> node)
{
  if (node->previous != nullptr) {
    node->previous->next = node->next;
  } else {
    head = node->next;
  }

  if (node->next != nullptr) {
    node->next->previous = node->previous;
  }

  _size--;
}

template <typename K, typename T>
void LinkedList<K,T>::remove(const T& value)
{
  auto node = search(value);
  if (node != nullptr) {
    remove(node);
  }
}

template <typename K, typename T>
void LinkedList<K,T>::removeByKey(const K& key)
{
  auto node = searchByKey(key);
  if (node != nullptr) {
    remove(node);
  }
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
