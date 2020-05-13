#include <iostream>
#include <cmath>
#include <vector>
#include "functions.h"

Triangle::Triangle (double x_1, double x_2, double y_1, double y_2, double z_1, double z_2) : a_x(x_1), a_y(x_2),
                                                                              b_x(y_1), b_y(y_2), c_x(z_1), c_y(z_2){}
double Triangle::area () const {
    double a_side = sqrt(pow(this->a_x - this->b_x, 2) + pow(this->a_y - this->b_y, 2));
    double b_side = sqrt(pow(this->b_x - this->c_x, 2) + pow(this->b_y - this->c_y, 2));
    double c_side = sqrt(pow(this->c_x - this->a_x, 2) + pow(this->c_y - this->a_y, 2));
    double per = (a_side + b_side + c_side) / 2.;
    return sqrt(per * (per - a_side) * (per - b_side) * (per - c_side));
}

void Triangle::transport (std::vector <int> new_pos) {
    if (!new_pos.empty()) {
        this->a_x += new_pos[0];
    }
    if (new_pos.size() > 1) {
        this->a_y += new_pos[1];
    }
    if (new_pos.size() > 2) {
        this->b_x += new_pos[2];
    }
    if (new_pos.size() > 3) {
        this->b_y += new_pos[3];
    }
    if (new_pos.size() > 4) {
        this->c_x += new_pos[4];
    }
    if (new_pos.size() > 5) {
        this->c_y += new_pos[5];
    }
}

Array_int &Array_int::operator= (const Array_int &right) {
    if (this != &right) {
        this->size = right.size;
        delete[] this->body;
        this->body = new int[this->size];
        for (int i = 0; i < this->size; i++) {
            this->body[i] = right.body[i];
        }
    }
    return *this;
}