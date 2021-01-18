#pragma once

struct Point {
    double x;
    double y;
};

struct Rectangle {
    struct Point a, b, c, d;
};

void RectangleConstructor(struct Rectangle *, double, double, struct Point);
double perimeter(struct Rectangle);
double square(struct Rectangle);