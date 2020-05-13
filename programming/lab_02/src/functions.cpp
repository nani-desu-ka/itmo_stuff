#include <iostream>
#include <cmath>
#include "functions.h"

complex::complex () : a(0), b(0) {}
complex::complex (double i, double i_1) : a(i), b(i_1) {}
complex::complex (const complex &value) : a(value.a), b(value.b) {}

double complex::length () {
    return sqrt(this->a * this->a + this->b * this->b);
}

