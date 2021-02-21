#include <fstream>
#include <iostream>

#include "MappingEntry.h"

int main() {

#ifdef DEBUG
	std::ostream& out = std::cout;
#else
	std::ofstream file;
	file.open("Out/Lab2/task3.out");
	std::ostream& out = file;
#endif

	char value[] = "MappingEntryValue";

	/* TODO: Create a MappingEntry object (key should be 1 and value - given
		value from above) using new operator */
	MappingEntry* a = MappingEntry(1, *value);
	
	/* TODO: Print entry's value in output */
	out << a -> key << a -> value <<::endl;

	/* TODO: Delete the entry */
	delete a;

#ifndef DEBUG
	file.close();
#endif

	return 0;
}