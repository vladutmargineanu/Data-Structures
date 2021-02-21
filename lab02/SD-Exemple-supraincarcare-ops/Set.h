#ifndef __SET_H
#define __SET_H

#include <algorithm>
#include <vector>

template <typename T>
class Set {
private:
	int size;
	T *elements;

public:
	// Constructor
	Set(int size) {
		this->size = size;
		this->elements = new T[size];
		std::fill_n(this->elements, size, -1);
	}

	// Destructor
	~Set() {
		delete [] this->elements;
	}

	// Copy Constructor
	Set(const Set &other) {
		// We're creating a new object (*this) from object other
		int count = 0;
		this->size = other.getSize();
		this->elements = new T[size];

		for (int i = 0; i < size; i++) {
			this->elements[i] = other.getElementAtPos(i);
		}
	}

	Set& operator=(const Set &other) {
		// Check self-assignment
		if (this == &other) {
			return *this;
		}

		// Delete old values
		// (*this) object already exists
		if (this->elements) {
			delete [] this->elements;
			this->elements = new T[other.getSize()];
		}

		// Copy all other propierties
		this->size = other.getSize();
		std::fill_n(this->elements, size, -1);

		for (int i = 0; i < size; i++) {
			this->elements[i] = other.getElementAtPos(i);
		}

		return *this;
	}

	void operator+=(T element) {
		int posToInsert = -1;

		if (!element) {
			std::cout << "Set can only contain positive numbers\n";
			return;
		}

		// Set should contain only unique numbers
		for (int pos = 0; pos < size; pos++) {
			if (elements[pos] == element) {
				std::cout << "Element " << element << 
							" was already found in set!\n";
				return;
			}

			// No break statement here because we neet to traverse all
			// elements in order to see if the element we're about to add
			// already exists. Otherwise, we keep this pos just to know 
			// which space is the first free one from set
			if (elements[pos] == -1 && posToInsert == -1) {
				posToInsert = pos;
			}
		}

		if (posToInsert == -1) {
			std::cout << "Set is already full!\n";
			return;
		}

		elements[posToInsert] = element;
	}

	void operator+=(const std::vector<T> elems) {
		// Cool thing here: we're actually using the above method to 
		// add these elems to set
		for (auto elem : elems) {
			// Why use *this and not just this? this = a pointer, an address.
			// Values that are stored there (size and elements) can be
			// accessed using the dereferencing opetaor (*)
			*this += elem;
		}
	}

	void operator-=(T element) {
		for (int i = 0; i < size; i++) {
			if (elements[i] == element) {
				elements[i] = -1;
				return;
			}
		}

		std::cout << "Element " << element << " was not found in set!\n";
	}

	bool contains(T elem) const {
		for (int i = 0; i < size; i++) {
			if (elements[i] == elem) {
				return true;
			}
		}

		return false;
	}

	std::vector<T> getUsedElements() const {
		std::vector<T> elems;

		for (int i = 0; i < size; i++) {
			if (elements[i] != -1) {
				elems.push_back(elements[i]);
			}
		}

		return elems;
	}

	int getSize() const {
		return this->size;
	}

	T* getElements() const {
		return this->elements;
	}

	T getElementAtPos(int i) const {
		if (i > this->size) {
			return -1;
		}

		return this->elements[i];
	}

	template <typename S>
	friend bool operator==(const Set<S> &first, const Set<S> &second);
	template <typename S>
	friend std::ostream& operator<<(std::ostream& os, Set<S>& other);
};

template <typename S>
bool operator==(const Set<S> &first, const Set<S> &second) {
	if (first.size != second.size) {
		return false;
	}

	std::vector<S> elems = first.getUsedElements();

	for (auto elem : elems) {
		if (!second.contains(elem)) {
			return false;
		}
	}

	return true;
}

template <typename S>
std::ostream& operator<<(std::ostream& os, Set<S>& other) {
	std::vector<S> elems = other.getUsedElements();
	int size = elems.size();
	
	os << "{";

	if (size > 1) {
		for (int i = 0; i < size - 1; i++) {
				os << elems[i] << ", ";
		}
	}

	os << elems[size - 1] << "}\n";

	return os;
}

#endif