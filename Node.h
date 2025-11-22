#pragma once
#include <iostream>
using namespace std;
#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
private:
	T item;
	Node<T>* Next;

public:
	Node(T t) {
		item = t;
	Next = nullptr;

	}
	  template <typename T>
		void SetItemNode(T t) {
		item = t;
	}
		void setNext(Node<T>* n) {
		Next = n;
	}
	T getitem() {
		return item;
	}
	Node<T>* getnext() {
		return Next;

	}
};


//nour
