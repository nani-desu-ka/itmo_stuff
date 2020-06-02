#pragma once
#include <vector>

enum cs {
    RGB,
    HSL,
    HSV,
    YCbCr_601,
    YCbCr_709,
    YCoCg,
    CMY,
};

enum files_amount {
    solid_file,
    channels,
};

struct rgb {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

class image {
public:
    void read(int, const std::string&, const std::string& = "trash", const std::string& = "trash");
    void write(int, const std::string&, const std::string& = "trash", const std::string& = "trash");
    void body_reader_char();
    void body_reader_multiple(const std::string&, const std::string&, const std::string&);
    void body_writer_char(const std::string&);
    void body_writer_multiple(const std::string&, const std::string&, const std::string&);
    void color_space_update(cs);
    void cs_convert_raw();
    void cs_convert_final(cs);
    ~image();
private:
    cs color_space;
    int image_type;
    std::string file_name;
    int row;
    int column;
    int max_color = 255;
    rgb **body_char = nullptr;
};