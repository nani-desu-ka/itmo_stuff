#pragma once
#include <vector>
#include "Enums.hpp"
#include "Element.hpp"

class rubiks_cube {
public:
    rubiks_cube();
    void draw();
    //-----------
    void UD(std::vector<int>, std::vector<int>, int, double);
    void LR(std::vector<int>, std::vector<int>, int, double);
    void clock();
    //-----------
    void UP();
    void UP_R();
    void RIGHT();
    void RIGHT_R();
    void LEFT();
    void LEFT_R();
    void DOWN();
    void DOWN_R();
    //-----------
    void find_element(colors, el_type);
    ~rubiks_cube();
private:
    std::vector<std::vector<element*>> _elements;
};