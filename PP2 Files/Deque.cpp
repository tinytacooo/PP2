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
	return head->str;
}

const std::string& Deque::back() {
	return tail->str;
}

/* Edit deque */
void Deque::insertBack(const std::string &s, const int &pr){
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));	// Allocate space for a new node

	newNode->str = s;		// add information to new node
	newNode->prec = pr;
	newNode->next = NULL;	// new node is at the END; no node comes after it

	if (tail != NULL) {
		newNode->prev = tail;	// connect newNode to the end of the list
		tail->next = newNode;
		tail = newNode;			// set new node as the last entity in the list
	} else {
		head = newNode;
		tail = newNode;
	}

	n++;		// increase list size
}

void Deque::insertFront(const std::string &s, const int &pr) {
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));	// Allocate space for a new node

	newNode->str = s;			// Add information to new node
	newNode->prec = pr;
	newNode->prev = NULL;		// Node is at the FRONT; no node comes before it

	if (head != NULL) {
		newNode->next = head;	// Link node to start of list
		head->prev = newNode;		
		head = newNode;			// set new node as the start of the list
	} else {
		head = newNode;
		tail = newNode;
	}

	n++;		// increase list size
}

const std::string Deque::removeBack() {
	struct Node *temp = tail->prev;		// 
	std::string s = tail->str;			// store character to return
	tail = tail->prev;					// 

		if(tail != NULL) {		
			tail->next = NULL;
		} else {
			head = NULL;		// if there's only one node in the list, just reset HEAD and TAIL nodes
			tail = NULL;
		}

		free(temp);		// free memory at (previous) tail node
		n--;			// decrease size of list

	return s;			// return char previously at end of list
}

const std::string Deque::removeFront() {
	struct Node *temp = head;			// 
	std::string s = head->str;				// store character to return
	head = head->next;					// 
	
	if (head != NULL) {
		head->prev = NULL;
	} else {
		head = NULL;
		tail = NULL;
	}

	free(temp);		// free memory at (previous) head node
	n--;			// decrease size of list

	return s;		// return char previously at front of list
}

/* REMOVE - TEST FUNCTIONS */
std::string Deque::printList() {
	std::stringstream ss;

	struct Node* ptr = head;

	while (ptr != NULL) {
		ss << ptr->str;
		ptr = ptr->next;
	}

	free(ptr);
	return ss.str();
}