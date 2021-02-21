#include <iostream>
#include "complex.h"

Complex Complex::conjugate() {
    Complex conj;
    conj.re = re;
    conj.im = -im;

    return conj;
}

void Complex::show() {
    if (im > 0) {
        std::cout << re << "+" << im << "i" << std::endl;
    } else {
        std::cout << re << im << "i" << std::endl;
    }
}