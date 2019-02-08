/*-----------------------*
   NotationConverter.cpp
   Kelly Johnston
   COP 4530 Spring: PP2
 *-----------------------*/

#include "NotationConverter.hpp"

/*------------------------*
 *   NOTATION CONVERTER   *
 *------------------------*/
std::string NotationConverter::postfixToInfix(std::string inStr) {
	Deque D;						// initialize deque to use

	std::stringstream ss(inStr);	// add expression to stringstream

	while(!ss.eof()) {
		std::string ret;			// string to return

		std::string temp;			// temp string to add character to Deque
		temp += ss.get();			// add character from string stream to temp variable

		if(isSpace(temp)) {
			continue;
		}
		else if(isOperator(temp)) {
			ret += "(" + D.popFront() + " " + temp + " " + D.popFront() + ")";
			D.popFront();
			D.pushFront(ret);
		}
		else if(isAlpha(temp)) {
			D.pushFront(temp);	// push contents of temp variable onto Deque
		} else {
			continue;
		}

		// D.printList();

	}
	// std::cout << D.getBack();
	return D.getBack();
}

//std::string NotationConverter::postfixToPrefix(std::string inStr);

std::string NotationConverter::infixToPostfix(std::string inStr) {
	Deque D;				// initialize deque to use
	std::string ret;		// string to return

	std::stringstream ss(inStr);	// add expression to stringstream

	while(!ss.eof()) {
		int curPrec = 0;

		std::string temp;			// temp string to add character to Deque
		temp += ss.get();			// add character from string stream to temp variable

		if(isOperator(temp)) {					// if current symbol is an operator, assign precedence
			curPrec = assignPrec(temp);
			// std::cout << "  >> ASSIGNED PREC: " << temp << " " << curPrec << "\n";
		}

		if(isSpace(temp)) {						// skip spaces
			// std::cout << "  >> FOUND SPACE\n";
			continue;
		}

		else if(isAlpha(temp)) {
			ret += " " + temp;
			// std::cout << "  >> FOUND ALPHA " << temp << "\n";
		}

		else if(temp == "(") {
			D.pushFront(temp);
			// std::cout << "  >> FOUND (\n";
		}

		else if(temp == ")") {
			// std::cout << "  >> FOUND )\n";
			while(!D.isEmpty() && D.getFront() != "(")
				ret += " " + D.popFront();

			if(!D.isEmpty() && D.getFront() == "(")
				D.popFront();
		}

		else if(isOperator(temp)) {
			// std::cout << "  >> FOUND OP\n";
			while(!D.isEmpty() && curPrec <= assignPrec(D.getFront()))
				ret += " " + D.popFront();

			D.pushFront(temp);
		}

		// D.printList();
	}

	while(!D.isEmpty())
		ret += " " + D.popFront();

	return ret.substr(1);
}

//std::string NotationConverter::infixToPrefix(std::string inStr);

//std::string NotationConverter::prefixToInfix(std::string inStr);

//std::string NotationConverter::prefixToPostfix(std::string inStr);

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

int NotationConverter::assignPrec(const std::string &s) {
	int ret;
	if(s == "+")
		ret = 1;
	else if(s == "-")
		ret = 2;
	else if(s == "/")
		ret = 3;
	else if(s == "*")
		ret = 4;
	else
		ret = 0;

	return ret;
}