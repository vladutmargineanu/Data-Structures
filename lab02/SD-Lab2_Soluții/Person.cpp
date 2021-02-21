#include <fstream>
#include <iostream>

#include "Person.h"

int main() {

#ifdef DEBUG
	std::ostream& out = std::cout;
#else
	std::ofstream file;
	file.open("Out/Lab2/task4.out");
	std::ostream& out = file;
#endif

	char name1[] = "Robin";
	char name2[] = "Starfire";
	char name3[] = "Raven";

	Person p1(name1, 18);
	Person p2(name2, 17);
	Person p3(name3, 100);

	out << "Initial value ";
	out << p3;

	p3 = p2;

	out << "After asignment: ";
	out << p3;

#ifndef DEBUG
	file.close();
#endif

	return 0;
}
