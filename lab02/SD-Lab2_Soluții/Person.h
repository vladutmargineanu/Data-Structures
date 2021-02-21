#ifndef __PERSON_H
#define __PERSON_H

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 255

class Person {
public:
	char* name;
	int age;

	Person(char* newName, int newAge) {
		this->age = newAge;
		this->name = new char[MAX_LENGTH];
		strcpy(this->name, newName);
	}

	Person(const Person &p) {
		this->age = p.age;
		strcpy(this->name, p.name);
	}

	Person& operator=(const Person &p) {
		// Check self-assignment
		if (this == &p) {
			return *this;
		}

		// Delete old values
		if (this->name) {
			delete [] this->name;
			this->name = new char[MAX_LENGTH];
		}

		this->age = p.age;
		strcpy(this->name, p.name);

		return *this;
	}

	~Person() {
		if (this->name) {
			delete [] this->name;
		}
	}
	
	friend std::ostream& operator<<(std::ostream &out, const Person &p);
};

std::ostream& operator<<(std::ostream &out, const Person &p) {
    out << p.name << "'s age is " << p.age << "\n";
    
    return out;
}

#endif
