#pragma once
#include <vector>

enum {
    none,
    ordered_diz,
    random_diz,
    floyd_diz,
    jarvis_diz,
    sierra_diz,
    atkinson_diz,
    halftone_diz,
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
    double gammaCorrection(double);
    double reverseGammaCorrection(double);
    void gradient();
    ~image();
private:
    int image_type;
    double gamma;
    std::string file_name;
    int row;
    int column;
    int max_color = 255;
    std::vector<std::vector<int>> error;
    unsigned char **body_char = nullptr;
};