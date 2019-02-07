#ifndef DEQUE_H
#define DEQUE_H

#include <string>
#include <iostream>

const int MAX = 4;

class Deque {
private:
	std::string arr[MAX];
	int front = -1;
	int back = -1;
	int size = 0;
public:
	// Deque();
	// ~List();

	/* Edit Deque */
	void pushFront(const std::string &s);
	void pushBack(const std::string &s);
	const std::string popFront();
	const std::string popBack();

	/* Interact with Deque */
	int getSize() { return size; }
	bool isEmpty() { return (size == 0); }
	bool isFull() { return (size == MAX-1); }
	const std::string getFront() { return arr[front]; }
	const std::string getBack() { return arr[back]; }

	/* Tester functions - REMOVE */
	void printList();
};
#endif