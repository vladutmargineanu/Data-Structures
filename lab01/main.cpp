#include "complex.h"

int main() {
    Complex number;    
    number.initialize(2, 3);
    Complex conj;
    conj = number.conjugate();
    conj.show();
    return 0;
}