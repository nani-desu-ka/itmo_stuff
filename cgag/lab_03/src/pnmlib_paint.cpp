#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include "pnmlib_paint.h"

double image::to_sRGB (double point) {
    if (point <= 0.0031308) {
        point *= 12.92;
    } else {
        point = 1.055 * std::pow(point, 2.4) - 0.055;
    }
    return point;
}

double image::from_sRGB (double point) {
    if (point <= 0.04045) {
        point /= 12.92;
    } else {
        point = std::pow((200 * point + 11) / 211.f, 12.f / 5.f);
    }
    return point;
}

void image::antialaising (int x, int y, double brightness_level, int line_brightness) {
    if (y >= 0 && x >= 0 && y < this->row && x < this->column) {
        int temp_brightness = (int)round(line_brightness * brightness_level + (1 - brightness_level) * this->body_char[y][x]);
        this->body_char[y][x] = temp_brightness;
    }
}

void image::simple_line (int x, int y, int line_brightness, int line_width, int line_type) {
    if (line_type == 2) {
        for (int i = 0; i < line_width / 2; i++) {
            if (y >= 0 && y < this->row && x + i < this->column && x + i >= 0) {
                this->body_char[y][x + i] = line_brightness;
            }
        }
        for (int i = 0; i < line_width / 2; i++) {
            if (y >= 0 && y < this->row && x - i < this->column && x - i >= 0) {
                this->body_char[y][x - i] = line_brightness;
            }
        }
    } else {
        for (int i = 0; i < line_width / 2; i++) {
            if (x >= 0 && x < this->column && y + i < this->row && y + i >= 0) {
                this->body_char[y + i][x] = line_brightness;
            }
        }
        for (int i = 0; i < line_width / 2 - 1; i++) {
            if (x >= 0 && x < this->column && y - i < this->row && y - i >= 0) {
                this->body_char[y - i][x] = line_brightness;
            }
        }
    }
}

void image::line_type (line &mem) {
    if (std::abs(mem.end.x - mem.start.x) > std::abs(mem.end.y - mem.start.y)) {
        this->draw_line_1(mem);
    } else {
        this->draw_line_2(mem);
    }
}

void image::draw_line_1 (line &mem) {
    if (mem.start.x > mem.end.x) {
        std::swap(mem.start.x, mem.end.x);
        std::swap(mem.start.y, mem.end.y);
    }
    double delta_x = mem.end.x - mem.start.x;
    double delta_y = mem.end.y - mem.start.y;
    double offset = delta_y / delta_x;
    double y = mem.start.y;
    for (int x = (int)mem.start.x; x <= (int)mem.end.x; x++) {
        double brightness = y - (int)y;
        if (mem.line_width > 1) {
            simple_line(x, (int)y, mem.brightness, mem.line_width, 1);
            antialaising(x, (int)y - mem.line_width / 2 + 1, 1 - brightness, mem.brightness);
            antialaising(x, (int)y + mem.line_width / 2, brightness, mem.brightness);
        } else {
            antialaising(x, (int)y, 1 - brightness, mem.brightness);
            antialaising(x, (int)y + 1, brightness, mem.brightness);
        }
        y += offset;
    }
}

void image::draw_line_2 (line &mem) {
    if (mem.start.y > mem.end.y) {
        std::swap(mem.start.x, mem.end.x);
        std::swap(mem.start.y, mem.end.y);
    }
    double delta_x = mem.end.x - mem.start.x;
    double delta_y = mem.end.y - mem.start.y;
    double offset = delta_x / delta_y;
    double x = mem.start.x;
    for (int y = (int)mem.start.y; y <= (int)mem.end.y; y++) {
        double brightness = x - (int)x;
        if (mem.line_width > 1) {
            simple_line((int) x, y, mem.brightness, mem.line_width, 2);
            antialaising((int)x + mem.line_width / 2, y, brightness, mem.brightness);
            antialaising((int)x - mem.line_width / 2, y, 1 - brightness, mem.brightness);
        } else {
            antialaising((int) x, y, 1 - brightness, mem.brightness);
            antialaising((int) x + 1, y, brightness, mem.brightness);
        }
        x += offset;
    }
}

void image::body_reader_char () {
    std::ifstream in;
    std::ios_base::iostate exceptionMask = in.exceptions() | std::ios::failbit;
    in.exceptions(exceptionMask);
    try {
        in.open(this->file_name, std::ios::binary);
    } catch (std::ios_base::failure& e) {
        std::cerr << "Unable to open " << this->file_name << '\n';
        exit(EXIT_FAILURE);
    }
    std::string temp;
    getline(in, temp);
    getline(in, temp);
    getline(in, temp);
    try {
        this->body_char = new(std::nothrow) unsigned char *[this->row];
        if (this->body_char == nullptr) {
            throw std::bad_alloc();
        }
    }
    catch (std::bad_alloc &) {
        std::cout << "Bad allocation";
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < this->row; i++) {
        this->body_char[i] = new unsigned char [this->column];
    }
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
            in.get((char &)this->body_char[i][j]);
            if (this->body_char[i][j] > this->max_color) {
                std::cout << "Incorrect depth of color" << '\n';
                exit(EXIT_FAILURE);
            }
            if (this->gamma == 100) {
                    this->body_char[i][j] = to_sRGB(this->body_char[i][j] / 255.f) * 255;
            } else {
                int temp_ = this->max_color * std::pow((float) this->body_char[i][j] / (float) this->max_color,
                                                       1.f / (float) this->gamma);
                this->body_char[i][j] = temp_;
            }
        }
    }
    in.close();
}

void image::body_writer_char (const std::string& output_file) {
    std::ofstream out;
    std::ios_base::iostate exceptionMask = out.exceptions() | std::ios::failbit;
    out.exceptions(exceptionMask);
    try {
        out.open(output_file, std::ios::binary);
    }
    catch (std::ios_base::failure& e) {
        std::cerr << "Unable to open " << output_file << '\n';
        exit(EXIT_FAILURE);
    }
    out << 'P' << this->image_type << '\n';
    out << this->column << ' ' << this->row << '\n';
    out << this->max_color << '\n';
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
            if (this->gamma == 100) {
                this->body_char[i][j] = from_sRGB(this->body_char[i][j] / 255.f) * 255;
            } else {
                int temp = std::pow((float) this->body_char[i][j] / (float) this->max_color, this->gamma) *
                           this->max_color;
                this->body_char[i][j] = temp;
            }
                out << this->body_char[i][j];
        }
    }
    if (out.fail()) {
        std::cout << "Writing error" << '\n';
        exit(EXIT_FAILURE);
    }
    out.close();
}

void image::read (const std::string& src_file_name, double src_gamma) {
    this->gamma = src_gamma;
    this->file_name = src_file_name;
    std::ifstream in;
    std::ios_base::iostate exceptionMask = in.exceptions() | std::ios::failbit;
    in.exceptions(exceptionMask);
    try {
        in.open(this->file_name);
    }
    catch (std::ios_base::failure& e) {
        std::cerr << "Unable to open " << this->file_name << '\n';
        exit(EXIT_FAILURE);
    }
    std::string temp_type;
    getline(in, temp_type);
    if (temp_type.length() != 2 || temp_type[0] != 'P' || (temp_type[1] - '0' != 5)) {
        std::cerr << "Incorrect file format (not P5)" << '\n';
        exit(EXIT_FAILURE);
    }
    this->image_type = temp_type[1] - '0';
    in >> this->column >> this->row >> this->max_color;
    this->body_reader_char();
    in.close();
}

void image::write (const std::string& output_file) {
    this->body_writer_char(output_file);
}

image::~image () {
    if (this->body_char != nullptr) {
        for (int i = 0; i < this->row; i++) {
            delete[] this->body_char[i];
        }
        delete[] this->body_char;
    }
}

