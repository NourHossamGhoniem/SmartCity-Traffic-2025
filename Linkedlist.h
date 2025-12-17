#pragma once
#include "Node.h"

template <class T>
class LinkedList {
protected:
    Node<T>* head;
    int count;

public:
    LinkedList() {
        head = nullptr;
        count = 0;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    int getCount() const {
        return count;
    }
};

