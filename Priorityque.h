#pragma once
#include "LinkedList.h"
#include <iostream>
using namespace std;

template <class T>
class PriorityQueue : public LinkedList<T> {
private:
    Node<T>* front;
    Node<T>* rear;
    int count;

public:
    PriorityQueue() {
        front = nullptr;
        rear = nullptr;
        count = 0;
    }

    bool isEmpty() {
        return (front == nullptr);
    }

    void enqueue(T item) {
        Node<T>* newNode = new Node<T>(item);

        // lw empty
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
            count++;
            return;
        }

        // lw priority high
        if (item < front->getitem()) {      
            newNode->setNext(front);
            front = newNode;
            count++;
            return;
        }

        // loop
        Node<T>* curr = front;
        while (curr->getnext() != nullptr &&   
            curr->getnext()->getitem() < item) { 
            curr = curr->getnext();            
        }

        newNode->setNext(curr->getnext());     
        curr->setNext(newNode);

        if (newNode->getnext() == nullptr) {   
            rear = newNode;
        }

        count++;
    }

    T dequeue() {
        if (isEmpty()) {
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
