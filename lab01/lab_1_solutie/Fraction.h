#ifndef __FRACTION_H
#define __FRACTION_H

class Fraction {
	private:
	 double num;  //numarator
	 double denom;  //numitor
	
	public:
		Fraction(double num, double denom) {
			// TODO constructor that initializes fields
			this -> num = num;
			this -> denom = denom;
		}
		double getNum() {
			// TODO get private numerator
			return num;
		}
		double getDenom() {
			// TODO get private denominator
			return denom;
		}
		double decimal() {
			// TODO compute decimal equivalent to fraction
			return num / denom;
		}
		Fraction multiply(Fraction f) {
			// TODO compute product of this and f
			Fraction prod(f.getNum() * num, f.getDenom() * denom);
			return prod;
		}
		Fraction divide(Fraction f) {
			// TODO compute division of this and f
			Fraction inverse(f.getDenom(), f.getNum());
			return multiply(inverse);
		}
		
};

#endif
