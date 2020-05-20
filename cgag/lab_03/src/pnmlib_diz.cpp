#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include "pnmlib_diz.h"
#include "diz_matrix.hpp"

void image::ordered_diz_f() {
    double shift = this->bit == 4 ? 0.1 : 0;
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
            double buffer = (gamma_uncorrect(this->body_char[i][j]) +
                             (static_cast<double>(this->max_color) / bit) *
                             (ordered_diz_mat[i % 8][j % 8] / 64. -
                              (0.5 + bit / 20.0 + shift))) / this->max_color;
            if (buffer < 0) {
                buffer = 0;
            }
            buffer *= this->brightness - 1;
            buffer = std::round(buffer);
            this->body_char[i][j] = std::round(
                    gamma_correct(buffer * (static_cast<double>(this->max_color) /
                                            (this->brightness - 1))));
        }
    }
}

void image::random_diz_f() {
    double shift = 0;
    switch (bit) {
        case 1:
            shift = 0.5;
            break;

        case 2:
            shift = 0.65;
            break;

        case 3:
            shift = 0.8;
            break;

        case 4:
            shift = 0.85;
            break;

        case 5:
        case 6:
            shift = 0.9;
            break;

        case 7:
            shift = 0.95;
            break;

        case 8:
            shift = 1;
            break;
    }
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
            double buffer = (gamma_uncorrect(this->body_char[i][j]) +
                             (static_cast<double>(this->max_color) / this->bit) * (static_cast<double>(std::rand())
                                                                             / RAND_MAX - shift)) /
                            this->max_color;
            if (buffer < 0) {
                buffer = 0;
            }
            buffer *= this->brightness - 1;
            buffer = std::round(buffer);
            if (std::round(static_cast<int>(gamma_correct(buffer *
                                                          (static_cast<double>(this->max_color) /
                                                           (this->brightness - 1))))) > this->max_color) {
                std::cout << std::round(gamma_correct(buffer *
                                                      (static_cast<double>(this->max_color) / (this->brightness - 1))))
                                                      << std::endl;
            }
            this->body_char[i][j] = std::round(
                    gamma_correct(buffer * (static_cast<double>(this->max_color) /
                                            (this->brightness - 1))));
        }
    }
}

void image::floyd_diz_f() {
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
            double buffer = static_cast<double>(gamma_uncorrect(this->body_char[i][j]) +
                                                error[i][j]) / this->max_color;
            buffer *= brightness - 1;
            buffer = std::round(buffer);
            buffer *= static_cast<double>(this->max_color) / (this->brightness - 1);
            int prev_err = this->body_char[i][j] + error[i][j] - static_cast<int>(buffer);
            this->body_char[i][j] = static_cast<int>(buffer);
            if (static_cast<int>(buffer) > 255) {
                this->body_char[i][j] = this->max_color;
            }
            if (j + 1 < this->column) {
                error[i][j + 1] += prev_err * (7.0 / 16.0);
            }
            if (j - 1 >= 0 && i + 1 < this->row) {
                error[i + 1][j - 1] += prev_err * (3.0 / 16.0);
            }
            if (i + 1 < this->row) {
                error[i + 1][j] += prev_err * (5.0 / 16.0);
            }
            if (i + 1 < this->row && j + 1 < this->column) {
                error[i + 1][j + 1] += prev_err * (3.0 / 16.0);
            }
        }
    }
}

void image::jarvis_diz_f() {
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
            double buffer = static_cast<double>(gamma_uncorrect(this->body_char[i][j]) + error[i][j]) /
                    this->max_color;
            buffer *= this->brightness - 1;
            buffer = std::round(buffer);
            buffer *= static_cast<double>(this->max_color) / (brightness - 1);
            int prev_err = this->body_char[i][j] + error[i][j] - static_cast<int>(buffer);
            this->body_char[i][j] = static_cast<int>(buffer);
            if (static_cast<int>(buffer) > 255) {
                this->body_char[i][j] = this->max_color;
            }
            for (int temp_row = 0; temp_row <= 2; temp_row++) {
                for (int temp_column = -2; temp_column <= 2; temp_column++) {
                    if (!(temp_row == 0 && temp_column <= 0) && j + temp_column < this->column && j +
                    temp_column >= 0 && i + temp_row < this->row) {
                        error[i + temp_row][j + temp_column] +=
                                prev_err * jarvis_diz_mat[temp_row][2 + temp_column] / 48.0;
                    }
                }
            }
        }
    }
}

void image::sierra_diz_f() {
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
            double buffer = static_cast<double>(gamma_uncorrect(this->body_char[i][j]) + error[i][j]) /
                    this->max_color;
            buffer *= this->brightness - 1;
            buffer = std::round(buffer);
            buffer *= static_cast<double>(this->max_color) / (brightness - 1);
            int prev_err = this->body_char[i][j] + error[i][j] - static_cast<int>(buffer);
            this->body_char[i][j] = static_cast<int>(buffer);
            if (static_cast<int>(buffer) > 255) {
                this->body_char[i][j] = this->max_color;
            }
            for (int temp_row = 0; temp_row <= 2; temp_row++) {
                for (int temp_column = -2; temp_column <= 2; temp_column++) {
                    if (!(temp_row == 0 && temp_column <= 0) && j + temp_column < this->column && j +
                    temp_column >= 0 && i + temp_row < this->row && i + temp_row < this->row) {
                        error[i + temp_row][j + temp_column] += prev_err *
                                                                sierra_diz_mat[temp_row][2 + temp_column] / 32.0;
                    }
                }
            }
        }
    }
}

void image::atkinson_diz_f() {
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
            double buffer = static_cast<double>(gamma_uncorrect(this->body_char[i][j]) + error[i][j]) /
                    this->max_color;
            buffer *= this->brightness - 1;
            buffer = std::round(buffer);
            buffer *= static_cast<double>(this->max_color) / (brightness - 1);
            int prev_err = this->body_char[i][j] + error[i][j] - static_cast<int>(buffer);
            this->body_char[i][j] = static_cast<int>(buffer);
            if (static_cast<int>(buffer) > 255) {
                this->body_char[i][j] = this->max_color;
            }
            for (int temp_row = 0; temp_row <= 2; temp_row++) {
                for (int temp_column = -2; temp_column <= 2; temp_column++) {
                    if (!(temp_row == 0 && temp_column <= 0) && j + temp_column < this->column && j +
                    temp_column >= 0 && i + temp_row < this->row) {
                        error[i + temp_row][j + temp_column] += prev_err *
                                                                atkinson_diz_mat[temp_row][2 + temp_column] / 8.0;
                    }
                }
            }
        }
    }
}

void image::halftone_diz_f() {
    double shift = 0;
    switch (bit) {
        case 1:
            shift = 0.5;
            break;

        case 2:
            shift = 0.6;
            break;

        case 3:
            shift = 0.65;
            break;

        case 4:
            shift = 0.7;
            break;

        case 5:
            shift = 0.75;
            break;

        case 6:
        case 7:
            shift = 0.8;
            break;

        case 8:
            shift = 0.85;
            break;
    }
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
            double buffer = static_cast<double>(gamma_uncorrect(this->body_char[i][j]) +
                                                (static_cast<double>(this->max_color) / bit) *
                                                (halftone_diz_mat[i % 4][j % 4] / 16 - shift)) / this->max_color;
            if (buffer < 0) {
                buffer = 0;
            }
            buffer *= this->brightness - 1;
            buffer = std::round(buffer);
            this->body_char[i][j] = static_cast<unsigned char>(std::round(
                    gamma_correct(buffer * (static_cast<double>(this->max_color) /
                                            (this->brightness - 1)))));
        }
    }
}

void image::error_filler() {
    try {
        this->error = new(std::nothrow) int *[this->row];
        if (this->error == nullptr) {
            throw std::bad_alloc();
        }
    }
    catch (std::bad_alloc &) {
        std::cout << "Bad allocation";
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < this->row; i++) {
        this->error[i] = new int [this->column];
    }
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
            this->error[i][j] = 0;
        }
    }
}

void image::diz_modification_type(int diz_type, int temp_bit) {
    this->bit = temp_bit;
    this->brightness = std::pow(2, bit);
    switch (diz_type) {
        case none: {
            for (int i = 0; i < this->row; i++) {
                for (int j = 0; j < this->column; j++) {
                    double buffer =
                            gamma_uncorrect(static_cast<double>(this->body_char[i][j])) /
                            this->max_color;
                    buffer *= this->brightness - 1;
                    buffer = std::round(buffer);
                    this->body_char[i][j] = std::round(
                            gamma_correct(buffer * (static_cast<double>(this->max_color) /
                            (this->brightness - 1))));
                }
            }
            break;
        } case ordered_diz: {
            ordered_diz_f();
            break;
        } case random_diz: {
            random_diz_f();
            break;
        } case floyd_diz: {
            floyd_diz_f();
            break;
        } case jarvis_diz: {
            jarvis_diz_f();
            break;
        } case sierra_diz: {
            sierra_diz_f();
            break;
        } case atkinson_diz: {
            atkinson_diz_f();
            break;
        } case halftone_diz: {
            halftone_diz_f();
            break;
        } default: {
            std::cout << "Incorrect diz_type";
            break;
        }
    }
}

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
