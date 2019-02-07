/*-----------------------*
   Deque.hpp
   Kelly Johnston
   COP 4530 Spring: PP2
 *-----------------------*/

#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <sstream>


/*-----------*
 *   NODES   *
 *-----------*/
struct Node {
    std::string str;		        // operand/operator from expression
    int prec = 1;					// precedence of operand/operator; determined by parenthesis/order
    struct Node *prev;
    struct Node *next;
};


/*-----------*
 *   DEQUE   *
 *-----------*/
class Deque {
public:
	/* Constructor, Destructor */
	// ~Deque();
	/* Interact with deque */
	int size() const { return n; }
	bool empty() const { return (head == NULL); }		// returns TRUE if empty
	const std::string& front();		// ADD THROWS
	const std::string& back();		// ADD THROWS
	/* Edit deque */
	void insertBack(const std::string &s, const int &pr);
	void insertFront(const std::string &s, const int &pr);
	const std::string removeBack();		// ADD THROWS
	const std::string removeFront();	// ADD THROWS
	/* REMOVE - TEST FUNCTIONS */
	std::string printList();
private:
	struct Node* head = NULL;
	struct Node* tail = NULL;
	int n = 0;
};

#endif