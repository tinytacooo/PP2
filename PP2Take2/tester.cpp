// #include "NotationConverterInterface.hpp"
#include "Deque.hpp"
#include "NotationConverter.hpp"
// #include <iostream>	// IN DEQUE_H

int main() {
	int op = 1;		// user option
	Deque D;
	NotationConverter NC;

	const std::string infix1 = "(A + B) ";
	const std::string infix2 = "((X + B) * (Y - D))";
	const std::string infix3 = "(((A + B) / (X + Y)) - R)";

	const std::string prefix1 = "+ / * x y g h";
	const std::string prefix2 = "-    /  x  y  g"; // Multiple Spaces Between Letters and Operators
	const std::string prefix3 = "- / x y * a b";

	const std::string postfix1 = "X Y + A B + *";
	const std::string postfix2 = "V C +";
	const std::string postfix3 = "H W * R Q - /";

	while(op != 0) {
		std::cout << "Enter an option, 0 to quit:\n";

		std::cin >> op;
		std::string r;
		// std::cout << "Choose a conversion (0 to quit): \n1. post to in  2. post to pre\n3. in to post  4. in  to pre\n5. pre  to in  6. pre to post\n";

		switch(op) {
			case 1: { r = NC.postfixToPrefix(postfix1); break; }
			case 2: { r = NC.postfixToPrefix(postfix2); break; }

			case 3: { r = NC.infixToPostfix(infix1); break; }
			case 4: { r = NC.infixToPostfix(infix3); break; }

			case 6: { r = NC.prefixToInfix(prefix1); break; }
			case 7: { r = NC.prefixToInfix(prefix2); break; }

/*			case 8: { std::string r = NC.postfixToInfix(postfix2); break; }
			case 9: { std::string r = NC.postfixToInfix(postfix2); break; }
*/
			case 0: { break; }
			default: { break; }
		}

		std::cout << "==" << r << "==";
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