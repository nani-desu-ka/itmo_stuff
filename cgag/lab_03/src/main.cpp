#include <iostream>
#include "pnmlib_diz.h"
using namespace std;

int main(int argc, char *argv[]) {
    image src_image;
    double gamma = 1;
    if (argc != 7) {
        cerr << "Incorrect input format (7 arguments needed)" << '\n';
        exit(EXIT_FAILURE);
    }
    gamma = atof(argv[6]);
    int diz_type = atoi(argv[4]);
    int bit = atoi(argv[5]);
    src_image.read(argv[1], gamma);
    if (atoi(argv[3]) > 1 || atoi(argv[3]) < 0) {
        cerr << "Incorrect input format (gradient only 1 || 0)" << '\n';
        exit(EXIT_FAILURE);
    }
    if (atoi(argv[3])) src_image.gradient();
    src_image.diz_modification_type(diz_type, bit);
    src_image.write(argv[2]);
    return 0;
}
