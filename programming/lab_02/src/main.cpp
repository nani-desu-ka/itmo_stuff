#include <iostream>
#include "functions.h"

using namespace std;

int main() {
    complex first(1, 2);
    complex second(2, 3);
    complex third = second;
    complex fourth;
    double real = 1.55;

    cout << "Complex_1: " << first << '\n';
    cout << "Complex_2: " << second << '\n';
    cout << "Complex_3: " << third << '\n';
    cout << "Complex_4: " << fourth << '\n';/home/just/ITMO_lab/lab_03
    cout << "Real_1: " << real << '\n' << '\n';
    cout << "Complex_1 = Complex_2" << '\n';
    first = second;
    cout << "Complex_1: " << first << '\n';
    first = third + second;
    cout << "Complex_1 = Complex_2 + Complex_3" << '\n' << "Complex_1: " << first << '\n';
    first = first * second;
    cout << "Complex_1 = Complex_1 * Complex_2" << '\n' << "Complex_1: " << first << '\n';
    cout << "Complex_1 length: " << first.length() << '\n';
    first = first * real;
    cout << "Complex_1 = Complex_1 * Real_1" << '\n' << "Complex_1: " << first << '\n';
    return 0;
}