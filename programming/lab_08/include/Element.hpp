#pragma once
#include <vector>
#include "Point.hpp"
#include "Enums.hpp"
#include "Color_c.hpp"

class element {
public:
    element(float, float, float, colors, colors, colors, colors, colors, colors, orientation);
    void draw();
    color_c color_check(colors);
    std::vector<colors> poly_color;
    std::vector<std::vector<Point>> _faces;
    orientation _orientation;
    rotation _rotation = no_rotation;
    Point _position;
    double _angle = 0;
    bool _right_pos = true;
};
