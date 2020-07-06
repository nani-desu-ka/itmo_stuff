// Chess board class (consists of cubes)

#pragma once
#include <vector>
#include "Enums.hpp"
#include "Element.hpp"

class Board {
public:
    Board();
    void draw();
    element &get_element(int);
    ~Board();
private:
    std::vector<element> _elements;
    std::vector<element> _border;
};