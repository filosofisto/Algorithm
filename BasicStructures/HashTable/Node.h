//
// Created by eduardo on 03.05.20.
//

#ifndef HASHTABLE_NODE_H
#define HASHTABLE_NODE_H

#include <iostream>
#include <memory>

using namespace std;

template <typename K, typename T>
class Node {
public:
    explicit Node(T* data, K* key);
    ~Node();

    T* data() const;

    K* key() const;

    Node<K, T>* previous() const;
    void previous(Node<K, T> *_before);

    Node<K, T>* next() const;
    void next(Node<K, T>* _next);
private:
    T* _data;
    K* _key;
    Node<K, T>* _before;
    Node<K, T>* _next;
};

template <typename K, typename T>
Node<K, T>::Node(T* data, K* key): _data(data), _key(key)
{

}

template <typename K, typename T>
Node<K, T>::~Node() = default;

template <typename K, typename T>
T* Node<K, T>::data() const
{
    return _data;
}

template<typename K, typename T>
K* Node<K, T>::key() const
{
    return _key;
}

template <typename K, typename T>
Node<K, T>* Node<K, T>::previous() const
{
    return _before;
}

template <typename K, typename T>
void Node<K, T>::previous(Node<K, T> *_before)
{
    this->_before = _before;
}

template <typename K, typename T>
Node<K, T>* Node<K, T>::next() const
{
    return _next;
}

template <typename K, typename T>
void Node<K, T>::next(Node<K, T>* _next)
{
    this->_next = _next;
}

#endif //HASHTABLE_NODE_H
