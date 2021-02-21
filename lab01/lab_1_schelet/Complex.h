#ifndef __COMPLEX_H__
#define __COMPLEX_H__

#include <math.h>

class Complex {
private:
	double re;
	double im;

public:
	Complex(double re, double im) {
		// TODO create constructor and initialize fields
		this -> re = re;
		this -> im = im;
	}

	double getRe() {
		// TODO create getter for re
		return re;
	}

	double getIm() {
		// TODO create getter for imd
		return im;
	}

	double modulus() {
		// TODO compute module of this
		return sqrt(re * re + im * im);
	}

	Complex add(Complex c) {
		// TODO compute sum of this and c
		c -> re = this -> re + re;
		c -> im = this -> im + im;
	}

	Complex multiply(Complex c) {
		// TODO compute product of this and c
		c -> re = this -> re * re -
	}
};

#endif // __COMPLEX_H__
