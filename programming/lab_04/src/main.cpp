#include <iostream>
#include "side_lib.hpp"
#include "Interfaces.hpp"

int main() {
    bool p_end = false;
    comm_list();
    while (!p_end) {
        p_end = command_input();
        if (!p_end) {
            std::cout << "Список всех комманд - 8\n";
        }
    }
    std::cout << "==========Завершение работы==========\n";
    return 0;
}
