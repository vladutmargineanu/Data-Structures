#ifndef __PAIR_H__
#define __PAIR_H__

#include <ostream>

template <typename T, typename S>
class Pair {
private:
	T first;
	S second;

public:
	Pair (T first, S second) {
		this->first = first;
		this->second = second;
	}

	bool operator==(const Pair &other) const {
		return first + second  == other.getFirst() + other.getSecond();
	}

	bool operator<(const Pair &other) const {
		return first + second < other.getFirst() + other.getSecond();
	}

	bool operator>(const Pair &other) const {
		return first + second  > other.getFirst() + other.getSecond();
	}

	Pair operator-(const Pair &other) {
		return Pair(first - other.getFirst(), second + other.getSecond()); 
	}

	Pair operator+(const Pair &other) {
		return Pair(first + other.getFirst(), second + other.getSecond()); 
	}

	T getFirst() const {
		return this->first;
	}

	S getSecond() const {
		return this->second;
	}

	template <typename P, typename Q>
	friend std::ostream& operator<<(std::ostream& os, Pair<P, Q>& pair);
};

template <typename T, typename S>
std::ostream& operator<<(std::ostream& os, Pair<T, S>& pair) {
	os << "First: " << pair.first << " Second: " << pair.second << "\n";

	return os;
}

#endif