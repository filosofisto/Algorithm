//
// Created by eduardo on 12.04.20.
//

#ifndef LINKEDLIST_NODE_H
#define LINKEDLIST_NODE_H

#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class Node {
public:
    explicit Node(T* data);
    ~Node();

    T* data() const;

    Node<T>* before() const;
    void before(Node<T>* _before);

    Node<T>* next() const;
    void next(Node<T>* _next);

private:
    T* _data;
    Node<T>* _before;
    Node<T>* _next;
};

template <typename T>
Node<T>::Node(T* data): _data(data)
{

}

template <typename T>
Node<T>::~Node() = default;

template <typename T>
T* Node<T>::data() const
{
    return _data;
}

template <typename T>
Node<T>* Node<T>::before() const
{
    return _before;
}

template <typename T>
void Node<T>::before(Node<T>* _before)
{
    this->_before = _before;
}

template <typename T>
Node<T>* Node<T>::next() const
{
    return _next;
}

template <typename T>
void Node<T>::next(Node<T>* _next)
{
    this->_next = _next;
}

#endif //LINKEDLIST_NODE_H
