#include <fstream>
#include <iostream>

#include "Complex.h"

#define DEBUG 1

int main() {

#ifdef DEBUG
	std::ostream& out = std::cout;
#else
	std::ofstream file;
	file.open("Out/Lab2/task1.out");
	std::ostream& out = file;
#endif

	Complex c1(2, 3);
	Complex c2(4.2, 5);

	out << "Print initial values: \n";
	out << c1 << c2;
	out << "\n";

	// Copy constructor will be called
	Complex sum = c1 + c2;
	Complex diff = c1 - c2;
	Complex product = c1 * c2;

	out << "Compute sum => ";
	out << sum;
	out << "Compute difference => ";
	out << diff;
	out << "Compute product => ";
	out << product;

	// Assignment operator will be called
	c2 = c1;

	out << "Check Assignment operator => ";
	out << c2;

#ifndef DEBUG
	file.close();
#endif

	return 0;
}
