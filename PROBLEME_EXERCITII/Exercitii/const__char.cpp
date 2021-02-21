#include <iostream>

using namespace std;

void sayHello(char* name) {
	cout << "Hello1 "<< name << endl;
}

void sayHello(const char* name) {
	cout << "Hello2 "<< name << endl;
}

void sayHello(string name) {
	cout << "Hello3 "<< name << endl;
}

int main(){
char nume[20] = "Tom";
sayHello(nume);
sayHello("John");
string name = "Mike";
sayHello(name);
}