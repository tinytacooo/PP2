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

	std::stringstream ss(inStr);	// string to concat operators and operands to push onto stack

	while(!ss.eof()) {
		std::string ret;			// string to return

		std::string temp;			// temp string to add character to Deque
		temp += ss.get();			// add character from string stream to temp variable

		if(isBadInput(temp))			// non-alpha, non-operator and non-space characters will throw an error
			throw("Error: Bad input");

		// skip spaces
		if(isSpace(temp)) {
			continue;
		}

		// when operator is encountered, surround it with relevant operands and push it onto the stack
		// as expressions are pushed onto the stack, concatenated expressions become operands that are being popped from the stack
		else if(isOperator(temp)) {
			ret += "(" + D.popFront() + " " + temp + " " + D.popFront() + ")";
			D.popFront();
			D.pushFront(ret);
		}

		// operands are just pushed onto the stack for later use
		else if(isAlpha(temp)) {
			D.pushFront(temp);	// push contents of temp variable onto Deque
		}

		// I think my function reached a null character at some point... this is to skip it if that happens.
		else {
			continue;
		}

	}

	return D.getBack();		// last expression left in the stack is the converted expression
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

		if(isBadInput(temp))			// non-alpha, non-operator and non-space characters will throw an error
			throw("Error: Bad input");

		// skip spaces
		if(isSpace(temp)) {
			continue;
		}

		// push operands onto stack
		else if(isAlpha(temp)) {
			D.pushFront(temp);
		}

		// when an operator is encountered, list operator followed by two operands
		// again, as expressions are pushed onto the stack, they become 'operands' that are being concatenated with the operator
		else if(isOperator(temp)) {
			ret += temp + " " + D.popFront() + " " + D.popFront(); 	// push contents of temp variable onto Deque
			D.pushFront(ret);
		}

		// skip possible bull characters
		else {
			continue;
		}
	}

	return D.getBack();		// last expression in the stack is the converted expression
}

/*----------------*
 *   IN -> POST   *
 *----------------*/
std::string NotationConverter::infixToPostfix(std::string inStr) {
	Deque D;				// initialize deque to use
	std::string ret;		// string to return - operators and operands will be concatenated into this string

	std::stringstream ss(inStr);	// add expression to stringstream

	while(!ss.eof()) {
		int curPrec = 0;

		std::string temp;			// temp string to add character to Deque
		temp += ss.get();			// add character from string stream to temp variable

		if(isBadInput(temp))
			throw("Error: Bad input");

		if(isOperator(temp)) {					// if current symbol is an operator, assign precedence
			curPrec = assignPrec(temp);			// (see helper function below for values)
		}

		if(isSpace(temp)) {						// skip spaces
			continue;
		}

		else if(isAlpha(temp)) {				// add space + operand to return string
			ret += " " + temp;
		}

		else if(temp == "(") {					// push opening parenthesis onto stack
			D.pushFront(temp);
		}

		else if(temp == ")") {
			while(!D.isEmpty() && D.getFront() != "(")		// when a closing parenthesis is encountered, pop items from stack until
				ret += " " + D.popFront();					// parenthesis is closed (by the corresponding opoeining parenthesis)

			if(!D.isEmpty() && D.getFront() == "(")			// get rid of opening parenthesis on stack
				D.popFront();
		}

		else if(isOperator(temp)) {
			while(!D.isEmpty() && curPrec <= assignPrec(D.getFront()))		// add operators with smaller precedence to return variable 
				ret += " " + D.popFront();

			D.pushFront(temp);												// push current operator onto stack - deal with it later
		}

	}

	while(!D.isEmpty())					// when initial expression is empty and sorted, pop off all the remaining operators/operands
		ret += " " + D.popFront();

	return ret.substr(1);				// return concatenated expression; get rid of space in front of it
}

/*---------------*
 *   IN -> PRE   *
 *---------------*/
std::string NotationConverter::infixToPrefix(std::string inStr) {
	std::string post = infixToPostfix(inStr);		// convert infix -> postfix -> prefix using existing expressions
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
		std::string ret;			// string to return
		std::string temp;			// temp string to add character to Deque
		temp += ss.get();			// add character from string stream to temp variable

		if(isBadInput(temp))			// throw error if bad input
			throw("Error: Bad input");

		if(isSpace(temp)) {							// skip spaces
			continue;
		}
		else if(isAlpha(temp)) {					// push operands onto stack
			D.pushFront(temp);
		}
		else if(isOperator(temp)) {					// if operator is encountered, surround it with relevant operands and push onto stack
			std::string temp_a = D.popFront();		// eventually, the whole converted expression will be pushed onto the stack
			std::string temp_b = D.popFront();
			ret += "(" + temp_a + " " + temp + " " + temp_b + ")";

			D.pushFront(ret);						// push concat expression onto stack
		}
	}

	return D.getBack();								// return converted expression
}

/*-----------------*
 *   PRE -> POST   *
 *-----------------*/
std::string NotationConverter::prefixToPostfix(std::string inStr) {
	std::string in = prefixToInfix(inStr);		// convert prefix -> infix -> postfix using existing functions
	return infixToPostfix(in);
}


/*----------------------------------*
 *									*
 *   NOTATION CONVERTER - HELPERS   *
 *									*
 *----------------------------------*/

// check for four allowed operators
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
// if((s>="a" && s<="z") || (s>="A" && s<="B"))  <-- because it's a string. duh.
bool NotationConverter::isAlpha(const std::string &s) {
	bool ret = false;
	if (s == "A" || s == "B" || s == "C" || s == "D" || s == "E" || s == "F" || s == "G" || s == "H" || s == "I" || s == "J" || s == "K" || s == "L" || s == "M" || s == "N" || s == "O" || s == "P" || s == "Q" || s == "R" ||s == "S" || s == "T" || s == "U" || s == "V" || s == "W" || s == "X" || s == "Y" || s == "Z" || s == "a" || s == "b" || s == "c" || s == "d" || s == "e" || s == "f" || s == "g" || s == "h" || s == "i" || s == "j" || s == "k" || s == "l" || s == "m" || s == "n" || s == "o" || s == "p" || s == "q" || s == "r" ||s == "s" || s == "t" || s == "u" || s == "v" || s == "w" || s == "x" || s == "y" || s == "z")
		ret = true;
	return ret;
}

// Hollywoo Stars and Celebrities: What Do They Know? Is This Character a Space? Do They Know Things?> Let's Find Out!
bool NotationConverter::isSpace(const std::string &s) {
	bool ret = false;
	if (s == " ")
		ret = true;
	return ret;
}

// check for non-alpha, non-space, non-operator characters
bool NotationConverter::isBadInput(const std::string &s) {
	bool ret = false;
	if (s == "!" || s == "@" || s == "#" || s == "%" || s == "^" || s == "&" || s == "_" || s == "=" || s == "{" || s == "}" || s == "[" || s == "]" || s == "|" || s == "\\" || s == "\"" || s == "'" || s == "<" || s == ">" ||s == "," || s == "." || s == "~" || s == "`" || s == "?" || s == "1" || s == "2" || s == "3" || s == "4" || s == "5" || s == "6" || s == "7" || s == "8" || s == "9" || s == "0")
		ret = true;
	return ret;
}

// assign precedence to operator. Probably could have put this in isOpertor(). Oh well `\( :) )/`
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