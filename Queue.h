#pragma once
#include "Node.h"

template <class T>
class Queue {
private:
    Node<T>* front;
    Node<T>* rear;
    int count;

public:
    Queue() {
        front = rear = nullptr;
        count = 0;
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    void enqueue(T item) {
        Node<T>* newNode = new Node<T>(item);

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->setNext(newNode);
            rear = newNode;
        }
        count++;
    }

    T dequeue() {
        if (isEmpty())
            return nullptr;

        Node<T>* temp = front;
        T item = temp->getItem();
        front = front->getNext();

        if (!front)
            rear = nullptr;

        delete temp;
        count--;
        return item;
    }
};

