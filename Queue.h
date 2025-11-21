#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"
#include <iostream>
using namespace std;


template<class T>
class Queue : public LinkedList<T> {
    Node<T>* front;
    Node<T>* rear;
public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(T item) {
        Node<T>* t = new Node<T>(item);
        if (t == nullptr) {
            cout << "the que is full\n";
            return;
        }
        if (front == nullptr) {
            front = t;
            rear = t;
        }
        else {
            rear->setNext(t);
            rear = t;
        }
    }

    T dequeue() {
        T x = nullptr;
        if (front == nullptr) {
            cout << "the que is empty\n";
            return x;
        }
        Node<T>* p = front;
        front = front->getNext();
        x = p->getItem();
        delete p;
        if (front == nullptr) {
            rear = nullptr;
            return x;
        }
    }

    void print() {
        cout << "  ";
        Node<T>* p = front;
        if (p == nullptr) {
            cout << "the que empty\n";
            return;
        }
        while (p != nullptr) {
            p->getItem()->print();
            cout << " ";
            p = p->getNext();
        }
        cout << endl;
    }
};

#endif
