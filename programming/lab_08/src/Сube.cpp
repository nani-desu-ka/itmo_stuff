#include "Cube.hpp"
#include "display.hpp"
#include <cmath>
#include "Enums.hpp"
#include <iostream>
double temp_degree = 4.5;
/*------CORNERS------*/
element temp_cor_0(1, 1, -1, red, blue, black, yellow, black, black, straight);
element temp_cor_1(-1, 1, -1, red, blue, white, black, black, black, straight);
element temp_cor_2(-1, -1, -1, red, black, white, black, green, black, straight);
element temp_cor_3(1, -1, -1, red, black, black, yellow, green, black, straight);

element temp_cor_4(1, 1, 1, black, blue, black, yellow, black, orange, straight);
element temp_cor_5(-1, 1, 1, black, blue, white, black, black, orange, straight);
element temp_cor_6(-1, -1, 1, black, black, white, black, green, orange, straight);
element temp_cor_7(1, -1, 1, black, black, black, yellow, green, orange, straight);
/*------CENTERS------*/
element temp_cen_0(0, 0, -1, red, black, black, black, black, black, straight);
element temp_cen_1(0, 1, 0, black, blue, black, black, black, black, straight);
element temp_cen_2(-1, 0, 0, black, black, white, black, black, black, straight);
element temp_cen_3(1, 0, 0, black, black, black, yellow, black, black, straight);
element temp_cen_4(0, -1, 0, black, black, black, black, green, black, straight);
element temp_cen_5(0, 0, 1, black, black, black, black, black, orange, straight);
/*------EDGES------*/
element temp_edge_0(0, 1, -1, red, blue, black, black, black, black, straight);
element temp_edge_1(-1, 0, -1, red, black, white, black, black, black, straight);
element temp_edge_2(0, -1, -1, red, black, black, black, green, black, straight);
element temp_edge_3(1, 0, -1, red, black, black, yellow, black, black, straight);

element temp_edge_4(1, 1, 0, black, blue, black, yellow, black, black, straight);
element temp_edge_5(-1, 1, 0, black, blue, white, black, black, black, straight);
element temp_edge_6(-1, -1, 0, black, black, white, black, green, black, straight);
element temp_edge_7(1, -1, 0, black, black, black, yellow, green, black, straight);

element temp_edge_8(0, 1, 1, black, blue, black, black, black, orange, straight);
element temp_edge_9(-1, 0, 1, black, black, white, black, black, orange, straight);
element temp_edge_10(0, -1, 1, black, black, black, black, green, orange, straight);
element temp_edge_11(1, 0, 1, black, black, black, yellow, black, orange, straight);

rubiks_cube::rubiks_cube() {
    _elements.resize(3);
    _elements[0].push_back(&temp_cor_0);
    _elements[0].push_back(&temp_cor_1);
    _elements[0].push_back(&temp_cor_2);
    _elements[0].push_back(&temp_cor_3);
    _elements[0].push_back(&temp_cor_4);
    _elements[0].push_back(&temp_cor_5);
    _elements[0].push_back(&temp_cor_6);
    _elements[0].push_back(&temp_cor_7);

    _elements[1].push_back(&temp_cen_0);
    _elements[1].push_back(&temp_cen_1);
    _elements[1].push_back(&temp_cen_2);
    _elements[1].push_back(&temp_cen_3);
    _elements[1].push_back(&temp_cen_4);
    _elements[1].push_back(&temp_cen_5);

    _elements[2].push_back(&temp_edge_0);
    _elements[2].push_back(&temp_edge_1);
    _elements[2].push_back(&temp_edge_2);
    _elements[2].push_back(&temp_edge_3);
    _elements[2].push_back(&temp_edge_4);
    _elements[2].push_back(&temp_edge_5);
    _elements[2].push_back(&temp_edge_6);
    _elements[2].push_back(&temp_edge_7);
    _elements[2].push_back(&temp_edge_8);
    _elements[2].push_back(&temp_edge_9);
    _elements[2].push_back(&temp_edge_10);
    _elements[2].push_back(&temp_edge_11);
}

void rubiks_cube::draw() {
    for (auto & _element : _elements) {
        for (auto j : _element) {
            j->draw();
        }
    }
}

void rubiks_cube::UD(std::vector<int> corners, std::vector<int> edges, int center, double degree) {
    double a = degree * (M_PI / 180);
    _elements[1][center]->_rotation = UD_rot;
    _elements[1][center]->_angle = a;
    for (int i = 0; i < 90 / std::abs(degree); i++) {
        for (auto j : corners) {
            _elements[0][j]->_rotation = UD_rot;
            double Y = _elements[0][j]->_position.y * cos(a) - _elements[0][j]->_position.z * sin(a);
            double Z = _elements[0][j]->_position.z * cos(a) + _elements[0][j]->_position.y * sin(a);
            _elements[0][j]->_position.y = Y;
            _elements[0][j]->_position.z = Z;
            _elements[0][j]->_angle = a;
        }
        for (auto j : edges) {
            _elements[2][j]->_rotation = UD_rot;
            double Y = _elements[2][j]->_position.y * cos(a) - _elements[2][j]->_position.z * sin(a);
            double Z = _elements[2][j]->_position.z * cos(a) + _elements[2][j]->_position.y * sin(a);
            _elements[2][j]->_position.y = Y;
            _elements[2][j]->_position.z = Z;
            _elements[2][j]->_angle = a;
        }
        display();
    }
    for (auto j : corners) {
        _elements[0][j]->_angle = 0;
    }
    for (auto j : edges) {
        _elements[2][j]->_angle = 0;
    }
    _elements[1][center]->_angle = 0;
    std::swap(*_elements[0][corners[0]], *_elements[0][corners[1]]);
    std::swap(*_elements[0][corners[1]], *_elements[0][corners[2]]);
    std::swap(*_elements[0][corners[2]], *_elements[0][corners[3]]);

    std::swap(*_elements[2][edges[0]], *_elements[2][edges[1]]);
    std::swap(*_elements[2][edges[1]], *_elements[2][edges[2]]);
    std::swap(*_elements[2][edges[2]], *_elements[2][edges[3]]);
}

void rubiks_cube::LR(std::vector<int> corners, std::vector<int> edges, int center, double degree) {
    double a = degree * (M_PI / 180);
    _elements[1][center]->_rotation = LR_rot;
    _elements[1][center]->_angle = a;
    for (int i = 0; i < 90 / std::abs(degree); i++) {
        for (auto j : corners) {
            _elements[0][j]->_rotation = LR_rot;
            double X = _elements[0][j]->_position.x * cos(a) - _elements[0][j]->_position.z * sin(a);
            double Z = _elements[0][j]->_position.z * cos(a) + _elements[0][j]->_position.x * sin(a);
            _elements[0][j]->_position.x = X;
            _elements[0][j]->_position.z = Z;
            _elements[0][j]->_angle = a;
        }
        for (auto j : edges) {
            _elements[2][j]->_rotation = LR_rot;
            double X = _elements[2][j]->_position.x * cos(a) - _elements[2][j]->_position.z * sin(a);
            double Z = _elements[2][j]->_position.z * cos(a) + _elements[2][j]->_position.x * sin(a);
            _elements[2][j]->_position.x = X;
            _elements[2][j]->_position.z = Z;
            _elements[2][j]->_angle = a;
        }
        display();
    }
    for (auto j : corners) {
        _elements[0][j]->_angle = 0;
    }
    for (auto j : edges) {
        _elements[2][j]->_angle = 0;
    }
    _elements[1][center]->_angle = 0;
    std::swap(*_elements[0][corners[0]], *_elements[0][corners[1]]);
    std::swap(*_elements[0][corners[1]], *_elements[0][corners[2]]);
    std::swap(*_elements[0][corners[2]], *_elements[0][corners[3]]);

    std::swap(*_elements[2][edges[0]], *_elements[2][edges[1]]);
    std::swap(*_elements[2][edges[1]], *_elements[2][edges[2]]);
    std::swap(*_elements[2][edges[2]], *_elements[2][edges[3]]);
}

void rubiks_cube::CLOCK(std::vector<int> corners, std::vector<int> edges, int center, double degree) {
    double a = degree * (M_PI / 180);
    _elements[1][center]->_rotation = CLOCK_rot;
    _elements[1][center]->_angle = a;
    for (int i = 0; i < 90 / std::abs(degree); i++) {
        for (auto j : corners) {
            _elements[0][j]->_rotation = CLOCK_rot;
            double X = _elements[0][j]->_position.x * cos(a) - _elements[0][j]->_position.y * sin(a);
            double Y = _elements[0][j]->_position.y * cos(a) + _elements[0][j]->_position.x * sin(a);
            _elements[0][j]->_position.x = X;
            _elements[0][j]->_position.y = Y;
            _elements[0][j]->_angle = a;
        }
        for (auto j : edges) {
            _elements[2][j]->_rotation = CLOCK_rot;
            double X = _elements[2][j]->_position.x * cos(a) - _elements[2][j]->_position.y * sin(a);
            double Y = _elements[2][j]->_position.y * cos(a) + _elements[2][j]->_position.x * sin(a);
            _elements[2][j]->_position.x = X;
            _elements[2][j]->_position.y = Y;
            _elements[2][j]->_angle = a;
        }
        display();
    }
    for (auto j : corners) {
        _elements[0][j]->_angle = 0;
    }
    for (auto j : edges) {
        _elements[2][j]->_angle = 0;
    }
    _elements[1][center]->_angle = 0;
    std::swap(*_elements[0][corners[0]], *_elements[0][corners[1]]);
    std::swap(*_elements[0][corners[1]], *_elements[0][corners[2]]);
    std::swap(*_elements[0][corners[2]], *_elements[0][corners[3]]);

    std::swap(*_elements[2][edges[0]], *_elements[2][edges[1]]);
    std::swap(*_elements[2][edges[1]], *_elements[2][edges[2]]);
    std::swap(*_elements[2][edges[2]], *_elements[2][edges[3]]);
}

void rubiks_cube::CENTER_LR(std::vector<int> edges, std::vector<int> centers, double degree) {
    double a = degree * (M_PI / 180);
    for (int i = 0; i < 90 / std::abs(degree); i++) {
        for (auto j : edges) {
            _elements[2][j]->_rotation = LR_rot;
            double X = _elements[2][j]->_position.x * cos(a) - _elements[2][j]->_position.z * sin(a);
            double Z = _elements[2][j]->_position.z * cos(a) + _elements[2][j]->_position.x * sin(a);
            _elements[2][j]->_position.x = X;
            _elements[2][j]->_position.z = Z;
            _elements[2][j]->_angle = a;
        }
        for (auto j : centers) {
            _elements[1][j]->_rotation = LR_rot;
            double X = _elements[1][j]->_position.x * cos(a) - _elements[1][j]->_position.z * sin(a);
            double Z = _elements[1][j]->_position.z * cos(a) + _elements[1][j]->_position.x * sin(a);
            _elements[1][j]->_position.x = X;
            _elements[1][j]->_position.z = Z;
            _elements[1][j]->_angle = a;
        }
        display();
    }
    for (auto j : edges) {
        _elements[2][j]->_angle = 0;
    }
    for (auto j : centers) {
        _elements[1][j]->_angle = 0;
    }
    std::swap(*_elements[2][edges[0]], *_elements[2][edges[1]]);
    std::swap(*_elements[2][edges[1]], *_elements[2][edges[2]]);
    std::swap(*_elements[2][edges[2]], *_elements[2][edges[3]]);

    std::swap(*_elements[1][centers[0]], *_elements[1][centers[1]]);
    std::swap(*_elements[1][centers[1]], *_elements[1][centers[2]]);
    std::swap(*_elements[1][centers[2]], *_elements[1][centers[3]]);
}
//-------------------------------
void rubiks_cube::RIGHT() {
    std::vector<int> corners = {0, 3, 7, 4};
    std::vector<int> edges = {3, 7, 11, 4};
    UD(corners, edges, 3, temp_degree);
}

void rubiks_cube::RIGHT_R() {
    std::vector<int> corners = {0, 4, 7, 3};
    std::vector<int> edges = {3, 4, 11, 7};
    UD(corners, edges, 3, -temp_degree);
}

void rubiks_cube::LEFT() {
    std::vector<int> corners = {1, 2, 6, 5};
    std::vector<int> edges = {1, 6, 9, 5};
    UD(corners, edges, 2, temp_degree);
}

void rubiks_cube::LEFT_R() {
    std::vector<int> corners = {1, 5, 6, 2};
    std::vector<int> edges = {1, 5, 9, 6};
    UD(corners, edges, 2, -temp_degree);
}

void rubiks_cube::UP() {
    std::vector<int> corners = {0, 4, 5, 1};
    std::vector<int> edges = {0, 4, 8, 5};
    LR(corners, edges, 1, -temp_degree);
}

void rubiks_cube::UP_R() {
    std::vector<int> corners = {0, 1, 5, 4};
    std::vector<int> edges = {0, 5, 8, 4};
    LR(corners, edges, 1, temp_degree);
}

void rubiks_cube::DOWN() {
    std::vector<int> corners = {2, 6, 7, 3};
    std::vector<int> edges = {2, 6, 10, 7};
    LR(corners, edges, 4, temp_degree);
}

void rubiks_cube::DOWN_R() {
    std::vector<int> corners = {2, 3, 7, 6};
    std::vector<int> edges = {2, 7, 10, 6};
    LR(corners, edges, 4, -temp_degree);
}

void rubiks_cube::CLOCK_R() {
    std::vector<int> corners = {0, 1, 2, 3};
    std::vector<int> edges = {0, 1, 2, 3};
    CLOCK(corners, edges, 0, -temp_degree);
}

void rubiks_cube::CLOCK_L() {
    std::vector<int> corners = {0, 3, 2, 1};
    std::vector<int> edges = {0, 3, 2, 1};
    CLOCK(corners, edges, 0, temp_degree);
}
//-------------------------------
void rubiks_cube::CENTER_RIGHT() {
    std::vector<int> edges = {3, 1, 9, 11};
    std::vector<int> centers = {0, 2, 5, 3};
    CENTER_LR(edges, centers, temp_degree);
}

void rubiks_cube::CENTER_LEFT() {
    std::cout << "HERE БЛЯТЬ";
    std::vector<int> edges = {3, 11, 9, 1};
    std::vector<int> centers = {0, 3, 5, 2};
    CENTER_LR(edges, centers, -temp_degree);
}
//-------------------------------
void rubiks_cube::pif_paf() {
    RIGHT();
    UP();
    RIGHT_R();
    UP_R();
}

void rubiks_cube::all_left() {
    UP();
    CENTER_LEFT();
    DOWN_R();
}

void rubiks_cube::all_right() {
    UP_R();
    CENTER_RIGHT();
    DOWN();
}
//-------------------------------

rubiks_cube::~rubiks_cube() {
    for (auto & _element : _elements) {
        _element.clear();
    }
    _elements.clear();
}