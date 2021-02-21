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

  // ResizableArray(const ResizableArray& other) {
  //   capacity = other.capacity;
	// 	size = other.size;
	// 	array = new int[capacity];
  //   for (int i=0;i<size;i++) {
  //     array[i] = other.array[i];
  //   }
  // }
	//
  // ~ResizableArray() {
  //   delete[] this->array;
	// }
};

int main() {
  ResizableArray a = ResizableArray(5);
  // ResizableArray b = a;
  // ResizableArray c;
  // c = a;
}
