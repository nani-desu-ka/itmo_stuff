#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include "pnmlib_cs_converter.h"

void image::cs_convert_raw() {
    if (color_space == RGB) return;
    double red, green, blue;
    double Y, Cb, Cr;
    switch (color_space) {
        case HSL:
        case HSV: {
            double hue, saturation, lightness;
            double C, X, m;
            for (int i = 0; i < this->row; i++)
                for (int j = 0; j < this->column; j++) {
                    hue = (this->body_char[i][j].red / 255.0) * 360.0;
                    saturation = this->body_char[i][j].green / 255.0;
                    lightness = this->body_char[i][j].blue / 255.0;
                    if (this->color_space == HSL) {
                        C = (1 - abs(2 * lightness - 1)) * saturation;
                        X = C * (1 - abs(fmod(hue / 60, 2) - 1));
                        m = lightness - C / 2;
                    } else {
                        C = saturation * lightness;
                        X = C * (1 - abs(fmod(hue / 60, 2) - 1));
                        m = lightness - C;
                    }
                    m *= 255;
                    if (hue >= 0 && hue < 60) {
                        this->body_char[i][j].red = 255 * C + m;
                        this->body_char[i][j].green = 255 * X + m;
                        this->body_char[i][j].blue = m;
                    } else if (hue >= 60 && hue < 120) {
                        this->body_char[i][j].red = X * 255 + m;
                        this->body_char[i][j].green = C * 255 + m;
                        this->body_char[i][j].blue = m;
                    } else if (hue >= 120 && hue < 180) {
                        this->body_char[i][j].red = m;
                        this->body_char[i][j].green = C * 255 + m;
                        this->body_char[i][j].blue = X * 255 + m;
                    } else if (hue >= 180 && hue < 240) {
                        this->body_char[i][j].red = m;
                        this->body_char[i][j].green = X * 255 + m;
                        this->body_char[i][j].blue = C * 255 + m;
                    } else if (hue >= 240 && hue < 300) {
                        this->body_char[i][j].red = X * 255 + m;
                        this->body_char[i][j].green = m;
                        this->body_char[i][j].blue = C * 255 + m;
                    } else if (hue >= 300 && hue <= 360) {
                        this->body_char[i][j].red = C * 255.0 + m;
                        this->body_char[i][j].green = m;
                        this->body_char[i][j].blue = X * 255 + m;
                    }
                }
            break;
        }
        case YCbCr_601:
        case YCbCr_709: {
            double Kr;
            double Kg;
            double Kb;
            if (this->color_space == YCbCr_601) {
                Kr = 0.299;
                Kg = 0.587;
                Kb = 0.114;
            } else {
                Kr = 0.0722;
                Kg = 0.2126;
                Kb = 0.7152;
            }
            for (int i = 0; i < this->row; i++)
                for (int j = 0; j < this->column; j++) {
                    Y = this->body_char[i][j].red / 255.0;
                    Cb = this->body_char[i][j].green / 255.0 - 0.5;
                    Cr = this->body_char[i][j].blue / 255.0 - 0.5;
                    red = (Y + Cr * (2 - 2 * Kr));
                    green = (Y - (Kb / Kg) * (2 - 2 * Kb) * Cb - (Kr / Kg) * (2 - 2 * Kr) * Cr);
                    blue = (Y + (2 - 2 * Kb) * Cb);

                    if (red < 0) red = 0;
                    else if (red > 1) red = 1;

                    if (green < 0) green = 0;
                    else if (green > 1) green = 1;

                    if (blue < 0) blue = 0;
                    else if (blue > 1) blue = 1;

                    this->body_char[i][j].red = 255 * red;
                    this->body_char[i][j].green = 255 * green;
                    this->body_char[i][j].blue = 255 * blue;
                }
            break;
        } case YCoCg: {
            double Co, Cg;
            for (int i = 0; i < this->row; i++)
                for (int j = 0; j < this->column; j++) {
                    Y = this->body_char[i][j].red / 255.0;
                    Co = this->body_char[i][j].green / 255.0 - 0.5;
                    Cg = this->body_char[i][j].blue / 255.0 - 0.5;
                    red = Y + Co - Cg;
                    green = Y + Cg;
                    blue = Y - Co - Cg;
                    if (red < 0) red = 0;
                    else if (red > 1) red = 1;
                    if (green < 0) green = 0;
                    else if (green > 1) green = 1;
                    if (blue < 0) blue = 0;
                    else if (blue > 1) blue = 1;
                    this->body_char[i][j].red = 255 * red;
                    this->body_char[i][j].green = 255 * green;
                    this->body_char[i][j].blue = 255 * blue;
                }
            break;
        } case CMY: {
            double cyan, magenta, yellow;
            for (int i = 0; i < this->row; i++)
                for (int j = 0; j < this->column; j++) {
                    cyan = this->body_char[i][j].red / 255.0;
                    magenta = this->body_char[i][j].green / 255.0;
                    yellow = this->body_char[i][j].blue / 255.0;
                    this->body_char[i][j].red = 255 * (1 - cyan);
                    this->body_char[i][j].green = 255 * (1 - magenta);
                    this->body_char[i][j].blue = 255 * (1 - yellow);
                }
            break;
        } case RGB: {
            break;
        } default: {
            std::cerr << "Unknown color_space";
            exit(EXIT_FAILURE);
        }
    }
}

void image::cs_convert_final(cs new_color_space) {
    if (new_color_space == RGB && this->color_space == RGB) return;
    double red, green, blue;
    switch (new_color_space) {
        case HSL:
        case HSV: {
            double hue = 0, saturation = 0, lightness;
            double value;
            double C;
            double max, min;
            for (int i = 0; i < this->row; i++)
                for (int j = 0; j < this->column; j++) {
                    red = this->body_char[i][j].red / 255.0;
                    green = this->body_char[i][j].green / 255.0;
                    blue = this->body_char[i][j].blue / 255.0;
                    max = std::max(red, std::max(green, blue));
                    min = std::min(red, std::min(green, blue));
                    value = max;
                    C = max - min;
                    lightness = value - C / 2;
                    if (C != 0) {
                        if (value == red) {
                            hue = 60 * ((green - blue) / C);
                        } else if (value == green) {
                            hue = 60 * (2 + (blue - red) / C);
                        } else if (value == blue) {
                            hue = 60 * (4 + (red - green) / C);
                        }
                    }
                    if (new_color_space == HSV) {
                        if (value != 0) {
                            saturation = C / value;
                        }
                        this->body_char[i][j].blue = value * 255;
                    } else if (new_color_space == HSL) {
                        if (lightness != 0 && lightness != 1) {
                            saturation = (value - lightness) / std::min(lightness, 1 - lightness);
                        }
                        this->body_char[i][j].blue = 255 * lightness;
                    }
                    this->body_char[i][j].red = 255 * (hue / 360);
                    this->body_char[i][j].green = 255 * saturation;
                }
            break;
        } case YCbCr_601:
        case YCbCr_709: {
            double Y, Cb, Cr;
            double Kr, Kg, Kb;
            if (new_color_space == YCbCr_601) {
                Kr = 0.299;
                Kg = 0.587;
                Kb = 0.114;
            } else {
                Kr = 0.0722;
                Kg = 0.2126;
                Kb = 0.7152;
            }
            for (int i = 0; i < this->row; i++)
                for (int j = 0; j < this->column; j++) {
                    red = this->body_char[i][j].red / 255.0;
                    green = this->body_char[i][j].green / 255.0;
                    blue = this->body_char[i][j].blue / 255.0;
                    Y = Kr * red + Kg * green + Kb * blue;
                    Cb = 0.5 * ((blue - Y) / (1 - Kb));
                    Cr = 0.5 * ((red - Y) / (1 - Kr));
                    this->body_char[i][j].red =  255 * Y;
                    this->body_char[i][j].green =  255 * (Cb + 0.5);
                    this->body_char[i][j].blue = 255 * (Cr + 0.5);
                }
            break;
        } case YCoCg: {
            double Y, Co, Cg;
            for (int i = 0; i < this->row; i++)
                for (int j = 0; j < this->column; j++) {
                    red = this->body_char[i][j].red / 255.0;
                    green = this->body_char[i][j].green / 255.0;
                    blue = this->body_char[i][j].blue / 255.0;
                    Y = red / 4 + green / 2 + blue / 4;
                    Co = red / 2 - blue / 2;
                    Cg = -red / 4 + green / 2 - blue / 4;
                    this->body_char[i][j].red = 255 * Y;
                    this->body_char[i][j].green = 255 * (Co + 0.5);
                    this->body_char[i][j].blue = 255 * (Cg + 0.5);
                }
            break;
        } case CMY: {
            for (int i = 0; i < this->row; i++)
                for (int j = 0; j < this->column; j++) {
                    red = this->body_char[i][j].red / 255.0;
                    green= this->body_char[i][j].green / 255.0;
                    blue = this->body_char[i][j].blue / 255.0;
                    this->body_char[i][j].red = 255 * (1 - red);
                    this->body_char[i][j].green = 255 * (1 - green);
                    this->body_char[i][j].blue = 255 * (1 - blue);
                }
            break;
        }
    }

}

void image::color_space_update(cs new_one) {
    this->color_space = new_one;
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
        this->body_char = new(std::nothrow) rgb *[this->row];
        if (this->body_char == nullptr) {
            throw std::bad_alloc();
        }
    }
    catch (std::bad_alloc &) {
        std::cout << "Bad allocation";
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < this->row; i++) {
        this->body_char[i] = new rgb [this->column];
    }
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
            in.get((char &)this->body_char[i][j].red);
            if (this->body_char[i][j].red > this->max_color) {
                std::cout << "Incorrect depth of color" << '\n';
                exit(EXIT_FAILURE);
            }
            in.get((char &)this->body_char[i][j].green);
            if (this->body_char[i][j].red > this->max_color) {
                std::cout << "Incorrect depth of color" << '\n';
                exit(EXIT_FAILURE);
            }
            in.get((char &)this->body_char[i][j].blue);
            if (this->body_char[i][j].red > this->max_color) {
                std::cout << "Incorrect depth of color" << '\n';
                exit(EXIT_FAILURE);
            }
        }
    }
    in.close();
}

void image::body_reader_multiple(const std::string& src_file_name_1, const std::string& src_file_name_2,
                                 const std::string& src_file_name_3) {
    std::ifstream in;
    std::ios_base::iostate exceptionMask = in.exceptions() | std::ios::failbit;
    in.exceptions(exceptionMask);
    try {
        in.open(src_file_name_1, std::ios::binary);
    } catch (std::ios_base::failure& e) {
        std::cerr << "Unable to open " << this->file_name << '\n';
        exit(EXIT_FAILURE);
    }
    std::string temp;
    getline(in, temp);
    getline(in, temp);
    getline(in, temp);
    try {
        this->body_char = new(std::nothrow) rgb *[this->row];
        if (this->body_char == nullptr) {
            throw std::bad_alloc();
        }
    }
    catch (std::bad_alloc &) {
        std::cout << "Bad allocation";
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < this->row; i++) {
        this->body_char[i] = new rgb [this->column];
    }
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
            in.get((char &)this->body_char[i][j].red);
            if (this->body_char[i][j].red > this->max_color) {
                std::cout << "Incorrect depth of color" << '\n';
                exit(EXIT_FAILURE);
            }
        }
    }
    in.close();
    try {
        in.open(src_file_name_2, std::ios::binary);
    } catch (std::ios_base::failure& e) {
        std::cerr << "Unable to open " << src_file_name_2 << '\n';
        exit(EXIT_FAILURE);
    }
    getline(in, temp);
    getline(in, temp);
    getline(in, temp);
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
            in.get((char &)this->body_char[i][j].green);
            if (this->body_char[i][j].green > this->max_color) {
                std::cout << "Incorrect depth of color" << '\n';
                exit(EXIT_FAILURE);
            }
        }
    }
    in.close();
    try {
        in.open(src_file_name_3, std::ios::binary);
    } catch (std::ios_base::failure& e) {
        std::cerr << "Unable to open " << src_file_name_3 << '\n';
        exit(EXIT_FAILURE);
    }
    getline(in, temp);
    getline(in, temp);
    getline(in, temp);
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
            in.get((char &)this->body_char[i][j].blue);
            if (this->body_char[i][j].blue > this->max_color) {
                std::cout << "Incorrect depth of color" << '\n';
                exit(EXIT_FAILURE);
            }
        }
    }
    in.close();
}

void image::body_writer_multiple (const std::string& output_file_1, const std::string& output_file_2,
        const std::string& output_file_3) {
    std::ofstream out;
    std::ios_base::iostate exceptionMask = out.exceptions() | std::ios::failbit;
    out.exceptions(exceptionMask);
    try {
        out.open(output_file_1, std::ios::binary);
    }
    catch (std::ios_base::failure& e) {
        std::cerr << "Unable to open " << output_file_1 << '\n';
        exit(EXIT_FAILURE);
    }
    out << 'P' << this->image_type << '\n';
    out << this->column << ' ' << this->row << '\n';
    out << this->max_color << '\n';
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
            out << this->body_char[i][j].red;
        }
    }
    if (out.fail()) {
        std::cout << "Writing error" << '\n';
        exit(EXIT_FAILURE);
    }
    out.close();
    try {
        out.open(output_file_2, std::ios::binary);
    }
    catch (std::ios_base::failure& e) {
        std::cerr << "Unable to open " << output_file_2 << '\n';
        exit(EXIT_FAILURE);
    }
    out << 'P' << this->image_type << '\n';
    out << this->column << ' ' << this->row << '\n';
    out << this->max_color << '\n';
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
            out << this->body_char[i][j].green;
        }
    }
    if (out.fail()) {
        std::cout << "Writing error" << '\n';
        exit(EXIT_FAILURE);
    }
    out.close();
    try {
        out.open(output_file_3, std::ios::binary);
    }
    catch (std::ios_base::failure& e) {
        std::cerr << "Unable to open " << output_file_1 << '\n';
        exit(EXIT_FAILURE);
    }
    out << 'P' << this->image_type << '\n';
    out << this->column << ' ' << this->row << '\n';
    out << this->max_color << '\n';
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
            out << this->body_char[i][j].blue;
        }
    }
    if (out.fail()) {
        std::cout << "Writing error" << '\n';
        exit(EXIT_FAILURE);
    }
    out.close();
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
            out << this->body_char[i][j].red;
            out << this->body_char[i][j].green;
            out << this->body_char[i][j].blue;
        }
    }
    if (out.fail()) {
        std::cout << "Writing error" << '\n';
        exit(EXIT_FAILURE);
    }
    out.close();
}

void image::read (int amount, const std::string& src_file_name_1, const std::string& src_file_name_2,
        const std::string& src_file_name_3) {
    this->file_name = src_file_name_1;
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
//    if (temp_type.length() != 2 || temp_type[0] != 'P' || (temp_type[1] - '0' != 5)) {
//        std::cerr << "Incorrect file format (not P5)" << '\n';
//        exit(EXIT_FAILURE);
//    }
    this->image_type = temp_type[1] - '0';
    in >> this->column >> this->row >> this->max_color;
    if (amount == 1) this->body_reader_char();
    else if (amount == 3) this->body_reader_multiple(src_file_name_1, src_file_name_2, src_file_name_3);
    in.close();
}

void image::write (int amount, const std::string& output_file_1, const std::string& output_file_2,
        const std::string& output_file_3) {
    if (amount == 1) this->body_writer_char(output_file_1);
    else if (amount == 3) this->body_writer_multiple(output_file_1, output_file_2, output_file_3);
}

image::~image () {
    if (this->body_char != nullptr) {
        for (int i = 0; i < this->row; i++) {
            delete[] this->body_char[i];
        }
        delete[] this->body_char;
    }
}
