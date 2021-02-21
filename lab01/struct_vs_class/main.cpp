#include "complex.h"

int main() {
    Complex number;
    number.re = 2;
    number.im = 4;   
    number.show();

    Complex conj = number.conjugate();
    conj.show();

    return 0;
}