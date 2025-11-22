#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

template <class T>
class Queue {
private:
    Node<T>* front;
    Node<T>* rear;
    int count;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
        count = 0;
    }

    bool isEmpty() {
        if (front == nullptr) {
            return true;
        }
        return false;
    }

    void enqueue(T item) {
        Node<T>* newNode = new Node<T>(item);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->setNext(newNode);
            rear = newNode;
        }
        count++;
    }

    T dequeue() {
        if (front == nullptr) {
            return nullptr;
        }

        Node<T>* curr = front;
        T item = front->getitem(); 
        front = front->getnext();  

        if (front == nullptr) {
            rear = nullptr;
        }

        delete curr;
        count--;
        return item;
    }
};



