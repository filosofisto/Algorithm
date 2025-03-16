#ifndef __QUEUE__
#define __QUEUE__

template <typename T>
class Queue
{
  public:
    Queue() = default;
    virtual ~Queue() = default;

    virtual bool empty() const = 0;
    virtual void enqueue(T&& element) = 0;
    virtual void enqueue(const T& element) = 0;
    virtual T dequeue() = 0;
    virtual size_t size() const =  0;
};

#endif
