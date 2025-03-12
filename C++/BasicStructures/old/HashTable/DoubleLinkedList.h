//
// Created by eduardo on 03.05.20.
//

#ifndef HASHTABLE_LINKEDLIST_H
#define HASHTABLE_LINKEDLIST_H

#include <memory>
#include <iostream>
#include "Node.h"

using namespace std;

template <typename K, typename T>
class DoubleLinkedList {
public:
    DoubleLinkedList();
    ~DoubleLinkedList();

    Node<K, T>* search(K* key) const;

    void insert(T* data, K* key);

    void remove(Node<K, T>* node);

    size_t getSize() const;

    void print();
private:
    Node<K, T>* head;
    size_t size;
};

template<typename K, typename T>
DoubleLinkedList<K, T>::DoubleLinkedList(): size(0)
{

}

template<typename K, typename T>
DoubleLinkedList<K, T>::~DoubleLinkedList()
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

template<typename K, typename T>
Node<K, T>* DoubleLinkedList<K, T>::search(K* key) const {
    auto node = head;

    while (node != nullptr) {
        if (*node->key() == *key) {
            return node;
        }

        node = node->next();
    }

    return nullptr;
}

template<typename K, typename T>
void DoubleLinkedList<K, T>::insert(T* data, K* key) {
    auto node = new Node<K, T>(data, key);
    node->next(head);

    if (head != nullptr) {
        head->previous(node);
    }

    head = node;
    node->previous(nullptr);

    size++;
}

template<typename K, typename T>
void DoubleLinkedList<K, T>::remove(Node<K, T>* node)
{
    if (node == nullptr) {
        return;
    }

    if (node->previous() == nullptr) {
        // head -> X -> Y
        // head = X.next (Y)
        // head -> Y
        head = node->next();

        // Y.previous -> null (due to head -> Y)
        if (node->next() != nullptr) {
            node->next()->previous(nullptr);
        }
    } else {
        // head -> W -> X -> Y
        // W.next = Y
        node->previous()->next(node->next());

        // Y.previous = W
        // head -> W -> Y
        if (node->next() != nullptr) {
            node->next()->previous(node->previous());
        }
    }

    size--;
}

template<typename K, typename T>
void DoubleLinkedList<K, T>::print()
{
    auto node = head;

    cout << "[";

    while (node != nullptr) {
        cout << *node->data();

        node = node->next();

        if (node != nullptr) {
            cout << " | ";
        }
    }

    cout << "]";
}

template<typename K, typename T>
size_t DoubleLinkedList<K, T>::getSize() const {
    return size;
}

#endif //HASHTABLE_LINKEDLIST_H
