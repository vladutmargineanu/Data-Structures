#include <iostream>
#include <fstream>

#include "Complex.h"

int main() {

#ifdef DEBUG
	std::ostream& out = std::cout;
#else
	std::ofstream file;
	file.open("Out/Lab1/task2.out");
	std::ostream& out = file;
#endif

	Complex c1(2, 3);
	Complex c2(5.1, 2);

	out << c1.getRe() << " " << c1.getIm() << std::endl;
	out << c2.getRe() << " " << c2.getIm() << std::endl;

	double mod1 = c1.modulus();
	double mod2 = c2.modulus();

	out << mod1 << std::endl;
	out << mod2 << std::endl;

	Complex sum1 = c1.add(c2);
	Complex sum2 = c2.add(c2);

	out << sum1.getRe() << " " << sum1.getIm() << std::endl;
	out << sum2.getRe() << " " << sum2.getIm() << std::endl;

	Complex prod1 = c1.multiply(c2);
	Complex prod2 = c2.multiply(prod1);

	out << prod1.getRe() << " " << prod1.getIm() << std::endl;
	out << prod2.getRe() << " " << prod2.getIm() << std::endl;

	return 0;
}
