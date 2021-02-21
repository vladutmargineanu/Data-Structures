#include <iostream>
#include <fstream>

int main() {

	/*
	* Use out as std::cout
	* ex : out << var1 << " " << var2 << std::endl;
	*/

#ifdef DEBUG
	std::ostream& out = std::cout;
#else
	std::ofstream file;
	file.open("Out/Lab1/task1.out");
	std::ostream& out = file;
#endif

	std::pair<int, float> v[10];
	int n = 10;
	float s = 0;
	
	for (int i = 0; i < n; i++) {
		v[i] = std::make_pair(i, 2.5 * i);
	}
	for (auto p : v) {
		out << p.first << " ";
		s += p.second;
	}
	out << s;

	return 0;
}
