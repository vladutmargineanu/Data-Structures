/*
 * De ce parametru const la copy constructor si copy assignment?
 * 1. nu are sens sa modificam obiectul copiat => ne protejam de erori
 * 2. parametru cu const va accepta si valori temporare (rvalues)
 * pentru detalii: https://eli.thegreenplace.net/2011/12/15/understanding-lvalues-and-rvalues-in-c-and-c
 */

class ResizableArray {
	int *array;
	int capacity;
	int size;

public:
	ResizableArray(int capacity_=10) {
		capacity = capacity_;
		size = 0;
		array = new int[capacity_];
	}

  ResizableArray(const ResizableArray& other) {		// incercati cu si fara const
    capacity = other.capacity;
		size = other.size;
		array = new int[capacity];
    for (int i=0;i<size;i++) {
      array[i] = other.array[i];
    }
  }

  ~ResizableArray() {
    delete[] this->array;
	}

	// concat as operator+
	ResizableArray operator+(const ResizableArray &other) {
     ResizableArray res = ResizableArray(size+other.size);
		 for (int i=0;i<size;i++) {
       res.array[i] = array[i];
     }
		 for (int i=0;i<other.size;i++) {
       res.array[size+i] = other.array[i];
     }
     return res;
	 }
};

int main() {
  ResizableArray a = ResizableArray(5);
	ResizableArray b = ResizableArray(6);
	//ResizableArray c = a;
	ResizableArray c = a+b;
}
