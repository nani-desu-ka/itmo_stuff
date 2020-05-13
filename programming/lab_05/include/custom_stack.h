#pragma once
#include <iostream>

enum {
    exit_s,
    push_s,
    pop_s,
    top_s,
    again_s,
};

class ArrayException {
private:
    std::string m_error;
public:
    ArrayException(std::string);
    const char* getError();
};

template <typename T>
class stack {
private:
    long long capacity;
    long long size;
    T *array;
public:
    ~stack();
    stack(long long);
    void push(T);
    void pop();
    T top();
};

template<typename T>
bool stack_handling(stack<T> &);

void stack_commands();
#include "custom_stack.tpp"