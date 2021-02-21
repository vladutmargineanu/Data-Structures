#include <iostream>
#include <string>

using namespace std;

class Dosar {
	int an_nastere;
	string tara;
	bool cautat;

	public:
	Dosar(){
		this->an_nastere = 0;
		this->tara = "";
		this->cautat = false;
	}

	Dosar(string input) {
		int firstComma = input.find_first_of(',');
		int secondComma = input.find_last_of(',');
		this->an_nastere = stoi(input.substr(0, firstComma));
		this->tara = input.substr(firstComma+1, secondComma-firstComma-1);
		this->cautat = (input.substr(secondComma+1, input.length()-secondComma).compare("true")==0);
	}

	Dosar(int an_nastere, string tara, int cautat){
		this->an_nastere = an_nastere;
		this->tara = tara;
		this->cautat = cautat;
	}

	friend std::ostream& operator<<(std::ostream&, const Dosar&);

};

std::ostream& operator<<(std::ostream &strm, const Dosar &d) {
	string cautat = "";
	if (d.cautat) cautat = " CAUTAT!!!! ";
	return strm << "nascut in " << d.an_nastere << " in " << d.tara << ", " << cautat;
}