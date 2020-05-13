#include <iostream>
#include "pnmlib.h"
#include <fstream>
#include <utility>

void image::inversion () {
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
         this->body[i][j].red = max_color - this->body[i][j].red;
         this->body[i][j].blue = max_color - this->body[i][j].blue;
         this->body[i][j].green = max_color - this->body[i][j].green;
        }
    }
}

void image::mirror_horizontal () {
    RGB **temp;
    try {
        temp = new(std::nothrow) RGB *[this->row];
        if (temp == nullptr) {
            throw std::bad_alloc();
        }
    }
    catch (std::bad_alloc &) {
        std::cout << "Bad allocation";
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < this->row; i++) {
        temp[i] = new RGB [this->column];
    }
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
            temp[i][this->column - j - 1] = this->body[i][j];
        }
    }
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
            this->body[i][j] = temp[i][j];
        }
    }
    for (int i = 0; i < this->row; i++) {
        delete [] temp[i];
    }
    delete [] temp;
}

void image::mirror_vertical () {
    RGB **temp;
    try {
        temp = new(std::nothrow) RGB *[this->row];
        if (temp == nullptr) {
            throw std::bad_alloc();
        }
    }
    catch (std::bad_alloc &) {
        std::cout << "Bad allocation";
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < this->row; i++) {
        temp[i] = new RGB [this->column];
    }
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
            temp[this->row - i - 1][j] = this->body[i][j];
        }
    }
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
            this->body[i][j] = temp[i][j];
        }
    }
    for (int i = 0; i < this->row; i++) {
        delete [] temp[i];
    }
    delete [] temp;
}

void image::rotate_270 () {
    RGB **temp;
    try {
        temp = new(std::nothrow) RGB *[this->column];
        if (temp == nullptr) {
            throw std::bad_alloc();
        }
    }
    catch (std::bad_alloc &) {
        std::cout << "Bad allocation";
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < this->column; i++) {
        temp[i] = new RGB [this->row];
    }
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
            temp[j][i] = this->body[i][j];
        }
    }
    for (int i = 0; i < row; i++) {
        delete [] this->body[i];
    }
    delete [] this->body;
    std::swap(this->column, this->row);
    try {
        this->body = new(std::nothrow) RGB *[this->row];
        if (this->body == nullptr) {
            throw std::bad_alloc();
        }
    }
    catch (std::bad_alloc &) {
        std::cout << "Bad allocation";
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < this->row; i++) {
        this->body[i] = new RGB [this->column];
    }
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
            this->body[i][j] = temp[i][j];
        }
    }
    for (int i = 0; i < this->row; i++) {
        delete [] temp[i];
    }
    delete [] temp;
    this->mirror_vertical();
}

void image::rotate_90 () {
    this->rotate_270();
    this->rotate_270();
    this->rotate_270();
}

void image::inversion_char () {
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
            this->body_char[i][j] = this->max_color - this->body_char[i][j];
        }
    }
}

void image::mirror_horizontal_char () {
    unsigned char **temp;
    try {
        temp = new(std::nothrow) unsigned char *[this->row];
        if (temp == nullptr) {
            throw std::bad_alloc();
        }
    }
    catch (std::bad_alloc &) {
        std::cout << "Bad allocation";
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < this->row; i++) {
        temp[i] = new unsigned char [this->column];
    }
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
            temp[i][this->column - j - 1] = this->body_char[i][j];
        }
    }
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
            this->body_char[i][j] = temp[i][j];
        }
    }
    for (int i = 0; i < this->row; i++) {
        delete [] temp[i];
    }
    delete [] temp;
}

void image::mirror_vertical_char () {
    unsigned char **temp;
    try {
        temp = new(std::nothrow) unsigned char *[this->row];
        if (temp == nullptr) {
            throw std::bad_alloc();
        }
    }
    catch (std::bad_alloc &) {
        std::cout << "Bad allocation";
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < this->row; i++) {
        temp[i] = new unsigned char [this->column];
    }
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
            temp[this->row - i - 1][j] = this->body_char[i][j];
        }
    }
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
            this->body_char[i][j] = temp[i][j];
        }
    }
    for (int i = 0; i < this->row; i++) {
        delete [] temp[i];
    }
    delete [] temp;
}

void image::rotate_270_char () {
    unsigned char **temp;
    try {
        temp = new(std::nothrow) unsigned char *[this->column];
        if (temp == nullptr) {
            throw std::bad_alloc();
        }
    }
    catch (std::bad_alloc &) {
        std::cout << "Bad allocation";
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < this->column; i++) {
        temp[i] = new unsigned char [this->row];
    }
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
            temp[j][i] = this->body_char[i][j];
        }
    }
    for (int i = 0; i < row; i++) {
        delete [] this->body_char[i];
    }
    delete [] this->body_char;
    std::swap(this->column, this->row);
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
            this->body_char[i][j] = temp[i][j];
        }
    }
    for (int i = 0; i < this->row; i++) {
        delete [] temp[i];
    }
    delete [] temp;
    this->mirror_vertical_char();
}

void image::rotate_90_char () {
    this->rotate_270_char();
    this->rotate_270_char();
    this->rotate_270_char();
}

void image::commands (int command) {
    switch (command) {
        case invert:
            if (this->image_type == PGM || this->image_type == PBM || this->image_type == PPM) {
                inversion();
            } else {
                inversion_char();
            }
            break;
        case mirror_h:
            if (this->image_type == PGM || this->image_type == PBM || this->image_type == PPM) {
                mirror_horizontal();
            } else {
                mirror_horizontal_char();
            }
            break;
        case mirror_v:
            if (this->image_type == PGM || this->image_type == PBM || this->image_type == PPM)
                mirror_vertical();
            else
                mirror_vertical_char();
            break;
        case rotate_90_cmd:
            if (this->image_type == PGM || this->image_type == PBM || this->image_type == PPM)
                rotate_90();
            else
                rotate_90_char();
            break;
        case rotate_270_cmd:
            if (this->image_type == PGM || this->image_type == PBM || this->image_type == PPM)
                rotate_270();
            else
                rotate_270_char();
            break;
        default:
            throw std::exception();
    }
}

void image::body_reader () {
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
    std::string temp;
    getline(in, temp);
    getline(in, temp);
    getline(in, temp);
    getline(in, temp);
    try {
        this->body = new(std::nothrow) RGB *[this->row];
        if (this->body == nullptr) {
            throw std::bad_alloc();
        }
    }
    catch (std::bad_alloc &) {
        std::cout << "Bad allocation";
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < this->row; i++) {
        this->body[i] = new RGB [this->column];
    }
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
            in >> this->body[i][j].red >> this->body[i][j].green >> this->body[i][j].blue;
            if (this->body[i][j].red > this->max_color || this->body[i][j].green > this->max_color ||
                this->body[i][j].blue > this->max_color) {
                std::cout << "Incorrect depth of color" << '\n';
                exit(EXIT_FAILURE);
            }
        }
    }
    in.close();
}

void image::body_reader_char () {
    std::ifstream in;
    std::ios_base::iostate exceptionMask = in.exceptions() | std::ios::failbit;
    in.exceptions(exceptionMask);
    try {
        in.open(this->file_name, std::ios::binary);
    }
    catch (std::ios_base::failure& e) {
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
        }
    }
    in.close();
}

void image::body_writer (const std::string& output_file) {
    std::ofstream out;
    std::ios_base::iostate exceptionMask = out.exceptions() | std::ios::failbit;
    out.exceptions(exceptionMask);
    try {
        out.open(output_file);
    }
    catch (std::ios_base::failure& e) {
        std::cerr << "Unable to open " << output_file << '\n';
        exit(EXIT_FAILURE);
    }
    out << 'P' << this->image_type << '\n';
    out << this->comment_section << '\n';
    out << this->column << ' ' << this->row << '\n';
    out << this->max_color << '\n';
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
            out << this->body[i][j].red << ' ' << this->body[i][j].green << ' ' << this->body[i][j].blue << ' ';
        }
        out << '\n';
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
            out << this->body_char[i][j];
        }
    }
    if (out.fail()) {
        std::cout << "Writing error" << '\n';
        exit(EXIT_FAILURE);
    }
    out.close();
}

void image::read (const std::string& src_file_name) {
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
    if (temp_type.length() != 2 || temp_type[0] != 'P' || (temp_type[1] - '0' < 1 ||
    temp_type[1] - '0' > 6)) {
        std::cerr << "Incorrect file format (not P1-6)" << '\n';
        exit(EXIT_FAILURE);
    }
    this->image_type = temp_type[1] - '0';
    if (this->image_type == PPM || this->image_type == PGM || this->image_type == PBM) {
        getline(in, this->comment_section);
        if(this->comment_section[0] != '#') {
            std::cerr << "Incorrect file format (comment not found)" << '\n';
            exit(EXIT_FAILURE);
        }
    }
    this->comment_section = "# File has been modified with pnmlib.h";
    in >> this->column >> this->row >> this->max_color;
    if (this->image_type == PGM || this->image_type == PBM || this->image_type == PPM) {
        this->body_reader();
    } else {
        this->body_reader_char();
    }
    in.close();
}

void image::write (const std::string& output_file) {
    if (this->image_type == PGM || this->image_type == PBM || this->image_type == PPM) {
        this->body_writer(output_file);
    } else {
        this->body_writer_char(output_file);
    }
}

image::~image () {
    if (this->body != nullptr) {
        for (int i = 0; i < this->row; i++) {
            delete[] this->body[i];
        }
    }
    delete [] this->body;
    if (this->body_char != nullptr) {
        for (int i = 0; i < this->row; i++) {
            delete[] this->body_char[i];
        }
        delete[] this->body_char;
    }
}

