//
// Created by eduardo on 22.04.20.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

#include "Node.h"
#include <glob.h>

template <typename T>
class Stack {
public:
    Stack();
    ~Stack();

    Stack* push(T* data);
    T* pop();
    T* peek() const;
    bool empty() const;
    size_t getSize() const;
private:
    Node<T>* top;
    size_t size;
};

template <typename T>
Stack<T>::Stack(): top(nullptr), size(0)
{

}

template <typename T>
Stack<T>::~Stack()
{
    while (!empty()) {
        pop();
    }
}

template <typename T>
Stack<T> *Stack<T>::push(T *data) {
    auto node = new Node<T>(data);

    if (empty()) {
        top = node;
        top->previous(nullptr);
    } else {
        node->previous(top);
        top->next(node);
        top = node;
    }

    top->next(nullptr);
    size++;

    return this;
}

template <typename T>
T *Stack<T>::pop() {
    if (empty()) {
        return nullptr;
    }

    auto node = top;
    top = top->previous();
    size--;

    T* result = node->data();
    delete node;

    return result;
}

template <typename T>
T *Stack<T>::peek() const {
    if (empty()) {
        return nullptr;
    }

    return top->data();
}

template <typename T>
bool Stack<T>::empty() const
{
    return size == 0;
}

template<typename T>
size_t Stack<T>::getSize() const {
    return size;
}

#endif //STACK_STACK_H
