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
	std::cout << "NC CALLED\n";
	Deque D;
/*
	D.insertFront('a', 1);
	D.insertFront('b', 1);
	D.insertFront('c', 1);
*/
	std::stringstream ss(inStr);
	std::cout << "DONE0 ";

	// D.insertFront(ss.get(), 1);

	while(!ss.eof()) {
		D.insertFront(ss.get(), 1);
		std::cout << "DONE2 (" << D.front() << ')';
	}

	D.removeFront();
	std::cout << "DONE3\n";
	std::cout << D.front() << ' ' << D.back() << '\n';

	return "\nWow!";
}

/*std::string NotationConverter::postfixToPrefix(std::string inStr);

std::string NotationConverter::infixToPostfix(std::string inStr);

std::string NotationConverter::infixToPrefix(std::string inStr);

std::string NotationConverter::prefixToInfix(std::string inStr);

std::string NotationConverter::prefixToPostfix(std::string inStr); */