#pragma once
#include <vector>
#include "Enums.hpp"
#include "Interfaces.hpp"

class rubiks_cube {
public:
    rubiks_cube();
    void draw();
    void rotation(int);
    void find_element(colors, el_type);
    ~rubiks_cube();
private:
    std::vector<element*> elements;
}

class edge_element : element {
public:
    void draw() override;
    el_type element_type() override;
private:
    el_type _typename = _edge;
};