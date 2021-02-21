#ifndef __MAPPING_ENTRY_H
#define __MAPPING_ENTRY_H

#include <stdio.h>
#include <string.h>

using namespace std;

#define MAX_LENGTH 255

class MappingEntry {
private:
	int key;
	char *value;

public:
	MappingEntry(int key, char *value) {
		this->key = key;
		this->value = new char[MAX_LENGTH];
		strcpy(this->value, value);
	}

	~MappingEntry() {
		delete [] this->value;
	}

	int getKey() const {
		return this->key;
	}

	char* getValue() const {
		return this->value;
	}
};

#endif
