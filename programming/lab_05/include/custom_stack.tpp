#include <iostream>

template<typename T>
bool stack_handling(stack<T> &array) {
    int temp_comm;
    std::cout << "Enter command\n~> ";
    std::cin >> temp_comm;
    switch (temp_comm) {
        case exit_s: {
            return false;
        } case push_s: {
            T temp_value;
            std::cout << "Enter value\n~> ";
            std::cin >> temp_value;
            try {
                array.push(temp_value);
            } catch (ArrayException &exception) {
                std::cerr << "An array exception occurred (" << exception.getError() << ")\n";
            }
            return true;
        } case pop_s: {
            try {
                array.pop();
            } catch (ArrayException &exception) {
                std::cerr << "An array exception occurred (" << exception.getError() << ")\n";
            }
            return true;
        } case top_s: {
            try {
                std::cout << array.top() << '\n';
            } catch (ArrayException &exception) {
                std::cerr << "An array exception occurred (" << exception.getError() << ")\n";
            }
            return true;
        } case again_s: {
            try {
                stack_commands();
            } catch (ArrayException &exception) {
                std::cerr << "An array exception occurred (" << exception.getError() << ")\n";
            }
            return true;
        } default: {
            std::cout << "=========Undefined command==========\n";
            std::cout << '\n';
            return true;
        }
    }
}

void stack_commands() {
    std::cout << "====AVAILABLE COMMANDS====" << '\n';
    std::cout << "Push - 1" << '\n';
    std::cout << "Pop - 2" << '\n';
    std::cout << "Top - 3" << '\n' << '\n';
    std::cout << "Stop - 0" << '\n';
}

ArrayException::ArrayException(std::string error) : m_error(error) {}

const char *ArrayException::getError() {
    return m_error.c_str();
}

template<typename T>
stack<T>::stack(long long capacity) : capacity(capacity), size(0) {
    array = new T [capacity];
}

template<typename T>
void stack<T>::push (T value) {
    if (size == capacity) throw ArrayException("Stack overflow");
    this->array[size++] = value;
}

template<typename T>
void stack<T>::pop() {
    if (size == 0) throw ArrayException("Nothing to pop");
    --size;
}

template<typename T>
T stack<T>::top() {
    if (size == 0) throw ArrayException("Nothing to return");
    return this->array[size - 1];
}

template<typename T>
stack<T>::~stack() {
    delete [] this->array;
}