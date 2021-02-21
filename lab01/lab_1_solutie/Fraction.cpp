#include <iostream>
#include <fstream>

#include "Fraction.h"

int main() {

#ifdef DEBUG
	std::ostream& out = std::cout;
#else
	std::ofstream file;
	file.open("Out/Lab1/task3.out");
	std::ostream& out = file;
#endif

	Fraction f1(2, 3);
	Fraction f2(5.1, 2);

	out << f1.getNum() << " " << f1.getDenom() << "\n";
	out << f2.getNum() << " " << f2.getDenom() << "\n";

	double d1 = f1.decimal();
	double d2 = f2.decimal();

	out << d1 << "\n" << d2 << "\n";

	Fraction prod1 = f1.multiply(f2); //inmultire f1 cu f2
	Fraction prod2 = f2.multiply(f2);  //inmultire f2 cu f2

	out << prod1.getNum() << " " << prod1.getDenom() << std::endl;
	out << prod2.getNum() << " " << prod2.getDenom() << std::endl;


	Fraction div1 = f1.divide(f2);  //impartire f1 / f2
	Fraction div2 = f2.divide(div1);

	out << div1.getNum() << " " << div1.getDenom() << std::endl;
	out << div2.getNum() << " " << div2.getDenom() << std::endl;

	return 0;
}
