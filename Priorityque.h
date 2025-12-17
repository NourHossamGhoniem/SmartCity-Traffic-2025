#pragma once
#include "Node.h"

template <class T>
class PriorityQueue {
private:
    Node<T>* front;
    int count;

public:
    PriorityQueue() {
        front = nullptr;
        count = 0;
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    void enqueue(T item) {
        Node<T>* newNode = new Node<T>(item);

        // empty
        if (!front) {
            front = newNode;
            count++;
            return;
        }

        // higher priority first
        if (item->priority > front->getItem()->priority) {
            newNode->setNext(front);
            front = newNode;
            count++;
            return;
        }

        Node<T>* curr = front;
        while (curr->getNext() &&
               curr->getNext()->getItem()->priority >= item->priority) {
            curr = curr->getNext();
        }

        newNode->setNext(curr->getNext());
        curr->setNext(newNode);
        count++;
    }

    T dequeue() {
        if (isEmpty())
            return nullptr;

        Node<T>* temp = front;
        T item = temp->getItem();
        front = front->getNext();

        delete temp;
        count--;
        return item;
    }
};
