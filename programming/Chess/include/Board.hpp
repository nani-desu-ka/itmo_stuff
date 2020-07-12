#pragma once
#include <vector>
#include "Enums.hpp"
#include "Element.hpp"
#include "Figure.hpp"

class Board {
public:
    Board();
    void draw();
    element &get_element(int);
    void finisher();
    ~Board();
private:
    std::vector<element> _elements;
    std::vector<element> _border;
};