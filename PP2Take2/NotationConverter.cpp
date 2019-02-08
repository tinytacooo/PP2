/*-----------------------*
   NotationConverter.cpp
   Kelly Johnston
   COP 4530 Spring: PP2
 *-----------------------*/

#include "NotationConverter.hpp"

/*------------------------*
 *						  *
 *   NOTATION CONVERTER   *
 *						  *
 *------------------------*/

/*----------------*
 *   POST -> IN   *
 *----------------*/
std::string NotationConverter::postfixToInfix(std::string inStr) {
	Deque D;						// initialize deque to use

	std::stringstream ss(inStr);	// add expression to stringstream

	while(!ss.eof()) {
		std::string ret;			// string to return

		std::string temp;			// temp string to add character to Deque
		temp += ss.get();			// add character from string stream to temp variable

		if(temp == "[" || temp == "]" || temp == "\\" || temp == "{" || temp == "}" || temp == "^")
			throw("Error: Bad input");

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

	}

	return D.getBack();
}

/*-----------------*
 *   POST -> PRE   *
 *-----------------*/
std::string NotationConverter::postfixToPrefix(std::string inStr){
	Deque D;						// initialize deque to use

	std::stringstream ss(inStr);	// add expression to stringstream

	while(!ss.eof()) {
		std::string ret;			// string to return

		std::string temp;			// temp string to add character to Deque
		temp += ss.get();			// add character from string stream to temp variable

		if(temp == "[" || temp == "]" || temp == "\\" || temp == "{" || temp == "}" || temp == "^")
			throw("Error: Bad input");

		if(isSpace(temp)) {
			continue;
		}
		else if(isAlpha(temp)) {
			D.pushFront(temp);
		}
		else if(isOperator(temp)) {
			ret += temp + " " + D.popFront() + " " + D.popFront(); 	// push contents of temp variable onto Deque
			D.pushFront(ret);
		} else {
			continue;
		}

	}
	return D.getBack();
}

/*----------------*
 *   IN -> POST   *
 *----------------*/
std::string NotationConverter::infixToPostfix(std::string inStr) {
	Deque D;				// initialize deque to use
	std::string ret;		// string to return

	std::stringstream ss(inStr);	// add expression to stringstream

	while(!ss.eof()) {
		int curPrec = 0;

		std::string temp;			// temp string to add character to Deque
		temp += ss.get();			// add character from string stream to temp variable

		if(temp == "[" || temp == "]" || temp == "\\" || temp == "{" || temp == "}" || temp == "^")
			throw("Error: Bad input");

		if(isOperator(temp)) {					// if current symbol is an operator, assign precedence
			curPrec = assignPrec(temp);
		}

		if(isSpace(temp)) {						// skip spaces
			continue;
		}

		else if(isAlpha(temp)) {
			ret += " " + temp;
		}

		else if(temp == "(") {
			D.pushFront(temp);
		}

		else if(temp == ")") {
			while(!D.isEmpty() && D.getFront() != "(")
				ret += " " + D.popFront();

			if(!D.isEmpty() && D.getFront() == "(")
				D.popFront();
		}

		else if(isOperator(temp)) {
			while(!D.isEmpty() && curPrec <= assignPrec(D.getFront()))
				ret += " " + D.popFront();

			D.pushFront(temp);
		}

	}

	while(!D.isEmpty())
		ret += " " + D.popFront();

	return ret.substr(1);
}

/*---------------*
 *   IN -> PRE   *
 *---------------*/
std::string NotationConverter::infixToPrefix(std::string inStr) {
	std::string post = infixToPostfix(inStr);
	return postfixToPrefix(post);
}

/*---------------*
 *   PRE -> IN   *
 *---------------*/
std::string NotationConverter::prefixToInfix(std::string inStr) {
	Deque D;				// initialize deque to use
	std::string rev;

	for(int i = inStr.length()-1; i > -1; i--)
		rev += inStr.at(i);

	std::stringstream ss(rev);	// add expression to stringstream

	while(!ss.eof()) {
		// std::cout << "CATCH1" << "" << "\n";
		std::string ret;			// string to return
		std::string temp;			// temp string to add character to Deque
		temp += ss.get();			// add character from string stream to temp variable

		if(temp == "[" || temp == "]" || temp == "\\" || temp == "{" || temp == "}" || temp == "^")
			throw("Error: Bad input");

		//std::cout << "CATCH2" << "" << "\n";
		if(isSpace(temp)) {
			continue;
		}
		else if(isAlpha(temp)) {
			D.pushFront(temp);
		}
		else if(isOperator(temp)) {
			std::string temp_a = D.popFront();
			std::string temp_b = D.popFront();
			ret += "(" + temp_a + " " + temp + " " + temp_b + ")";

			D.pushFront(ret);
		}
	}

	return D.getBack();
}

/*-----------------*
 *   PRE -> POST   *
 *-----------------*/
std::string NotationConverter::prefixToPostfix(std::string inStr) {
	std::string in = prefixToInfix(inStr);
	return infixToPostfix(in);
}


/*----------------------------------*
 *									*
 *   NOTATION CONVERTER - HELPERS   *
 *									*
 *----------------------------------*/

bool NotationConverter::isOperator(const std::string &s) {
	bool ret = false;
	if (s == "+" || s == "-" || s == "*" || s == "/")
		ret = true;
	return ret;
}

// this hurts my eyeees
// thought it might be better than putting another library into the overhead for this program
// #mightberight
// turns out is is
// guess what didn't work??
// if((s>="a" && s<="z") || (s>="A" && s<="B"))
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