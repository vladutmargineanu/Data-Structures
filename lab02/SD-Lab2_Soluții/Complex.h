#ifndef __COMPLEX_H
#define __COMPLEX_H

#include <iostream>

class Complex {
public:
    double re;
    double im;
 
    Complex(double real, double imag): re(real), im(imag) {};

    Complex operator+(const Complex &d) {
        return Complex(re + d.re, im + d.im);
    }

    Complex operator-(const Complex &d) {
        return Complex(re - d.re, im - d.im);
    }

    Complex operator*(const Complex &d) {
        return Complex(re * d.re - im * d.im, re * d.im + im * d.re);
    }

    Complex(const Complex &d) {
        re = d.re;
        im = d.im;
    }

    ~Complex() {
        // No memory to free here
    }

    Complex& operator=(const Complex &d) {
        // Check self-assignment 
    	if (this == &d) {
    		return *this;
    	}

        re = d.re;
        im = d.im;

        return *this;
    }

    friend std::ostream& operator<<(std::ostream &out, const Complex &d);
};

std::ostream& operator<<(std::ostream &out, const Complex &d) {
    out << "Complex nr: Re(" << d.re <<") Im(" << d.im << ")\n";
    
    return out;
}

#endif
