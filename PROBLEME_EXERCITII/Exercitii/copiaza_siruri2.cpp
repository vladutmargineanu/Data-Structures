#include <iostream>

using namespace std;

void copiaza(char *d, char *s){
	while(*s)
		*d++ = *s++;
	*d = *s;
}

int main(){
	char a[256] = "alfabet", b[256];
	copiaza(b, a);
	cout << b <<endl; // nu se modifica adresa lui b
	// se afiseaza "alfabet"
}