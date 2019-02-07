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
const char& Deque::front() {	// ADD THROWS
	try{
		if (head == NULL)
			throw("Error: Can't peek an empty deque!");

		return head->c;
	}
	catch(const char* msg) {
		std::cout << msg << '\n';
	}

}

const char& Deque::back() {	// ADD THROWS
	try{
		if (head == NULL)
			throw("Error: Can't peek an empty deque!");

		return tail->c;
	}
	catch(const char* msg) {
		std::cout << msg << '\n';
	}
}

/* Edit deque */
void Deque::insertBack(const char &ch, const int &pr){
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));	// Allocate space for a new node

	newNode->c = ch;		// add information to new node
	newNode->prec = pr;
	newNode->next = NULL;	// new node is at the END; no node comes after it

	if (tail != NULL) {
		newNode->prev = tail;	// connect newNode to the end of the list
		tail->next = newNode;
		tail = newNode;			// set new node as the last entity in the list
	} else {
		head = newNode;			// if newNode is the only node in the list, new node is the head and tail
		tail = newNode;
	}

	n++;		// increase list size
}

void Deque::insertFront(const char &ch, const int &pr) {
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));	// Allocate space for a new node

	newNode->c = ch;			// Add information to new node
	newNode->prec = pr;
	newNode->prev = NULL;		// Node is at the FRONT; no node comes before it

	if (head != NULL) {
		newNode->next = head;	// Link node to start of list
		head->prev = newNode;		
		head = newNode;			// set new node as the start of the list
	} else {
		head = newNode;			// if newNode is the only node in the list, new node is the head and tail
		tail = newNode;
		tail->next = head;
	}

	n++;		// increase list size
}

void Deque::removeBack() {	// ADD THROWS
	try {
		// handle empty deque exception
		if(head == NULL)
			throw("Error: Can't remove item from empty deque!");

		if(n > 1) {
			struct Node *temp = tail->prev;		// store address of prev node
			tail->c = temp->c;					// copy data to temp node
			tail->prec = temp->prec;
			tail->prev = temp->prev;			// cut out uneeded node
			free(temp);							// free memory at (previous) tail node
		} else {
			head = NULL;		// if there's only one node in the list, just reset HEAD and TAIL nodes
			tail = NULL;
		}

		n--;	// decrease size of list
	}

	// REMOVE CATCH
	catch(const char* msg) {
		std::cout << msg << '\n';
	}
}

void Deque::removeFront() {	// ADD THROWS
	try {
		// handle empty deque exception
		if(head == NULL)
			throw("Error: Can't remove item from empty deque!");

		struct Node *temp = head;			// store address of next node
		head = head->next;					// copy data to temp node
		free(temp);							// free memory at (previous) head node
		
		if (head != NULL)
			head->prev = NULL;

		n--;	// decrease size of list
	}

	// REMOVE CATCH
	catch(const char* msg) {
		std::cout << msg << '\n';
	}
}

/* REMOVE - TEST FUNCTIONS */
std::string Deque::printList() {
	std::stringstream ss;

	struct Node* ptr = head;

	while (ptr != NULL) {
		ss << ' ' << ptr->c << ' ';
		ptr = ptr->next;
	}

	free(ptr);
	return ss.str();
}