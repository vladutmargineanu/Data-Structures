#ifndef __FRACTION_H__
#define __FRACTION_H__

class Fraction {
private:
	double num;
	double denom;

public:
	Fraction(double num, double denom) {
		// TODO constructor that initializes fields
	}

	double getNum() {
		// TODO get private numerator
	}

	double getDenom() {
		// TODO get private denominator
	}

	double decimal() {
		// TODO compute decimal equivalent to fraction
	}

	Fraction multiply(Fraction f) {
		// TODO compute product of this and f
	}

	Fraction divide(Fraction f) {
		// TODO compute division of this and f
	}
};

#endif // __FRACTION_H__
