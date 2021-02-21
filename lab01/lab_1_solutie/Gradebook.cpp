#include <iostream>
#include <fstream>

#include "Gradebook.h"

int main() {

#ifdef DEBUG
	std::ostream& out = std::cout;
#else
	std::ofstream file;
	file.open("Out/Lab1/task4.out");
	std::ostream& out = file;
#endif

	Gradebook gb(10);

	for (int i = 0; i < 10; i++) {
		gb.addGrade(i);
		out << gb.average() << std::endl;
	}

	return 0;
}
