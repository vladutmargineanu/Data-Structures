#ifndef __FRACTION_H
#define __FRACTION_H

class Fraction {
public:
	double num;
	double denom;

	Fraction(double n, double d): num(n), denom(d) {};

    Fraction operator*(const Fraction &f) {
    	return Fraction(num * f.num, denom * f.denom);
    }

	Fraction operator/(const Fraction &f) {
		return Fraction(num * f.denom, denom * f.num); 
	}

	double getValue() {
		return num / denom;	
	}

	friend std::ostream& operator<<(std::ostream &out, const Fraction &f);
};

std::ostream& operator<<(std::ostream &out, const Fraction &f) {
    out << f.num << "/" << f.denom << "\n";
    
    return out;
}

#endif
