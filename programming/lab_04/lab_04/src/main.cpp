#include <iostream>
#include "side_lib.hpp"

int main() {
    bool p_end = false;
    comm_list();
    while (!p_end) {
        p_end = command_input();
        if (!p_end) {
            std::cout << "All commands list - 8\n";
        }
    }
    std::cout << "==========Shutting down==========\n";
    return 0;
}
