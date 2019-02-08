/*-----------------------*
   Deque.hpp
   Kelly Johnston
   COP 4530 Spring: PP2
 *-----------------------*/

#include "Deque.hpp"

// Deque implementation using circular array.

void Deque::pushFront(const std::string &s) {
	// empty array initially has front and back cursors = -1.
	// when the first element is added to the array, the cursors are made to point to the first element in the array.
	if (front == -1 && back == -1) {
		front = 0;
		back = 0;
		arr[0] = s;
	}
	// when array already has elements, front cursor is pushed back to point at a new cell. Data is copied into this cell.
	else {
		front--;
		if(front < 0 )
			front = MAX - 1;

		arr[front] = s;
	}

	size++;		// Increase size of deque
}

void Deque::pushBack(const std::string &s) {
	// empty array initially has front and back cursors = -1.
	// when the first element is added to the array, the cursors are made to point to the first element in the array.
	if (front == -1 && back == -1) {
		front = 0;
		back = 0;
		arr[0] = s;
	}
	// when array already has elements, back cursor is pushed forwards; data is copied into new cell.
	else {
		back++;
		if(back == MAX)
			back = 0;

		arr[back] = s;
	}

	size++;		// Increase size of deque
}

// pop functions return the popped element
const std::string Deque::popFront() {
	std::string ret = arr[front];		// get string to return when function exits
	arr[front] = "\0";					// clear array cell

	if (size == 1 || size == 0) {		// if deque is empty, reset front and back cursors to -1
		back = -1;
		front = -1;
	} else {							// if deque still has elements, move front cursor up
		front++;
		if (front > MAX - 1)			// if front cursor goes outside the bounds to the array, loop cursor around to front of array
			front = 0;
	}

	if(size != 0)			// adjust size of deque; deque size cannot be less than 0
		size--;				// (I have to do this because pop functions can still be called on an empty deque)
	return ret;
}

const std::string Deque::popBack() {
	std::string ret = arr[back];		// string to return
	arr[back] = "\0";					// clear array cell

	if (size == 1 || size == 0) {		// if deque is empty, reset cursors
		back = -1;
		front = -1;
	} else {							// if deque still has elements, move back cursor backwards
		back--;
		if (back < 0)					// loop back cursor to end of array is cursor goes out of array bounds
			back = MAX-1;
	}

	if(size != 0)			// adjust size of deque
		size--;				// size of deque may not be negative
	return ret;
}


// TEST FUNCTION - disregard
/*
void Deque::printList() {
	std::cout << " >> (front=" << front << ", back=" << back << ") LIST:\n"; 
	for (int i = 0; i < MAX; i++) {
		std::cout << "\t" << i << "\t" << arr[i] << "\n";
	}
	std::cout<<'\n';
}
*/