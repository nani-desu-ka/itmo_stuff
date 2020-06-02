#include <iostream>
#include "pnmlib_cs_converter.h"
using namespace std;

int main(int argc, char *argv[]) {
    image src_image;
    cs output_cs;
    bool output_amount;
    bool input_amount;
    int input_value;
    int output_value;
    if (argc < 8) {
        cerr << "Incorrect input format (7 arguments needed)" << '\n';
        exit(EXIT_FAILURE);
    }
    string temp_arg;
    for (int i = 1; i < argc; i++) {
        temp_arg = argv[i];
        if (temp_arg == "-f") {
            temp_arg = argv[++i];
            if (temp_arg == "RGB") src_image.color_space_update(RGB);
            else if (temp_arg =="HSL") src_image.color_space_update(HSL);
            else if (temp_arg == "HSV") src_image.color_space_update(HSV);
            else if (temp_arg == "YCbCr.601") src_image.color_space_update(YCbCr_601);
            else if (temp_arg == "YCbCr.709") src_image.color_space_update(YCbCr_709);
            else if (temp_arg == "YCoCg") src_image.color_space_update(YCoCg);
            else if (temp_arg == "CMY") src_image.color_space_update(CMY);
            else {
                std::cerr << "Incorrect color space";
                return 1;
            }
        } else if (temp_arg == "-t") {
            temp_arg = argv[++i];
            if (temp_arg == "RGB") output_cs = RGB;
            else if (temp_arg == "HSL") output_cs = HSL;
            else if (temp_arg == "HSV") output_cs = HSV;
            else if (temp_arg == "YCbCr.601") output_cs = YCbCr_601;
            else if (temp_arg == "YCbCr.709") output_cs = YCbCr_709;
            else if (temp_arg == "YCoCg") output_cs = YCoCg;
            else if (temp_arg == "CMY") output_cs = CMY;
            else {
                std::cerr << "Incorrect color space";
                return 1;
            }
        } else if (temp_arg == "-i") {
            temp_arg = argv[++i];
            if (temp_arg == "1") input_amount = false;
            else if (temp_arg == "3") input_amount = true;
            else {
                std::cerr << "Incorrect files amount";
                return 1;
            }
            input_value = i;
        } else if (temp_arg == "-o") {
            temp_arg = argv[++i];
            if (temp_arg == "1") output_amount = false;
            else if (temp_arg == "3") output_amount = true;
            else {
                std::cerr << "Incorrect files amount";
                return 1;
            }
            output_value = i;
        }
    }
    if (!input_amount) src_image.read(1, argv[input_value + 1]);
    else src_image.read(3, argv[input_value + 1], argv[input_value + 2], argv[input_value + 3]);
    src_image.cs_convert_raw();
    src_image.cs_convert_final(output_cs);
    if (!output_amount) src_image.write(1, argv[output_value + 1]);
    else src_image.write(3, argv[output_value + 1], argv[output_value + 2], argv[output_value + 3]);
    return 0;
}
