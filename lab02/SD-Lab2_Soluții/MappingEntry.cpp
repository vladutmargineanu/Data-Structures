#include <fstream>

#include "MappingEntry.h"

int main() {
	std::ofstream output;
	output.open("Out/Lab2/task3.out");

	char value[] = "MappingEntryValue";
	MappingEntry *entry = new MappingEntry(1, value);

	output << entry->getValue();

	delete entry;
	output.close();

	return 0;
}
