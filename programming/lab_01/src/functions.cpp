#include <iostream>
#include <cmath>
#include "functions.h"

using namespace std;

void multiplier (complex &first, const complex &second) {
    first.a = first.a * second.a - first.b * second.b;
    first.b = first.a * second.b + first.b * second.a;
}

void multiplier (complex *first, const complex *second) {
    first->a = first->a * second->a - first->b * second->b;
    first->b = first->a * second->b + first->b * second->a;
}

void print (const complex &value) {
    cout << value.a << " + " << value.b << "i" << '\n';
}

void transport (circle &src, const int &x, const int &y) {
    src.position_x += x;
    src.position_y += y;
}

void transport (circle *src, const int *x, const int *y) {
    src->position_x += *x;
    src->position_y += *y;
}

void print(const circle &value) {
    cout << "X: " << value.position_x << " Y: " << value.position_y;
}

void custom_swap (int &first, int &second) {
    int mem;
    mem = first;
    first = second;
    second = mem;
}

void custom_swap (int *first, int *second) {
    int mem;
    mem = *first;
    *first = *second;
    *second = mem;
}

void custom_round (double &value, const int &sign) {
    value *= pow(10, sign);
    value = (int)value;
    value /= pow(10, sign);
}

void custom_round (double *value, const int &sign) {
    *value *= pow(10, sign);
    *value = (int)*value;
    *value /= pow(10, sign);
}

void custom_increase (int &src_variable, int multiplier) {
    src_variable += multiplier;
}

void custom_increase (int *src_variable, int multiplier) {
    *src_variable += multiplier;
}

void custom_biggest_increase (int &first, int &second) {
    if (first > second) {
        first += first % second;
    } else {
        second += second % first;
    }
}

void custom_biggest_increase (int *first, int *second) {
    if (*first > *second) {
        *first += *first % *second;
    } else {
        *second += *second % *first;
    }
}

void custom_int_part (double &value) {
    value = (int)value;
}

void custom_int_part (double *value) {
    *value = (int)*value;
}

void custom_fractional_part (double &value) {
    value -= (int)value;
}

void custom_fractional_part (double *value) {
    *value -= (int)*value;
}

void custom_inverse (double &value) {
    value *= -1;
}

void custom_inverse (double *value) {
    *value *= -1;
}

void custom_inverse (int &value) {
    value *= -1;
}

void custom_inverse (int *value) {
    *value *= -1;
}

void custom_reverse (double &value) {
    value = 1. / value;
}

void custom_reverse (double *value) {
    *value = 1. / *value;
}
