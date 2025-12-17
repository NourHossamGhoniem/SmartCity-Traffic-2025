#pragma once

template <class T>
class Node {
private:
    T item;
    Node<T>* next;

public:
    Node(T data) {
        item = data;
        next = nullptr;
    }

    void setNext(Node<T>* n) {
        next = n;
    }

    Node<T>* getNext() const {
        return next;
    }

    T getItem() const {
        return item;
    }
};

