#include <fstream>
#include <iostream>

#include "Fraction.h"

int main() {

#ifdef DEBUG
	std::ostream& out = std::cout;
#else
	std::ofstream file;
	file.open("Out/Lab2/task2.out");
	std::ostream& out = file;
#endif

	Fraction f1(1, 2);
	Fraction f2(2, 3);

	out << "Initial values: " << "\n";
	out << f1 << f2;
	out << "\n";

	out << f1.getValue() << "\n" << f2.getValue() << "\n";

	Fraction prod = f1 * f2;
	Fraction div = f1 / f2;

	out << "Compute product => ";
	out << prod;
	out << "Compute division =>  ";
	out << div;

#ifndef DEBUG
	file.close();
#endif

	return 0;
}
