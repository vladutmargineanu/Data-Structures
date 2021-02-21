#include <iostream>
using namespace std;

struct Apartament {
  int nr_camere;

  Apartament(){
    nr_camere = 3;
  }

  void viziteaza() const {
	cout << "Ap de " << nr_camere << "camere";
  }
  void daramaZid() {
	   nr_camere --;
     cout << "Ap de " << nr_camere << "camere";
  }
};

int main(){

  const Apartament ap_cotroceni;
  ap_cotroceni.viziteaza(); // ?
  ap_cotroceni.daramaZid(); // ?

  Apartament ap_militari;
  ap_militari.viziteaza(); // ?
  ap_militari.daramaZid(); // ?
}
