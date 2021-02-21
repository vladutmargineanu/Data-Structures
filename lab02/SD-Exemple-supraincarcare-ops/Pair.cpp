#include <iostream>

#include "Pair.h"

int main() {
	Pair<int, float> pair1 = Pair<int, float>(2, 4.5),
		pair2 = Pair<int, float>(3, 5.5), pair3 = Pair<int, float>(3, 5.5), 
		pair4 = Pair<int, float>(pair1 + pair2);

	std::cout << "---Initial pairs--- \n";
	
	std::cout << "Pair1 " << pair1;
	std::cout << "Pair2 " << pair2;
	std::cout << "Pair3 " << pair3;
	std::cout << "Pair4 " << pair4;

	std::cout << "---After sum--- \n" << pair4 << std::endl;

	pair1 < pair2 ? std::cout << "Second pair is greater!\n" :
					std::cout << "First pair is greater!\n";

	pair2 == pair3 ? std::cout << "Yep, pair2 and pair3 are equal!\n" :
					std:: cout << "Nope, pair2 and pai3 are not equal!\n";

	pair1 == pair3 ? std::cout << "Yep, pair1 and pair3 are equal!\n" :
					std:: cout << "Nope, pair1 and pai3 are not equal!\n";

	return 0;
}