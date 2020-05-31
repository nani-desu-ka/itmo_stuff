#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include "pnmlib_cs_converter.h"

double image::gamma_correct(double brightness) {
    brightness /= this->max_color;
    if (gamma == 0) {
        if (brightness <= 0.0031308) {
            return this->max_color * brightness * 12.92;
        } else {
            return this->max_color * (1.055 * pow(brightness, 1 / 2.4) - 0.055);
        }
    } else {
        return this->max_color * std::pow(brightness, gamma);
    }
}

double image::gamma_uncorrect(double brightness) {
    brightness /= this->max_color;
    if (gamma == 0) {
        if (brightness <= 0.04045) {
            return this->max_color * brightness / 12.92;
        } else {
            return this->max_color * pow((brightness + 0.055) / 1.055, 2.4);
        }
    } else {
        return this->max_color * std::pow(brightness, 1 / gamma);
    }
}

void image::gradient() {
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
            this->body_char[i][j] = gamma_correct(static_cast<double>(i) / this->row * this->max_color);
        }
    }
}

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
    this->error_filler();
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
