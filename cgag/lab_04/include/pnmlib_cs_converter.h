#pragma once
#include <vector>

enum ColorSpaces {
    RGB,
    HSL,
    HSV,
    YCbCr601,
    YCbCr709,
    YCoCg,
    CMY,
};

enum Count {
    oneFile,
    threeFiles,
};

class image {
public:
    void read(const std::string&, double);
    void write(const std::string&);
    void body_reader_char();
    void body_writer_char(const std::string&);
    void diz_modification_type(int, int);
    double to_sRGB(double);
    double from_sRGB(double);
    double gamma_correct(double);
    double gamma_uncorrect(double);
    void ordered_diz_f();
    void random_diz_f();
    void floyd_diz_f();
    void jarvis_diz_f();
    void sierra_diz_f();
    void atkinson_diz_f();
    void halftone_diz_f();
    void gradient();
    void error_filler();
    ~image();
private:
    int image_type;
    double gamma;
    std::string file_name;
    int brightness;
    int bit;
    int row;
    int column;
    int max_color = 255;
    int **error;
    unsigned char **body_char = nullptr;
};