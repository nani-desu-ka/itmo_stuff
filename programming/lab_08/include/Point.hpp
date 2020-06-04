#pragma once

struct Point {
    Point() : x(0), y(0), z(0) {}
    void set(float _x, float _y, float _z) {
        x = _x;
        y = _y;
        z = _z;
    }
    Point(float x, float y, float z) : x(x), y(y), z(z) {}
    Point &operator=(const Point &right) {
        if (this == &right) {
            return *this;
        }
        x = right.x;
        y = right.y;
        z = right.z;
        return *this;
    }
    double x = 0, y = 0, z = 0;
};

