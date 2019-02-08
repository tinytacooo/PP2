/*-----------------------*
   NotationConverter.hpp
   Kelly Johnston
   COP 4530 Spring: PP2
 *-----------------------*/

#ifndef NOTATIONCONVERTER_H
#define NOTATIONCONVERTER_H

#include "NotationConverterInterface.hpp"
#include "Deque.hpp"

/*------------------------*
 *   NOTATION CONVERTER   *
 *------------------------*/
class NotationConverter : public NotationConverterInterface {
public:
	/* From NotationConverterInterface */
	std::string postfixToInfix(std::string inStr);
	std::string postfixToPrefix(std::string inStr);
	std::string infixToPostfix(std::string inStr);
	std::string infixToPrefix(std::string inStr);
	std::string prefixToInfix(std::string inStr);
	std::string prefixToPostfix(std::string inStr);

	/* Helper functions */
	bool isAlpha(const std::string &s);
	bool isBadInput(const std::string &s);
	bool isOperator(const std::string &s);
	bool isSpace(const std::string &s);
	int assignPrec(const std::string &s);
};

#endif /* NOTATIONCONVERTER_H */