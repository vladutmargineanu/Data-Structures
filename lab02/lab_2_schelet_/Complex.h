#ifndef __COMPLEX_H
#define __COMPLEX_H

#include <iostream>

class Complex {
public:
    double re;
    double im;
 
    Complex(double real, double imag): re(real), im(imag) {};

    /* TODO: Overload + operator
    Complex operator+... {
    }*/

    Complex operator+(const Complex& d){
        return Complex(re + d.re, im + d.im);

    }

    /* TODO: Overload - operator
    Complex operator-...{
    }*/
    Complex operator-(const Complex& d){
        return Complex(re - d.re, im - d.im);
    }

    /* TODO: Overload * operator
    Complex operator*
    }*/
    Complex operator*(const Complex& d){
       Complex prod( re * d.re - im * d.im, re * d.im + d.re * im );
            return prod;
    }

    /* TODO: Implement Copy constructor method */
    
    Complex (const Complex& other):im(other.im), re(other.re){}

    /* TODO: Implement Copy assignment method */
    
  void operator=(const Complex& other){
    re = other.re;
    im = other.im;
  }


    /* TODO: Implement Destructor method */
    ~Complex(){}

    /* TODO: Overload << operator - Friend function declaration
    friend std::ofstream &operator<<...*/
    friend std::ostream& operator<< (std::ostream &out, const Complex &complex);
};

/* TODO: Overload << operator - Friend function implementation 
		Complex number c should be printed as:
			Complex nr: Re(c.re)* Im(c.im)\n */

 std::ostream& operator<< (std::ostream &out, const Complex &complex){

        out << "Complex nr: Re(" << complex.re << ")" << " Im(" << complex.im << ")" <<"\n" ;
        return out;
    }
   
 

#endif
