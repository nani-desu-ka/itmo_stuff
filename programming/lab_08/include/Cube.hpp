#pragma once
#include <vector>
#include "Enums.hpp"
#include "Element.hpp"

class rubiks_cube {
public:
    //----------- Constructor
    rubiks_cube();

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
    void left_pif_paf();
    void all_left();
    void all_right();
    void all_up();
    void all_down();

    //-------------- Rubiks disassembler and assembler
    void disassembler();
    void assembler();
    //-------------- Assembler iterations
    void cross_iteration();
    void lower_corners_itaration();
    void middle_edges_iteration();
    void top_figure_solver();
    void top_cross_reposition_iteration();
    void top_corners_positioning_iteration();
    void top_corners_orientation_iteration();
    void top_corners_reorientaion();
    //-------------- Random help functions
    int find_element(colors, el_type);
    void draw();
    int element_raiser();

    //-------------- Destructor
    ~rubiks_cube();
private:
    std::vector<std::vector<element*>> _elements;
};