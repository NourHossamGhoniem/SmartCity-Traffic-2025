#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>
using namespace std;

template<class T>
class LinkedList {
private:
    Node<T>* head;
    int count;

public:
    LinkedList() {
        head = nullptr;
        count = 0;
    }

    ~LinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* nodetoDelete = current;
            current = current->getnext(); 
            delete nodetoDelete;
        }
    }

    Node<T>* getHead() {
        return head;
    }

    int getCount() {
        return count;
    }

    bool isEmpty() {
        if (count == 0) {
            return true; 
        }
        else {
            return false;
        }
    }

    bool isFull() {
        return false;
    }

    void insertatbeginning(const T& data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->setNext(head);
        head = newNode;
        count++;
    }

    void printList() {
        cout << "List has (" << count << ") items: ";
        Node<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->getitem() << " -> "; 
            temp = temp->getnext();            
        }
        cout << "NULL";
    }
};
 
#endif
//nour
