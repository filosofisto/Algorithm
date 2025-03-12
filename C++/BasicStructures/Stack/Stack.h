#ifndef __STACK__
#define __STACK__

template <typename T>
class Stack
{
  public:
    Stack() = default;
    virtual ~Stack() = default;

    virtual bool empty() const = 0;
    virtual void push(T&& element) = 0;
    virtual void push(const T& element) = 0;
    virtual T pop() = 0;
    virtual size_t size() const =  0;
};

#endif
