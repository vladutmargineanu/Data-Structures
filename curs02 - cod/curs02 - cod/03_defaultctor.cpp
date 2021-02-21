#include <string>
#include <iostream>
using namespace std;

class Proprietar {
  string nume;
public:
  Proprietar(string nume = "Dacia") {
    this->nume = nume;
  }
  string getNume(){
    return nume;
  }
};

class Masina {
	Proprietar proprietar;

	public:
		Proprietar getProprietar () {
			return proprietar;
		}

    int* foo;
};

void sayHello(string who) {
  cout<<"Hello "<<who<<endl;
}

int main() {

  Masina m;
  sayHello(m.getProprietar().getNume());
  cout<<m.foo[0]<<endl;

}
