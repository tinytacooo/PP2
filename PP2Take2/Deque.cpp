/*-----------------------*
   Deque.hpp
   Kelly Johnston
   COP 4530 Spring: PP2
 *-----------------------*/

#include "Deque.hpp"

void Deque::pushFront(const std::string &s) {
	if (front == -1 && back == -1) {
		front = 0;
		back = 0;
		arr[0] = s;
	} else {
//		if(isFull())
//			break;

		front--;
		if(front < 0 )
			front = MAX - 1;

		arr[front] = s;
	}

	size++;
}

void Deque::pushBack(const std::string &s) {
	if (front == -1 && back == -1) {
		front = 0;
		back = 0;
		arr[0] = s;
	} else {
		back++;
		if(back == MAX)
			back = 0;

		arr[back] = s;
	}

	size++;
}

const std::string Deque::popFront() {
//	if(isEmpty())
//		return;

	std::string ret = arr[front];
	arr[front] = "\0";

	if (size == 1 || size == 0) {
		back = -1;
		front = -1;
	} else {
		front++;
		if (front > MAX - 1)
			front = 0;
	}

	if(size != 0)
		size--;
	return ret;
}

const std::string Deque::popBack() {
//	if(isEmpty())
//		return;

	std::string ret = arr[back];
	arr[back] = "\0";

	if (size == 1 || size == 0) {
		back = -1;
		front = -1;
	} else {
		back--;
		if (back < 0)
			back = MAX-1;
	}

	if(size != 0)
		size--;
	return ret;
}

void Deque::printList() {
	std::cout << " >> (front=" << front << ", back=" << back << ") LIST:\n"; 
	for (int i = 0; i < MAX; i++) {
		std::cout << "\t" << i << "\t" << arr[i] << "\n";
	}
	std::cout<<'\n';
}