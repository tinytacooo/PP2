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
		temp += ss.get();			// add character from string stream to temp variable

		if(isSpace(temp)) {
			continue;
		}
		else if(isOperator(temp)) {
		/*	while(isAlpha(D.front()))
				ret += D.removeFront();
			ret += temp;
			*/ std::cout << "FOUND OP\n";
		}
		else if(isAlpha(temp)) {
			D.insertBack(temp, 1);	// push contents of temp variable onto Deque
			std::cout << "FOUND ALPHA\n";
		}
		else {
			std::cout << "DID NOTHING\n";
		}

		
	}
	// D.removeFront();				// get rid of empty front node
	// END push characters from expression onto stack

	return ret;
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

// this hurts my eyeees
// thought it might be better than putting anothre library into the overhead for this program
// #mightberight
bool NotationConverter::isAlpha(const std::string &s) {
	bool ret = false;
	if (s == "A" || s == "B" || s == "C" || s == "D" || s == "E" || s == "F" || s == "G" || s == "H" || s == "I" || s == "J" || s == "K" || s == "L" || s == "M" || s == "N" || s == "O" || s == "P" || s == "Q" || s == "R" ||s == "S" || s == "T" || s == "U" || s == "V" || s == "W" || s == "X" || s == "Y" || s == "Z" || s == "a" || s == "b" || s == "c" || s == "d" || s == "e" || s == "f" || s == "g" || s == "h" || s == "i" || s == "j" || s == "k" || s == "l" || s == "m" || s == "n" || s == "o" || s == "p" || s == "q" || s == "r" ||s == "s" || s == "t" || s == "u" || s == "v" || s == "w" || s == "x" || s == "y" || s == "z")
		ret = true;
	return ret;
}

bool NotationConverter::isSpace(const std::string &s) {
	return (s == " ");
}