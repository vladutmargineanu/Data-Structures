#ifndef __COMPLEX_H
#define __COMPLEX_H

#include <math.h>
class Complex {
	private:
	 double re;
	 double im;
	
	public:
		Complex(double re, double im) {
			this -> re = re;
			this -> im = im;
		}
		double getRe() {
			return re;
		}
		double getIm() {
			return im;
		}
		double modulus() {
			// TODO compute module of this
			return sqrt(re * re + im * im);
		}
                //Complex sum1 = c1.add(c2);  //adnarea c1 cu c2

		Complex add(Complex c) {
			// TODO compute sum of this and c
			Complex sum(c.getRe() + re, c.getIm() + im);
			return sum;
		}
		Complex multiply(Complex c) {
			// TODO compute product of this and c
			//double re1 = c.getRe();
			//double im1 = c.getIm();
			//double prodRe = re * re1 - im * im1;
			//double prodIm = re * im1 + re1 * im;
			//Complex prod(prodRe, prodIm);
			Complex prod( re * c.getRe() - im * c.getIm(), re * c.getIm() + c.getRe() * im );
			return prod;
		}
		
};
#endif
