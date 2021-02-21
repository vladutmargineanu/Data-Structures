#include <iostream>

using namespace std;


class ResizableArray {
	int *array;
	int capacity;
	int size;
    
    public:
	ResizableArray(int capacity) {
		this->capacity = capacity;
		this->size = 0;
		this->array = new int[capacity];
	}
};

int main() {  
	ResizableArray a = ResizableArray(5);  
	ResizableArray b = a;  
	ResizableArray c;  
	c = a;
}