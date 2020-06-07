#pragma once
#include <vector>
#include "Enums.hpp"
#include "Element.hpp"

class rubiks_cube {
public:
    rubiks_cube();
    void draw();
    //----------- Plains of rotation
    void UD(std::vector<int>, std::vector<int>, int, double);
    void LR(std::vector<int>, std::vector<int>, int, double);
    void CLOCK(std::vector<int>, std::vector<int>, int, double);
    void CENTER_UD(std::vector<int>, std::vector<int>, double);
    void CENTER_LR(std::vector<int>, std::vector<int>, double);
    //----------- Possible directions of rotation
    void UP();
    void UP_R();
    void RIGHT();
    void RIGHT_R();
    void LEFT();
    void LEFT_R();
    void DOWN();
    void DOWN_R();
    void CLOCK_R();
    void CLOCK_L();
    //-------------- Complex rotation helpers
    void CENTER_UP();
    void CENTER_DOWN();
    void CENTER_LEFT();
    void CENTER_RIGHT();
    //------------- Complex rotations
    void pif_paf();
    void all_left();
    void all_right();
    void all_up();
    void all_down();
    //-------------- Rubiks desolver
    void desolver();
    //--------------
    void find_element(colors, el_type);
    ~rubiks_cube();
private:
    std::vector<std::vector<element*>> _elements;
};