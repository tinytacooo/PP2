// #include "NotationConverterInterface.hpp"
#include "NotationConverter.hpp"
#include <iostream>

int main() {
	int op = 1;		// user option
	Deque D;
	NotationConverter NC;

	while (op != 0) {
		std::cout << "Choose an option. 0 to quit.";
		std::cin >> op;
		// std::cout << "Choose a conversion (0 to quit): \n1. post to in  2. post to pre\n3. in to post  4. in  to pre\n5. pre  to in  6. pre to post\n";

		switch(op) {
			case 1: { 
				std::cout << "CASE1 \n";
				std::string s = "Hello, world!";
				std::string r;
				std::cout << "CASE1DONE0 \n";

				r = NC.postfixToInfix(s);
				std::cout << "CASE1DONE1 \n";
				std::cout << r << '\n';
				break; }
			case 0: { break; }
			default: { break; }
		}


/*
		std::cin >> op;
		char c;

		switch(op) {
			case  1: { std::cin >> c; D.insertFront(c, 1); break; }
			case  2: { std::cin >> c; D.insertBack(c, 1); break; }
			case  3: { break; }
			case  4: { D.removeFront(); break; }
			case  5: { D.removeBack(); break; }
			case  6: { std::cout << " >> " << D.front() << '\n'; break; }
			case  7: { std::cout << " >> " << D.back() << '\n'; break; }
			case  8: { std::cout << " >> " << D.empty() << '\n'; break; }
			case  9: { std::cout << " >> " << D.size() << '\n';  break; }
			default: break;
		}

		std::string s = D.printList(); std::cout <<  " LIST >> " << s << "  SIZE >> " << D.size() << '\n';
*/
	}

	return 0;
}