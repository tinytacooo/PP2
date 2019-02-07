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
	std::string postfixToInfix(std::string inStr);
	/* std::string postfixToPrefix(std::string inStr);

	std::string infixToPostfix(std::string inStr);
	std::string infixToPrefix(std::string inStr);

	std::string prefixToInfix(std::string inStr);
	std::string prefixToPostfix(std::string inStr);
	*/
};

#endif /* NOTATIONCONVERTER_H */