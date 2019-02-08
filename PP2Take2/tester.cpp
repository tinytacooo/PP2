// #include "NotationConverterInterface.hpp"
#include "Deque.hpp"
#include "NotationConverter.hpp"
// #include <iostream>	// IN DEQUE_H

int main() {
	int op = 1;		// user option
	Deque D;
	NotationConverter NC;

	while(op != 0) {
		std::cout << "Enter an option, 0 to quit:\n";

		std::cin >> op;
		// std::cout << "Choose a conversion (0 to quit): \n1. post to in  2. post to pre\n3. in to post  4. in  to pre\n5. pre  to in  6. pre to post\n";

		switch(op) {
			case 1: { 
				std::string s = "A B +";
				std::string r = NC.postfixToInfix(s);
				std::cout << r << '\n';
				break; }
			case 2: { 
				std::string s = "(((A + B) / (X + Y)) - R)";
				std::string r = NC.infixToPostfix(s);
				std::cout << "--" << r << "--\n";
				break; }
			case 0: { break; }
			default: { break; }
		}
/*
		std::cin >> op;
		std::string c;

		switch(op) {
			case  1: { D.pushFront("HI"); break; }
			case  2: { D.pushBack("BI"); break; }
			case  3: { D.printList(); break; }
			case  4: { std::cout << " >> POPFRONT- " << D.popFront() << '\n'; break; }
			case  5: { std::cout << " >> POPBACK - " << D.popBack() << '\n'; break; }
			case  6: { std::cout << " >> FRONT: " << D.getFront() << '\n'; break; }
			case  7: { std::cout << " >> BACK: " << D.getBack() << '\n'; break; }
//			case  8: { std::cout << " >> " << D.empty() << '\n'; break; }
			case  9: { std::cout << " >> SIZE: " << D.getSize() << '\n';  break; }
			default: break;
		}
		D.printList();

//		std::string s = D.printList(); std::cout <<  " LIST >> " << s << "  SIZE >> " << D.size() << '\n';
*/
	}

	return 0;
}