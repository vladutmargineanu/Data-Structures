#include <iostream>

using namespace std;

char* copiaza(char *d, char *s){
	char *p = d;
	while(*s) cout << (*d++ = *s++) << endl;
	*d = *s;
	//cout << d << endl;
	return p;
}

int main(){
	char a[256] = "alfabet", b[256];
	cout << copiaza(b, a) << endl;
	cout << b << endl;

}