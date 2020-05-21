#include <iostream>
#include "pnmlib_cs_converter.h"
using namespace std;

int main(int argc, char *argv[]) {
    image src_image;
    double gamma = 1;
    if (argc != 7) {
        cerr << "Incorrect input format (7 arguments needed)" << '\n';
        exit(EXIT_FAILURE);
    }
    gamma = atof(argv[6]);
    src_image.read(argv[1], gamma);
    if (atoi(argv[3]) > 1 || atoi(argv[3]) < 0) {
        cerr << "Incorrect input format (gradient only 1 || 0)" << '\n';
        exit(EXIT_FAILURE);
    }
    src_image.write(argv[2]);
    return 0;
}
