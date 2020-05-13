#include <iostream>
#include "console_handler.h"

int main() {
    bool p_end = true;
    while (p_end) {
        p_end = commands();
    }
    std::cout << "==========Shutting down==========\n";
    return 0;
}
