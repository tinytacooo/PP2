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
	Deque D;						// initialize deque to use
	std::string ret;				// string to return

	std::stringstream ss(inStr);	// add expression to stringstream

	// BEGIN push characters from expression onto stack
	while(!ss.eof()) {
		std::string temp;			// temp string to add character to Deque
		char ch = ss.get();
		temp += ch;			// add character from string stream to temp variable

		if(isSpace(temp)) {
			continue;
		} else if(isOperator(temp)) {
			// ret += removeFront();
			std::cout << "OP FOUND\n";
		} else if(std::isalpha(ch)) {
			std::cout << "ALPHA FOUND\n";
			D.insertBack(temp, 1);	// push contents of temp variable onto Deque
		} else {
			std::cout << "DID NOTHING\n";
		}

		
	}
	// D.removeFront();				// get rid of empty front node
	// END push characters from expression onto stack

	return D.printList();
}

/*std::string NotationConverter::postfixToPrefix(std::string inStr);

std::string NotationConverter::infixToPostfix(std::string inStr);

std::string NotationConverter::infixToPrefix(std::string inStr);

std::string NotationConverter::prefixToInfix(std::string inStr);

std::string NotationConverter::prefixToPostfix(std::string inStr); */

/*----------------------------------*
 *   NOTATION CONVERTER - HELPERS   *
 *----------------------------------*/

bool NotationConverter::isOperator(const std::string &s) {
	bool ret = false;
	if (s == "+" || s == "-" || s == "*" || s == "/")
		ret = true;
	return ret;
}

bool NotationConverter::isSpace(const std::string &s) {
	return (s == " ");
}