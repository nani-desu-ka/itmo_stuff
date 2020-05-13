#pragma once

struct RGB {
    int red;
    int green;
    int blue;
};

enum command_list{
    invert = 0,
    mirror_v,
    mirror_h,
    rotate_90_cmd,
    rotate_270_cmd,
};

enum image_type{
    PBM = 1,
    PGM,
    PPM,
};

class image {
public:
    void commands (int);
    void inversion ();
    void mirror_horizontal ();
    void mirror_vertical ();
    void rotate_90 ();
    void rotate_270 ();
    void read (const std::string&);
    void write (const std::string&);
    void inversion_char ();
    void mirror_horizontal_char ();
    void mirror_vertical_char ();
    void rotate_90_char ();
    void rotate_270_char ();
    void body_reader ();
    void body_reader_char ();
    void body_writer (const std::string&);
    void body_writer_char (const std::string&);
    ~image ();
private:
    int image_type;
    std::string file_name;
    std::string comment_section;
    int max_color = 1;
    int row;
    int column;
    RGB **body = nullptr;
    unsigned char **body_char = nullptr;
};