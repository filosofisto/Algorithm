#ifndef __STACK_VECTOR__
#define __STACK_VECTOR__

#include <vector>
#include "Stack.h"

template <typename T>
class StackVector : public Stack<T>
{
  public:
    StackVector() = default;
    virtual ~StackVector() = default;

    bool empty() const override;
    void push(T&& element) override;
    void push(const T& element) override;
    T pop() override;
    size_t size() const override;

  private:
    std::vector<T> elements;
};

template <typename T>
bool StackVector<T>::empty() const
{
  return elements.empty();
}

template <typename T>
void StackVector<T>::push(T&& element)
{
  elements.insert(elements.begin(), std::move(element));
}

template <typename T>
void StackVector<T>::push(const T& element)
{
  elements.insert(elements.begin(), element);
}

template <typename T>
T StackVector<T>::pop()
{
  if (empty()) {
    throw std::underflow_error("Stack underflow");
  }

  auto element = elements.front();
  elements.erase(elements.begin());

  return element;
}

template <typename T>
size_t StackVector<T>::size() const
{
  return elements.size();
}

#endif
