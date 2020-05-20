#pragma once

struct point {
    point (float x, float y) : x(x), y(y) {}
    float x = 0;
    float y = 0;
};

class line {
public:
    line (float x_1, float y_1, float x_2, float y_2, int line_width, int brightness = 255) :
    start(x_1, y_1), end(x_2, y_2), line_width(line_width), brightness(brightness) {}
    point start;
    point end;
    int brightness;
    int line_width;
};

class image {
public:
    void read (const std::string&, double);
    void write (const std::string&);
    void body_reader_char ();
    void body_writer_char (const std::string&);
    void draw_line_1 (line &);
    void draw_line_2 (line &);
    void line_type (line &);
    void antialaising (int, int, double, int);
    void simple_line (int, int, int, int, int);
    double to_sRGB (double);
    double from_sRGB (double);
    ~image ();
private:
    int image_type;
    double gamma;
    std::string file_name;
    int row;
    int column;
    int max_color = 255;
    unsigned char **body_char = nullptr;
};