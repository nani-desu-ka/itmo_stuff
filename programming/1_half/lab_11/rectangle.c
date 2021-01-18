#include "rectangle.h"
#include <math.h>

void RectangleConstructor(struct Rectangle *rectangle,
        double length, double height,
        struct Point lower_left_corner_position) {
    rectangle->a = lower_left_corner_position;
    rectangle->b = lower_left_corner_position;
    rectangle->c = lower_left_corner_position;
    rectangle->d = lower_left_corner_position;
    rectangle->b.y += height;
    rectangle->c.y += height;
    rectangle->c.x += length;
    rectangle->d.x += length;
}

double perimeter(struct Rectangle rectangle) {
    return fabs((rectangle.b.y - rectangle.a.y) * 2) + fabs((rectangle.d.x - rectangle.a.x) * 2);
}

double square(struct Rectangle rectangle) {
    return fabs((rectangle.b.y - rectangle.a.y)) * fabs((rectangle.d.x - rectangle.a.x));
}