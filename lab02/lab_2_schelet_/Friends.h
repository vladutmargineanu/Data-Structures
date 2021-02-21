#ifndef __STUDENT_H
#define __STUDENT_H

#include <vector>
#include <stdio.h>
#include <string>

using namespace std;

class Professor;

class Student {
	friend class Professor;
private:
	/* char* cand be used instead of string */
	std::string name;
	int classNr;
	float mathGrade;

public:
	/* TODO: Implement Constructor method */

	/* TODO: Implement Copy Constructor method */

	/* TODO: Overload Copy Assignment operator */

	/* TODO: Implement Destructor method */

	/* TODO: Implement getter for each field: name, classNr, mathGrade*/

	/* TODO: Overload << operator - Friend function declaration
    friend std::ofstream &operator<<...*/

    /* TODO: printPretty - Friend function declaration 
    friend void printPretty(std::ostream &output...*/
};

/* TODO: Overload << operator - Friend function implementation 
		Student s should be printed as:
			Student: Name(s.name) classNr(s.classNr) MathGrade(s.mathGrade)\n */

/* TODO: printPretty - Friend function implementation 
		Student s should be printed as:
	Student s.name is in class s.classNr and has 
		the following grade: s.mathGrade)\n */

class Professor {
public: 
	std::string name;
	std::vector<Student> students;

	Professor(std::string name) {
		this->name = name;
	}

	/* TODO: Add student s to this->students
	void addStudent(const Student& s) {...} */

	/* TODO: Implement incStudentMathGrade method which gets an index, accesses
			student at that index and increments his mathGrade 
	void incStudentMathGrade(size_t index) {...} */
};

#endif