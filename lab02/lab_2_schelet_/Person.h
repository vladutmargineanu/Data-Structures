#ifndef __PERSON_H
#define __PERSON_H

#include <stdio.h>
#include <string.h>
#define NMAX 256

class Person {
public:
	char* name;
	int age;

	/* TODO: Implement constructor method 
	Person(char* newName, int newAge) {
	}*/
	Person(char* newName, int newAge){
		this -> age = newAge;
		strcpy(name, newName);
	}

	/* TODO: Add copy constructor method */
    Person(const Person& other):
      age(other.age),
      name(other.name){}

    /* TODO: Overload copy assignment operator */
	Person& operator=(const Person& p){
	    if (this != &p) {        // Evitare auto-atribuire
		    if(name) {              // Curatare
		      delete [] name;
		    }
		       
		    age = p.age;             // Copiere
		    name = new char[256];
		    strcpy(name, p.name);
	    }
	 
	          return *this;            // Intoarce referinta la obiectul modificat
    }
 

	/* TODO: Add destructor method */
     ~Person(){}
     
	
	/* TODO: Overload << operator - Friend function declaration
    friend std::ofstream &operator<<...*/
     
     friend std::ostream &operator<<(std::ostream &out, const Person &p);
};

/* TODO: Overload << operator - Friend function implementation 
		Person p should be printed as:
			p.name's age is p.age\n */
   std::ostream &operator<<(std::ostream &out, const Person &p){
   	out << p.name <<"'s age is " << p.age <<"\n";
   	return out;

   }

#endif