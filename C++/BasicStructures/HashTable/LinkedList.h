#ifndef __LINKELIST__
#define __INKEDLIST__

#include <memory>

template <typename T>
class LinkedList;

template <typename T>
class Node
{
  public:
    Node(const T& element);
    virtual ~Node() = default;

    T data();

    friend class LinkedList<T>;
  private:
    T element;
    std::shared_ptr<Node<T>> previous;
    std::shared_ptr<Node<T>> next;
};

template <typename T>
Node<T>::Node(const T& element)
{
  this->element = element;
  this->previous = nullptr;
  this->next = nullptr;
}

template <typename T>
T Node<T>::data()
{
  return element;
}

template <typename T>
class LinkedList
{
  public:
    LinkedList();
    virtual ~LinkedList() = default;

    std::shared_ptr<Node<T>> search(const T& element) const;
    void prepend(const T& element);
    void postpend(const T& element);
//    void insert(const T& baseElement, const T& element);
    void remove(const T& element);
    bool empty() const;
    size_t size() const;
    std::shared_ptr<Node<T>> first() const;
    std::shared_ptr<Node<T>> last() const;

  private:
    void remove(std::shared_ptr<Node<T>> node);
    
    size_t _size;
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;
};

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), _size(0)
{

}

template <typename T>
std::shared_ptr<Node<T>> LinkedList<T>::search(const T& element) const
{
  auto nodePtr = head;

  while (nodePtr != nullptr && (*nodePtr).data() != element) {
    nodePtr = nodePtr->next;
  }

  return nodePtr;
}

template <typename T>
std::shared_ptr<Node<T>> LinkedList<T>::first() const
{
  return head;
}

template <typename T>
std::shared_ptr<Node<T>> LinkedList<T>::last() const
{
  return tail;
}


template <typename T>
void LinkedList<T>::prepend(const T& element)
{
  auto node = std::make_shared<Node<T>>(element);
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

template <typename T>
void LinkedList<T>::remove(std::shared_ptr<Node<T>> node)
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

template <typename T>
void LinkedList<T>::remove(const T& element)
{
  auto node = search(element);
  if (node != nullptr) {
    remove(node);
  }
}

template <typename T>
bool LinkedList<T>::empty() const
{
  return head == nullptr;
}

template <typename T>
size_t LinkedList<T>::size() const
{
  return _size;
}
#endif
