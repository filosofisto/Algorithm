#ifndef __Queue_ARRAY__
#define __Queue_ARRAY__

#include <iostream>
#include <array>
#include <cmath>

#include "Queue.h"

template <typename T>
class QueueArray : public Queue<T>
{
  public:
    QueueArray();
    virtual ~QueueArray() = default;

    bool empty() const override;
    void enqueue(T&& element) override;
    void enqueue(const T& element) override;
    T dequeue() override;
    size_t size() const override;
   
    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, const QueueArray<U>& queue);

  private:
    void checkOverflow() const;
    void updateTail();
    std::array<T, 100> _array;
    int head;
    int tail;
};

template <typename T>
QueueArray<T>::QueueArray() : head(0), tail(0)
{

}

template <typename T>
bool QueueArray<T>::empty() const
{
  return head == tail;
}

template <typename T>
void QueueArray<T>::enqueue(T&& element)
{
  checkOverflow();

  _array[tail] = std::move(element);

  updateTail();
}

template <typename T>
void QueueArray<T>::enqueue(const T& element)
{
  checkOverflow();

  _array[tail] = element;

  updateTail();
}

template <typename T>
T QueueArray<T>::dequeue()
{
  if (empty()) {
    throw std::underflow_error("Queue underflow");
  }

  auto element = _array[head];

  if (head == _array.size()) {
    head = 0;
  } else {
    head++;
  }

  return element;
}

template <typename T>
size_t QueueArray<T>::size() const
{
  return std::abs(tail-head);
}

template <typename T>
void QueueArray<T>::checkOverflow() const
{
  if (size() == 100) {
    throw std::overflow_error("Queue overflow");
  }
}

template <typename T>
void QueueArray<T>::updateTail()
{
  if (tail == _array.size()) {
    tail = 0;
  } else {
    tail++;
  }
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const QueueArray<T>& queue)
{
  out << "QueueArray[head=" << queue.head << ", tail=" << queue.tail << ", size=" << queue.size() << "]";

  return out;
}
#endif

