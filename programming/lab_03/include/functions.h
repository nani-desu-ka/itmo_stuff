#pragma once

class Triangle {
public:
    Triangle (double, double, double, double, double, double);
    double area () const;
    void transport (std::vector <int>);
    friend std::ostream &operator<< (std::ostream &out, const Triangle &value) {
        out << '[' << value.a_x << ", " << value.a_y << ']' << '[' << value.b_x << ", " << value.b_y << ']'
        << '[' << value.c_x << ", " << value.c_y << ']';
        return out;
    }
    friend bool operator> (const Triangle &left, const Triangle &right) {
        return left.area() > right.area();
    }
    friend bool operator< (const Triangle &left, const Triangle &right) {
        return left.area() < right.area();
    }
    friend bool operator== (const Triangle &left, const Triangle &right) {
        return left.area() == right.area();
    }
    friend bool operator!= (const Triangle &left, const Triangle &right) {
        return left.area() != right.area();
    }
private:
    double a_x;
    double a_y;
    double b_x;
    double b_y;
    double c_x;
    double c_y;
};

class Array_int {
public:
    Array_int (int new_size, int temp_value) {
        if (new_size > 100) {
            std::cerr << "Array is too big: " << new_size << "/100" << '\n';
            std::exit(EXIT_FAILURE);
        }
        this->size = new_size;
        this->body = new int [new_size];
        for (int i = 0; i < this->size; i++) {
            this->body[i] = temp_value;
        }
    }
    ~Array_int() {
        delete [] this->body;
    }
    friend std::ostream &operator<< (std::ostream &out, const Array_int &value) {
        out << '{';
        for (int i = 0; i < value.size; i++) {
            out << value.body[i];
            if (i != value.size - 1) {
                out << ", ";
            }
        }
        out << '}';
        return out;
    }
    friend Array_int operator+ (const Array_int &left, const Array_int &right) {
        Array_int temp(left.size + right.size, left.body[0]);
        for (int i = 0; i < left.size; i++) {
            temp.body[i] = left.body[i];
        }
        for (int i = left.size; i < left.size + right.size; i++) {
            temp.body[i] = right.body[i - left.size];
        }
        return temp;
    }
    Array_int &operator= (const Array_int &);
    friend bool operator> (const Array_int &left, const Array_int &right) {
        return left.size > right.size;
    }
    friend bool operator< (const Array_int &left, const Array_int &right) {
        return left.size < right.size;
    }
    friend bool operator== (const Array_int &left, const Array_int &right) {
        return left.size == right.size;
    }
    friend bool operator!= (const Array_int &left, const Array_int &right) {
        return left.size != right.size;
    }
private:
    int size;
    int *body;
};