#include <iostream>
using namespace std;

int fibonacci(int x) {
	if (x<=1) return 1;
	return fibonacci(x-1)+fibonacci(x-2);
}

int fibonacci2(const int& x) {
	if (x<=1) return 1;
	return fibonacci2(x-1)+fibonacci2(x-2);
}

int main() {
  int a = 5;
  cout<<fibonacci(a)<<endl;
  cout<<fibonacci2(a)<<endl;
}
