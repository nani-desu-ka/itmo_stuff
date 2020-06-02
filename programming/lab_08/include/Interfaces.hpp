#pragma once
#include <vector>
#include "Point.hpp"
#include "Enums.hpp"

class element {
public:
    virtual void draw() = 0;
    virtual el_type element_type() = 0;
private:
    Point _position;
    std::vector<colors> poly_color;
};
