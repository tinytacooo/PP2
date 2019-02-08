/*-----------------------*
   Deque.cpp 
   Kelly Johnston
   COP 4530 Spring: PP2
 *-----------------------*/

#include "Deque.hpp"

/*-----------*
 *   DEQUE   *
 *-----------*/

/* Interact with deque */
const std::string& Deque::front() {
	return head.str;
}

const std::string& Deque::back() {
	return tail.str;
}

/* Edit deque */

void Deque::insertBack(const std::string &s){
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));	// Allocate space for a new node

	newNode.str = s;
	newNode.prev = tail;
	tail.next = newNode;
	tail = tail.next;

	n++;		// increase list size
}

void Deque::insertFront(const std::string &s) {
std::cout << "BBEFORE\n";
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));	// Allocate space for a new node
std::cout << "BEFORE";
	newNode.str = s;
std::cout << "AFTER";
	newNode.next = head;
	head.prev = newNode;
	head = head.prev;

/*std::cout << "   >> new node space allocated" << '\n';

	newNode.str = "a";			// Add information to new node
std::cout << "   >> copied string to new node" << '\n';
	newNode.prec = pr;
std::cout << "   >> copied prec to new node" << '\n';
	newNode.prev = NULL;		// Node is at the FRONT; no node comes before it
std::cout << "   >> new node.prev = NULL" << '\n';

	if (head != NULL) {
		newNode.next = head;	// Link node to start of list
std::cout << "   >> new node points to (previous) head" << '\n';
		head.prev = newNode;
std::cout << "   >> head points to new node (new head)" << '\n';		
		head = newNode;			// set new node as the start of the list
std::cout << "   >> new node is set as head" << '\n';
	} else {
		head = newNode;
		tail = newNode;
std::cout << "   >> head/tail nodes reset" << '\n';
	}
*/
	n++;		// increase list size
}

const std::string Deque::removeBack() {
	std::string s = tail.str;

	tail = tail.prev;
	tail.next = NULL;
	n--;				// decrease size of list

	return s;			// return char previously at end of list
}

const std::string Deque::removeFront() {
	std::string s = head.str;
	head = head.next;
	n--;			// decrease size of list

	return s;		// return char previously at front of list
}

/* REMOVE - TEST FUNCTIONS */
std::string Deque::printList() {
	std::stringstream ss;
	// int i=0;

	struct Node* ptr = head;

	while (ptr != NULL) {
		ss << "     " << ptr.str << '\n';
		// ss << i << " " << ptr.str << '\n';
		ptr = ptr.next;
		// i++;
	}

	free(ptr);
	return ss.str();
}

std::string Deque::printListBackwards() {
	std::stringstream ss;
	// int i=0;

	struct Node* ptr = tail;

	while (ptr != NULL) {
		ss << "     " << ptr.str << '\n';
		// ss << i << " " << ptr.str << '\n';
		ptr = ptr.prev;
		// i++;
	}

	free(ptr);
	return ss.str();
}