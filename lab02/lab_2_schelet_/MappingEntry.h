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
	/* TODO: Add constructor method
	MappingEntry(int key, char *value){...}*/
	MappingEntry(int key, char *value){
		this -> key = key;
	    int n = strlen(value);
	    this -> value = new char[n];
	    strcpy(this -> value, value);
	}

	/* TODO: Add destructor method
	~MappingEntry() {...}*/
	~MappingEntry(){
		delete[] value;
	}

	/* TODO: Implement getters for key and value */

	int getKey(){
		return key;
	}

	char* getValue(){
		return value;
	}
};

#endif