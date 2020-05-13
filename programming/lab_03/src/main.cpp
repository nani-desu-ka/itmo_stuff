#include <iostream>
#include <vector>
#include "functions.h"

using namespace std;

int main() {
    vector <int> new_pos = {1, 2};
    Triangle mem(9, 15, 20, 13, 20, 5);
    Triangle mem_2(10, 16, 21, 14, 21, 6);
    Array_int array_1(5, 1);
    Array_int array_2(6, 2);
    if (mem_2 == mem)
        cout << mem.area() << '\n';
    if (mem < mem_2)
        cout << mem << '\n';
    mem.transport(new_pos);
    cout << mem << '\n';
    if (array_1 < array_2)
        cout << array_1 << '\n';
    cout << array_2 << '\n';
    array_1 = array_1 + array_2;
    cout << array_1 << '\n';
}