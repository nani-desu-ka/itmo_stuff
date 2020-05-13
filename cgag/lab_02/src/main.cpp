#include <iostream>
#include "pnmlib_paint.h"
using namespace std;

int main(int argc, char *argv[]) {
    image src_image;
    double gamma = 1;
    line new_line(atof(argv[5]), atof(argv[6]), atof(argv[7]),
            atof(argv[8]), atoi(argv[4]),
            atoi(argv[3]));
    if (argc < 9) {
        cerr << "Incorrect input format" << '\n';
        exit(EXIT_FAILURE);
    }
    if (argc == 10) {
        gamma = atof(argv[9]);
    } else {
        gamma = 100;
    }

    src_image.read(argv[1], gamma);
    src_image.line_type(new_line);
    src_image.write(argv[2]);

    return 0;
}
