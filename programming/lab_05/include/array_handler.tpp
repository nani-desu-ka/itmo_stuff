#include <iostream>

template <typename T>
T max_element (long long size) {
    T *array(new T [size]);
    array_filler<T*, T>(array, size);
    T max(array[0]);
    for (long long i = 0; i < size; ++i) {
        max = (max < array[i]) ? array[i] : max;
    }
    return max;
}

template <typename T, typename Y>
void array_filler (T array, long long size) {
    for (long long i = 0; i < size; ++i) {
        Y psevdo_random(((i * i + size) % 9 + (i * i * i) % 121 + i * size + i) / ((size + i) % 2 + 1));
        array[i] = psevdo_random;
    }
}