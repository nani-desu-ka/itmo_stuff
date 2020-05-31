#include <iostream>
#include <algorithm>
#include "circular_buffer.hpp"
#include "console_handler.h"
#include "exception.hpp"

circular_buffer <int> int_buf;

bool commands () {
    std::cout << "=========CHOOSE ITEM==========" << '\n';
    std::cout << "Push_back - 1" << '\n';
    std::cout << "Pop_back - 2" << '\n';
    std::cout << "Push_front - 3" << '\n';
    std::cout << "Pop_front - 4" << '\n';
    std::cout << "Insert - 5" << '\n';
    std::cout << "Erase - 6" << '\n';
    std::cout << "Get_element - 7" << '\n';
    std::cout << "Resize - 8" << '\n';
    std::cout << "Print - 9" << '\n';
    std::cout << "Sort - 10" << '\n';
    std::cout << "==============================" << '\n';
    std::cout << "Exit - 0" << '\n';
    std::cout << "~> ";
    int command;
    std::cin >> command;
    int temp_value = 0;
    int position = 0;
    try {
        switch (command) {
            case cancel_f:
                return false;
            case push_b_f:
                std::cout << "Enter value\n" << "~>";
                std::cin >> temp_value;
                int_buf.push_back(temp_value);
                return true;
            case pop_b_f:
                int_buf.pop_back();
                return true;
            case push_f_f:
                std::cout << "Enter value\n" << "~>";
                std::cin >> temp_value;
                int_buf.push_front(temp_value);
                return true;
            case pop_f_f:
                int_buf.pop_front();
                return true;
            case insert_f:
                std::cout << "Enter value\n" << "~>";
                std::cin >> temp_value;
                std::cout << "Enter position\n" << "~>";
                std::cin >> position;
                int_buf.insert(position, temp_value);
                return true;
            case erase_f:
                std::cout << "Enter position\n" << "~>";
                std::cin >> position;
                int_buf.erase(position);
                return true;
            case get_element_f:
                std::cout << "Enter position\n" << "~>";
                std::cin >> position;
                std::cout << int_buf[position] << '\n';
                return true;
            case resize_f:
                std::cout << "Enter new size\n" << "~>";
                std::cin >> temp_value;
                int_buf.resize(temp_value);
                return true;
            case print_f:
                int_buf.print();
                return true;
            case sort_f:
                std::sort(int_buf.begin(), int_buf.end());
                return true;
            default:
                std::cout << "========UNKNOWN COMMAND========" << '\n';
                return true;
        }
    } catch (std::bad_alloc) {
        std::cerr << "MEMORY ALLOCATION ERROR!" << std::endl;
        exit(EXIT_FAILURE);
    } catch (Exception &exception) {
        std::cerr << exception.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}