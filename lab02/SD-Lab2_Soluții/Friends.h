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
	Student(string name, int classNr, float mathGrade) {
		this->name = name;
		this->classNr = classNr;
		this->mathGrade = mathGrade;
	}

	Student(const Student &s) {
		this->name = s.getName();
		this->classNr = s.getClassNr();
		this->mathGrade = s.getMathGrade();
	}

	Student& operator=(const Student &s) {
		if (&s == this) {
			return *this;
		}

		// Nothing to delete here before re-assignment
		this->name = s.getName();
		this->classNr = s.getClassNr();
		this->mathGrade = s.getMathGrade();

		return *this;
	}

	~Student() {
		// Nothing to delete here
	}

	string getName() const {
		return this->name;
	}

	int getClassNr() const {
		return this->classNr;
	}

	float getMathGrade() const {
		return this->mathGrade;
	}

	friend std::ostream& operator<<(std::ostream &out, const Student &s);

    friend void printPretty(std::ostream &out, const Student &s);
};

std::ostream& operator<<(std::ostream &out, const Student &s) {
    out << "Student: Name(" << s.name << ") classNr(" <<  s.classNr 
    	<< ") MathGrade(" << s.mathGrade << ")\n";
    
    return out;
}

void printPretty(std::ostream &out, const Student &s) {
    out << "Student " << s.name << " is in class " <<  s.classNr 
    	<< " and has the following grade: " << s.mathGrade << "\n";
}

class Professor {
public: 
	std::string name;
	std::vector<Student> students;

	Professor(std::string name) {
		this->name = name;
	}

	void addStudent(const Student& s) {
		this->students.push_back(s);
	}

	void incStudentMathGrade(size_t index) {
		if (index < this->students.size()) {
			students[index].mathGrade++;
		}
	}
};

#endif
