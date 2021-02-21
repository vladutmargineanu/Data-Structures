#include <iostream>
#include <string>

class Student {
private:
    int grade, age, friends;
    std::string name, school;

public:
    Student(int newGrade=0, int newAge=0, int newFriends=0,
            std::string newName="", std::string newSchool=""):
            grade(newGrade), age(newAge), friends(newFriends),
            name(newName), school(newSchool) {}

    int getGrade() { return this->grade; }
    int getAge() { return this->age; }
    int getFriends() { return this->friends; }

    std::string getName() { return this->name; }
    std::string getSchool() { return this->school; }

    friend std::ostream& operator<< (std::ostream &out, const Student &student); 
};

std::ostream& operator<< (std::ostream &out, const Student &student) {
    /* Operatorul << este prieten cu clasa Student, deci ii poate
       accesa membrii, chiar daca acestia sunt private. */
    out << "Studentul " << student.name << " are " <<
                           student.age << " ani, " <<
                           student.friends << " de prieteni si invata la " <<
                           student.school << "!\n";

    return out;

}