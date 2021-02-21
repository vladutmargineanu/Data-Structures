#include <fstream>
#include <iostream>

#include "Friends.h"

int main() {

#ifdef DEBUG
	std::ostream& out = std::cout;
#else
	std::ofstream file;
	file.open("Out/Lab2/task5.out");
	std::ostream& out = file;
#endif

	/* TODO: Create students (name, classNr, mathGrade):
		Will 8 9.0
		Dustin 8 8.1
		Mike 8 7,5 */

	/* TODO: Create a professor and add students to his list */

	/* TODO: Uncomment the following:

	professor.incStudentMathGrade(2);

	printPretty(out, professor.students[2]);*/

#ifndef DEBUG
	file.close();
#endif

	return true;
}
