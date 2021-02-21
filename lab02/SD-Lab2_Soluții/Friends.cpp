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
	
	Student *student1 = new Student("Will", 8, 9.0); 
	Student *student2 = new Student("Dustin", 8, 8.1);
	Student *student3 = new Student("Mike", 8, 7.5);

	Professor* professor = new Professor("Scott");

	professor->addStudent(*student1);
	professor->addStudent(*student2);
	professor->addStudent(*student3);

	professor->incStudentMathGrade(2);

	printPretty(out, professor->students[2]);

	delete student1;
	delete student2;
	delete student3;

	delete professor;

#ifndef DEBUG
	file.close();
#endif

	return true;
}
