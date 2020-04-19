//
// Created by eduardo on 19.04.20.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include "Node.h"

template <typename T>
class Queue {
public:
    Queue();
    ~Queue();

    Queue<T>* enqueue(T* data);
    T* dequeue();
    bool empty() const;
    size_t getSize() const;
private:
    Node<T>* head;
    Node<T>* tail;
    size_t size;
};

template<typename T>
Queue<T>::Queue(): head(nullptr), tail(nullptr), size(0) {

}

template<typename T>
Queue<T>::~Queue() {
    while (!empty()) {
        dequeue();
    }
}

template<typename T>
Queue<T> *Queue<T>::enqueue(T* data) {
    auto node = new Node(data);
    node->next(tail);
    node->before(nullptr);

    if (tail != nullptr) {
        tail->before(node);
    }

    tail = node;

    if (head == nullptr) {
        head = node;
    }

    size++;

    return this;
}

template<typename T>
T* Queue<T>::dequeue() {
    if (head != nullptr) {
        auto node = head;
        head = head->before();
        auto data = node->data();
        delete node;
        size--;

        return data;
    }

    return nullptr;
}

template<typename T>
bool Queue<T>::empty() const {
    return head == nullptr;
}

template<typename T>
size_t Queue<T>::getSize() const {
    return size;
}

#endif //QUEUE_QUEUE_H
