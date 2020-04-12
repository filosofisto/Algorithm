//
// Created by eduardo on 12.04.20.
//

#ifndef LINKEDLIST_LinkedList_H
#define LINKEDLIST_LinkedList_H

#include <memory>
#include <iostream>
#include <cstdarg>

#include "Node.h"

using namespace std;

template <typename T>
class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    LinkedList<T>* add(const T& data);

    bool remove(const T& data);

    bool contains(const T& data) const;

    size_t getSize() const;

    bool empty() const;

    void print(ostream& os);
private:
    void remove(Node<T>* node);

    Node<T>* head;
    size_t size;
};

template <typename T>
LinkedList<T>::LinkedList(): size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList()
{
    auto node = head;
    auto nodeBefore = head;

    while (node != nullptr) {
        node = node->next();

        delete nodeBefore;
        nodeBefore = node;
    }

    if (nodeBefore != nullptr) {
        delete nodeBefore;
    }
}

template <typename T>
LinkedList<T>* LinkedList<T>::add(const T& data)
{
    auto node = new Node<T>(data);
    node->next(head);

    if (head != nullptr) {
        head->before(node);
    }

    head = node;
    node->before(nullptr);

    size++;

    return this;
}


template<typename T>
bool LinkedList<T>::remove(const T &data) {
    auto node = head;

    while (node != nullptr) {
        if (node->data() == data) {
            remove(node);
            return true;
        }

        node = node->next();
    }

    return false;
}

template <typename T>
void LinkedList<T>::remove(Node<T>* node)
{
    if (node == nullptr) {
        return;
    }

    if (node->before() == nullptr) {
        // head -> X -> Y
        // head = X.next (Y)
        // head -> Y
        head = node->next();

        // Y.before -> null (due to head -> Y)
        if (node->next() != nullptr) {
            node->next()->before(nullptr);
        }
    } else {
        // head -> W -> X -> Y
        // W.next = Y
        node->before()->next(node->next());

        // Y.before = W
        // head -> W -> Y
        if (node->next() != nullptr) {
            node->next()->before(node->before());
        }
    }

    size--;
}

template <typename T>
void LinkedList<T>::print(ostream& os)
{
    auto node = head;

    os << "[";

    while (node != nullptr) {
        os << node->data();

        node = node->next();

        if (node != nullptr) {
            os << " | ";
        }
    }

    os << "]";
}

template <typename T>
size_t LinkedList<T>::getSize() const {
    return size;
}

template<typename T>
bool LinkedList<T>::contains(const T &data) const {
    auto node = head;

    while (node != nullptr) {
        if (node->data() == data) {
            return true;
        }

        node = node->next();
    }

    return false;
}

template<typename T>
bool LinkedList<T>::empty() const {
    return getSize() == 0;
}


#endif //LINKEDLIST_LinkedList_H
