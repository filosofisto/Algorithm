#ifndef __STACK_ARRAY__
#define __SYACK_ARRAY__

#include <array>
#include "Stack.h"

template <typename T>
class StackArray : public Stack<T>
{
  public:
    StackArray();
    virtual ~StackArray() = default;

    bool empty() const override;
    void push(T&& element) override;
    void push(const T& element) override;
    T pop() override;
    size_t size() const override;

  private:
    std::array<T, 100> _array;
    int top;
};

template <typename T>
StackArray<T>::StackArray() : top(-1)
{

}

template <typename T>
bool StackArray<T>::empty() const
{
  return top == -1;
}

template <typename T>
void StackArray<T>::push(T&& element)
{
  if (top == 99) {
    throw std::overflow_error("Stack overflow");
  }

  top++;
  _array[top] = std::move(element);
}

template <typename T>
void StackArray<T>::push(const T& element)
{
  if (top == 99) {
    throw std::overflow_error("Stack overflow");
  }

  top++;
  _array[top] = element;
}

template <typename T>
T StackArray<T>::pop()
{
  if (empty()) {
    throw std::underflow_error("Stack underflow");
  }

  return std::move(_array[top--]);
}

template <typename T>
size_t StackArray<T>::size() const
{
  return static_cast<size_t>(top)+1;
}
#endif
