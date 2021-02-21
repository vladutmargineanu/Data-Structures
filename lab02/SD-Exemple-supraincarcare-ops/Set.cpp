#include <iostream>

#include "Set.h"

int main() {
	Set<int> set = Set<int>(10), other = Set<int>(5);
	std::vector<int> elems = {7, 8, 9};

	set += 1;
	set += 2;
	set += 3;

	std::cout << "Initial: " << set;
	std::cout << "After adding more elems at once: ";
	set += elems;
	std::cout << set;

	std::cout << "Deleting some elems...\n";
	set -= 4;
	set -= 2;

	std::cout << set;

	other += {5, 7, 8};
	std::cout << "New set: " << other;
	set == other ? std::cout << "Sets are the same!\n" :
				std::cout << "Sets are different!\n";

	return 0;
}