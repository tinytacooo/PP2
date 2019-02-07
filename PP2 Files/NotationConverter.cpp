/*-----------------------*
   NotationConverter.cpp
   Kelly Johnston
   COP 4530 Spring: PP2
 *-----------------------*/

#include "NotationConverter.hpp"
// #include <iostream>

/*------------------------*
 *   NOTATION CONVERTER   *
 *------------------------*/
std::string NotationConverter::postfixToInfix(std::string inStr) {
	Deque D;							// initialize deque to use

	std::stringstream ss(inStr);		// add expression to stringstream

	// BEGIN push characters from expression onto stack
	while(!ss.eof()) {
		std::string g;
		g += ss.get();
		D.insertFront(g, 1);
	}
	D.removeFront();
	// END push characters from expression onto stack

	return D.printList();
}

/*std::string NotationConverter::postfixToPrefix(std::string inStr);

std::string NotationConverter::infixToPostfix(std::string inStr);

std::string NotationConverter::infixToPrefix(std::string inStr);

std::string NotationConverter::prefixToInfix(std::string inStr);

std::string NotationConverter::prefixToPostfix(std::string inStr); */