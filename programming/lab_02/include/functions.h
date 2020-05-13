#pragma once

class complex {
public:
    explicit complex ();
    explicit complex (double, double);
    complex (const complex &);

    friend complex operator+ (const complex &left, const complex &right) {
        return complex(left.a + right.a, left.b + right.b);
    }
    friend complex &operator+= (complex &left, const complex &right) {
        left.a += right.a;
        left.b += right.b;
        return left;
    }
    friend complex operator* (const complex &left, const complex &right) {
        return complex(left.a * right.a - left.b * right.b, left.b * right.a + left.a * right.b);
    }
    friend complex operator* (const complex &left, const double &right) {
        return complex(left.a * right, left.b);
    }
    friend complex operator* (const double &right, const complex &left) {
        return complex(left.a * right, left.b);
    }
    friend std::ostream &operator<< (std::ostream &out, const complex &value) {
        out << value.a << " + " << value.b << 'i';
        return out;
    }
    double length();
private:
    double a = 0;
    double b = 0;
};
