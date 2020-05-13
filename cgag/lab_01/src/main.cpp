#include <iostream>
#include "pnmlib.h"
using namespace std;

int main(int argc, char *argv[]) {
    image src_image;

    if (argc != 4) {
        cerr << "Incorrect input format" << '\n';
        exit(EXIT_FAILURE);
    }

    src_image.read(argv[1]);

    std::string test_command = argv[3];
    if (test_command.size() > 1) {
        cout << "Unknown command" << '\n';
        exit(EXIT_FAILURE);
    }

    try {
        src_image.commands(argv[3][0] - '0');
    }
    catch (std::bad_alloc&){
        std::cerr << "Unknown command" << '\n';
        exit(EXIT_FAILURE);
    }

    src_image.write(argv[2]);

    return 0;
}
