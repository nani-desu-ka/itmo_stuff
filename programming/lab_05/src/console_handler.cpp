#include <iostream>
#include "console_handler.h"
#include "array_handler.h"
#include "custom_stack.h"

void type_chooser () {
    std::cout << "=========CHOOSE TYPE==========" << '\n';
    std::cout << "int - 1" << '\n';
    std::cout << "long long - 2" << '\n';
    std::cout << "float - 3" << '\n';
    std::cout << "double - 4" << '\n';
    std::cout << "Cancel - 0" << '\n';
    std::cout << "==============================" << '\n';
    std::cout << "~> ";
}

void function_item () {
    std::cout << "BEGINNING WORKING WITH FUNCTION..." << '\n';
    type_chooser();
    int command;
    std::cin >> command;
    if (command == cancel_f) {
        return;
    } else {
        long long arr_size;
        std::cout << "====CHOOSE ARRAY SIZE=====" << '\n';
        std::cout << "~> ";
        std::cin >> arr_size;
        switch (command) {
            case int_f: {
                auto max = max_element<int>(arr_size);
                std::cout << "Max_element: " << max << '\n' << '\n';
                break;
            } case ll_f: {
                auto max = max_element<long long>(arr_size);
                std::cout << "Max_element: " << max << '\n' << '\n';
                break;
            } case float_f: {
                auto max = max_element<float>(arr_size);
                std::cout << "Max_element: " << max << '\n' << '\n';
                break;
            } case double_f: {
                auto max = max_element<double>(arr_size);
                std::cout << "Max_element: " << max << '\n' << '\n';
                break;
            } default: {
                std::cout << "========UNKNOWN COMMAND========" << '\n';
                std::cout << "Cancelling..." << '\n' << '\n';
            }
        }
    }
}

void class_item () {
    std::cout << "BEGINNING WORKING WITH CLASS..." << '\n';
    type_chooser();
    int command;
    std::cin >> command;
    if (command == cancel_f) {
        return;
    } else {
        long long capacity;
        std::cout << "====CHOOSE STACK CAPACITY=====" << '\n';
        std::cout << "~> ";
        std::cin >> capacity;
        switch (command) {
            case int_f: {
                stack<int> mem(capacity);
                bool f_end = true;
                stack_commands();
                while (f_end) {
                    f_end = stack_handling(mem);
                    if (f_end) std::cout << "ALL commands list - 4\n";
                }
                break;
            } case ll_f: {
                stack<long long> mem(capacity);
                bool f_end = true;
                stack_commands();
                while (f_end) {
                    f_end = stack_handling(mem);
                    if (f_end) std::cout << "ALL commands list - 4\n";
                }
                break;
            } case float_f: {
                stack<float> mem(capacity);
                bool f_end = true;
                stack_commands();
                while (f_end) {
                    f_end = stack_handling(mem);
                    if (f_end) std::cout << "ALL commands list - 4\n";
                }
                break;
            } case double_f: {
                stack<double> mem(capacity);
                bool f_end = true;
                stack_commands();
                while (f_end) {
                    f_end = stack_handling(mem);
                    if (f_end) std::cout << "ALL commands list - 4\n";
                }
                break;
            } default: {
                std::cout << "========UNKNOWN COMMAND========" << '\n';
                std::cout << "Cancelling..." << '\n' << '\n';
            }
        }
    }
}

bool commands () {
    std::cout << "=========CHOOSE ITEM==========" << '\n';
    std::cout << "Function - 1" << '\n';
    std::cout << "Class - 2" << '\n' << '\n';
    std::cout << "Exit - 0" << '\n';
    std::cout << "==============================" << '\n';
    std::cout << "~> ";
    int command;
    std::cin >> command;
    switch (command) {
        case exit_f: {
            return false;
        } case function_f: {
            function_item();
            return true;
        } case class_f: {
            class_item();
            return true;
        }  default: {
            std::cout << "========UNKNOWN COMMAND========" << '\n';
            return true;
        }
    }
}