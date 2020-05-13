#include <iostream>
#include "functions.h"

using namespace std;

int main() {
    //first task
    int first_value = 1;
    int second_value = 3;

    //second task
    double double_value_1 = 1.22222222;
    double double_value_2 = 1.33333333;

    //third task
    complex first;
    complex second;

    //fourth task
    circle krug;
    int x = 1;
    int y = 2;

    cout << '\n' << "Task 1 (swap): " << '\n';
    cout << "   first_value: " << first_value << " second_value: " << second_value << '\n' << "swap &" << ":" << '\n';
    custom_swap(first_value, second_value);
    cout << "   first_value: " << first_value << " second_value: " << second_value << '\n' << "swap *:" << '\n';
    custom_swap(&first_value, &second_value);
    cout << "   first_value: " << first_value << " second_value: " << second_value << '\n';

    cout << '\n' << "Task 4 (int_part): " << '\n';
    cout << "Int_part &:" << '\n';
    cout << "   Value: " << double_value_1 << '\n';
    custom_int_part(double_value_1);
    cout << "   Value: " << double_value_1 << '\n';
    cout << "Int_part *:" << '\n';
    cout << "   Value_2: " << double_value_2 << '\n';
    custom_int_part(&double_value_2);
    cout << "   Value_2: " << double_value_2 << '\n';

    cout << '\n' << "Task 9 (complex_multiplier): " << '\n';
    cout << "Multiplier_func &:" << '\n';
    cout << "   Value: ";
    print(first);
    cout << "   Multiplier: ";
    print(second);
    multiplier(first, second);
    cout << "   Value: ";
    print(first);
    cout << "Multiplier_func *:" << '\n';
    cout << "   Value: ";
    print(first);
    cout << "   Multiplier: ";
    print(second);
    multiplier(&first, &second);
    cout << "   Value: ";
    print(first);

    cout << '\n' << "Task 12 (transport): " << '\n';
    cout << "Circle position ";
    print(krug);
    cout << '\n';
    cout << "Transport(1, 2) &:" << '\n';
    transport(krug, x, y);
    cout << "   Circle position ";
    print(krug);
    cout << '\n';
    cout << "Transport(2, 1) *:" << '\n';
    transport(&krug, &y, &x);
    cout << "   Circle position ";
    print(krug);
    cout << '\n';

    return 0;
}