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

	/*
	 * TODO Create array of pair, print the first field of each and the sum of all second fields
	 */

	return 0;
}
