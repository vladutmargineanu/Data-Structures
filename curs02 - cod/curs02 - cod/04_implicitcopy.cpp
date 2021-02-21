#include <string>
#include <iostream>

class person
{
    std::string name;
    int age;

public:

    person(const std::string& name, int age) : name(name), age(age)
    {
    }

    std::string getName() {
      return name;
    }
};

int main()
{
    person a("Bjarne Stroustrup", 60);
    person b(a);   // What happens here?
    std::cout<<b.getName()<<std::endl;
    b = a;         // And here?
    std::cout<<b.getName()<<std::endl;
}
