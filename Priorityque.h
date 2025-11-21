#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "LinkedList.h"

template<class T>
class PriorityQueue : public LinkedList<T> {
public:
    void enqueue(T item, int time) {
        Node<T>* n = new Node<T>(item);
        if (n == nullptr) {
            cout << "priority queue full\n";
            return;
        }
        if (isEmpty()) {
            insertatbeginning(item);
            return;
        }
        if (time <= getHead()->getItem()->time) {
            insertatbeginning(item);
            return;
        }
        Node<T>* p = getHead();
        while (p->getNext() != nullptr && p->getNext()->getItem()->time <= time) {
            p = p->getNext();
        }
        n->setNext(p->getNext());
        p->setNext(n);
    }
};


#endif
//nour
