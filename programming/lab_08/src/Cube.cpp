#include "Cube.hpp"
#include "display.hpp"
#include <cmath>
#include "Enums.hpp"
#include <iostream>

double temp_degree = 9;
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
        switch (_elements[0][j]->_orientation) {
            case straight:
                if (degree > 0) _elements[0][j]->_orientation = back_side;
                else _elements[0][j]->_orientation = f_side;
                continue;
            case l_side:
                continue;
            case r_side:
                continue;
            case f_side:
                if (degree > 0) _elements[0][j]->_orientation = straight;
                else _elements[0][j]->_orientation = bottom_side;
                continue;
            case back_side:
                if (degree > 0) _elements[0][j]->_orientation = bottom_side;
                else _elements[0][j]->_orientation = straight;
                continue;
            case bottom_side:
                if (degree > 0) _elements[0][j]->_orientation = f_side;
                else _elements[0][j]->_orientation = back_side;
                continue;
            default:
                std::cerr << "Impossible orientation";
                exit(EXIT_FAILURE);
        }
    }
    for (auto j : edges) {
        _elements[2][j]->_angle = 0;
        switch (_elements[2][j]->_orientation) {
            case straight:
                if (degree > 0) _elements[2][j]->_orientation = back_side;
                else _elements[2][j]->_orientation = f_side;
                continue;
            case l_side:
                continue;
            case r_side:
                continue;
            case f_side:
                if (degree > 0) _elements[2][j]->_orientation = straight;
                else _elements[2][j]->_orientation = bottom_side;
                continue;
            case back_side:
                if (degree > 0) _elements[2][j]->_orientation = bottom_side;
                else _elements[2][j]->_orientation = straight;
                continue;
            case bottom_side:
                if (degree > 0) _elements[2][j]->_orientation = f_side;
                else _elements[2][j]->_orientation = back_side;
                continue;
            default:
                std::cerr << "Impossible orientation";
                exit(EXIT_FAILURE);
        }
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
        switch (_elements[0][j]->_orientation) {
            case straight:
                continue;
            case l_side:
                if (degree > 0) _elements[0][j]->_orientation = f_side;
                else _elements[0][j]->_orientation = back_side;
                continue;
            case r_side:
                if (degree > 0) _elements[0][j]->_orientation = back_side;
                else _elements[0][j]->_orientation = f_side;
                continue;
            case f_side:
                if (degree > 0) _elements[0][j]->_orientation = r_side;
                else _elements[0][j]->_orientation = l_side;
                continue;
            case back_side:
                if (degree > 0) _elements[0][j]->_orientation = l_side;
                else _elements[0][j]->_orientation = r_side;
                continue;
            case bottom_side:
                continue;
            default:
                std::cerr << "Impossible orientation";
                exit(EXIT_FAILURE);
        }
    }
    for (auto j : edges) {
        _elements[2][j]->_angle = 0;
        switch (_elements[2][j]->_orientation) {
            case straight:
                continue;
            case l_side:
                if (degree > 0) _elements[2][j]->_orientation = f_side;
                else _elements[2][j]->_orientation = back_side;
                continue;
            case r_side:
                if (degree > 0) _elements[2][j]->_orientation = back_side;
                else _elements[2][j]->_orientation = f_side;
                continue;
            case f_side:
                if (degree > 0) _elements[2][j]->_orientation = r_side;
                else _elements[2][j]->_orientation = l_side;
                continue;
            case back_side:
                if (degree > 0) _elements[2][j]->_orientation = l_side;
                else _elements[2][j]->_orientation = r_side;
                continue;
            case bottom_side:
                continue;
            default:
                std::cerr << "Impossible orientation";
                exit(EXIT_FAILURE);
        }
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
        switch (_elements[0][j]->_orientation) {
            case straight:
                if (degree > 0) _elements[0][j]->_orientation = l_side;
                else _elements[0][j]->_orientation = r_side;
                continue;
            case l_side:
                if (degree > 0) _elements[0][j]->_orientation = bottom_side;
                else _elements[0][j]->_orientation = straight;
                continue;
            case r_side:
                if (degree > 0) _elements[0][j]->_orientation = straight;
                else _elements[0][j]->_orientation = bottom_side;
                continue;
            case f_side:
                continue;
            case back_side:
                continue;
            case bottom_side:
                if (degree > 0) _elements[0][j]->_orientation = r_side;
                else _elements[0][j]->_orientation = l_side;
                continue;
            default:
                std::cerr << "Impossible orientation";
                exit(EXIT_FAILURE);
        }
    }
    for (auto j : edges) {
        _elements[2][j]->_angle = 0;
        switch (_elements[2][j]->_orientation) {
            case straight:
                if (degree > 0) _elements[2][j]->_orientation = l_side;
                else _elements[2][j]->_orientation = r_side;
                continue;
            case l_side:
                if (degree > 0) _elements[2][j]->_orientation = bottom_side;
                else _elements[2][j]->_orientation = straight;
                continue;
            case r_side:
                if (degree > 0) _elements[2][j]->_orientation = straight;
                else _elements[2][j]->_orientation = bottom_side;
                continue;
            case f_side:
                continue;
            case back_side:
                continue;
            case bottom_side:
                if (degree > 0) _elements[2][j]->_orientation = r_side;
                else _elements[2][j]->_orientation = l_side;
                continue;
            default:
                std::cerr << "Impossible orientation";
                exit(EXIT_FAILURE);
        }
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
        switch (_elements[2][j]->_orientation) {
            case straight:
                continue;
            case l_side:
                if (degree > 0) _elements[2][j]->_orientation = f_side;
                else _elements[2][j]->_orientation = back_side;
                continue;
            case r_side:
                if (degree > 0) _elements[2][j]->_orientation = back_side;
                else _elements[2][j]->_orientation = f_side;
                continue;
            case f_side:
                if (degree > 0) _elements[2][j]->_orientation = r_side;
                else _elements[2][j]->_orientation = l_side;
                continue;
            case back_side:
                if (degree > 0) _elements[2][j]->_orientation = l_side;
                else _elements[2][j]->_orientation = r_side;
                continue;
            case bottom_side:
                continue;
            default:
                std::cerr << "Impossible orientation";
                exit(EXIT_FAILURE);
        }
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

void rubiks_cube::CENTER_UD(std::vector<int> edges, std::vector<int> centers, double degree) {
    double a = degree * (M_PI / 180);
    for (int i = 0; i < 90 / std::abs(degree); i++) {
        for (auto j : edges) {
            _elements[2][j]->_rotation = UD_rot;
            double Y = _elements[2][j]->_position.y * cos(a) - _elements[2][j]->_position.z * sin(a);
            double Z = _elements[2][j]->_position.z * cos(a) + _elements[2][j]->_position.y * sin(a);
            _elements[2][j]->_position.y = Y;
            _elements[2][j]->_position.z = Z;
            _elements[2][j]->_angle = a;
        }
        for (auto j : centers) {
            _elements[1][j]->_rotation = UD_rot;
            double Y = _elements[1][j]->_position.y * cos(a) - _elements[1][j]->_position.z * sin(a);
            double Z = _elements[1][j]->_position.z * cos(a) + _elements[1][j]->_position.y * sin(a);
            _elements[1][j]->_position.y = Y;
            _elements[1][j]->_position.z = Z;
            _elements[1][j]->_angle = a;
        }
        display();
    }
    for (auto j : edges) {
        _elements[2][j]->_angle = 0;
        switch (_elements[2][j]->_orientation) {
            case straight:
                if (degree > 0) _elements[2][j]->_orientation = back_side;
                else _elements[2][j]->_orientation = f_side;
                continue;
            case l_side:
                continue;
            case r_side:
                continue;
            case f_side:
                if (degree > 0) _elements[2][j]->_orientation = straight;
                else _elements[2][j]->_orientation = bottom_side;
                continue;
            case back_side:
                if (degree > 0) _elements[2][j]->_orientation = bottom_side;
                else _elements[2][j]->_orientation = straight;
                continue;
            case bottom_side:
                if (degree > 0) _elements[2][j]->_orientation = f_side;
                else _elements[2][j]->_orientation = back_side;
                continue;
            default:
                std::cerr << "Impossible orientation";
                exit(EXIT_FAILURE);
        }
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
    std::cout << "R ";
}

void rubiks_cube::RIGHT_R() {
    std::vector<int> corners = {0, 4, 7, 3};
    std::vector<int> edges = {3, 4, 11, 7};
    UD(corners, edges, 3, -temp_degree);
    std::cout << "R' ";
}

void rubiks_cube::LEFT_R() {
    std::vector<int> corners = {1, 2, 6, 5};
    std::vector<int> edges = {1, 6, 9, 5};
    UD(corners, edges, 2, temp_degree);
    std::cout << "L' ";
}

void rubiks_cube::LEFT() {
    std::vector<int> corners = {1, 5, 6, 2};
    std::vector<int> edges = {1, 5, 9, 6};
    UD(corners, edges, 2, -temp_degree);
    std::cout << "L ";
}

void rubiks_cube::UP() {
    std::vector<int> corners = {0, 4, 5, 1};
    std::vector<int> edges = {0, 4, 8, 5};
    LR(corners, edges, 1, -temp_degree);
    std::cout << "U ";
}

void rubiks_cube::UP_R() {
    std::vector<int> corners = {0, 1, 5, 4};
    std::vector<int> edges = {0, 5, 8, 4};
    LR(corners, edges, 1, temp_degree);
    std::cout << "U' ";
}

void rubiks_cube::DOWN() {
    std::vector<int> corners = {2, 6, 7, 3};
    std::vector<int> edges = {2, 6, 10, 7};
    LR(corners, edges, 4, temp_degree);
    std::cout << "D ";
}

void rubiks_cube::DOWN_R() {
    std::vector<int> corners = {2, 3, 7, 6};
    std::vector<int> edges = {2, 7, 10, 6};
    LR(corners, edges, 4, -temp_degree);
    std::cout << "D' ";
}

void rubiks_cube::CLOCK_R() {
    std::vector<int> corners = {0, 1, 2, 3};
    std::vector<int> edges = {0, 1, 2, 3};
    CLOCK(corners, edges, 0, -temp_degree);
    std::cout << "F ";
}

void rubiks_cube::CLOCK_L() {
    std::vector<int> corners = {0, 3, 2, 1};
    std::vector<int> edges = {0, 3, 2, 1};
    CLOCK(corners, edges, 0, temp_degree);
    std::cout << "F' ";
}
//-------------------------------
void rubiks_cube::CENTER_RIGHT() {
    std::vector<int> edges = {3, 1, 9, 11};
    std::vector<int> centers = {0, 2, 5, 3};
    CENTER_LR(edges, centers, temp_degree);
    std::cout << "U ";
    std::cout << "D' ";
}

void rubiks_cube::CENTER_LEFT() {
    std::vector<int> edges = {3, 11, 9, 1};
    std::vector<int> centers = {0, 3, 5, 2};
    CENTER_LR(edges, centers, -temp_degree);
    std::cout << "U' ";
    std::cout << "D ";
}

void rubiks_cube::CENTER_UP() {
    std::vector<int> edges = {0, 2, 10, 8};
    std::vector<int> centers = {0, 4, 5, 1};
    CENTER_UD(edges, centers, temp_degree);
    std::cout << "L ";
    std::cout << "R' ";
}

void rubiks_cube::CENTER_DOWN() {
    std::vector<int> edges = {0, 8, 10, 2};
    std::vector<int> centers = {0, 1, 5, 4};
    CENTER_UD(edges, centers, -temp_degree);
    std::cout << "L' ";
    std::cout << "R ";
}
//-------------------------------
void rubiks_cube::pif_paf() {
    RIGHT();
    UP();
    RIGHT_R();
    UP_R();
}

void rubiks_cube::left_pif_paf() {
    LEFT_R();
    UP_R();
    LEFT();
    UP();
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

void rubiks_cube::all_up() {
    LEFT_R();
    RIGHT();
    CENTER_UP();
}
//-------------------------------
void rubiks_cube::assembler() {
    std::cout << "\nRotations: ";
    cross_iteration();
    lower_corners_itaration();
    middle_edges_iteration();
    top_figure_solver();
    top_cross_reposition_iteration();
    top_corners_positioning_iteration();
    top_corners_orientation_iteration();
    top_corners_reorientaion();
}

void rubiks_cube::disassembler() {
    std::cout << "\nRotations: ";
    srand(time(NULL));
    for (int i = 0; i < 50; i++) {
        int temp_rotation = rand() % 10 + 0;
        switch (temp_rotation) {
            case right_rot:
                RIGHT();
                continue;
            case right_r_rot:
                RIGHT_R();
                continue;
            case left_rot:
                LEFT();
                continue;
            case left_r_rot:
                LEFT_R();
                continue;
            case up_rot:
                UP();
                continue;
            case down_rot:
                DOWN();
                continue;
            case down_r_rot:
                DOWN_R();
                continue;
            case clock_l_rot:
                CLOCK_L();
                continue;
            case clock_r_rot:
                CLOCK_R();
                continue;
        }
    }
    for (auto &i : _elements) {
        for (auto &j : i) {
            j->_right_pos = false;
            j->_corners_position = false;
        }
    }
}
//-------------------------------
void rubiks_cube::cross_iteration() {
  while (!_elements[2][2]->_right_pos || !_elements[2][7]->_right_pos || !_elements[2][6]->_right_pos ||
  !_elements[2][10]->_right_pos) {
      int element_index = find_element(green, edge_);
      if (element_index == 2 || element_index == 6 || element_index == 7 || element_index == 10) {
          if (element_index == 6) all_right();
          else if (element_index == 7) all_left();
          else if (element_index == 10) {
              all_left();
              all_left();
          }
          element_index = 2;
          if (_elements[2][element_index]->_orientation == straight) {
              bool right_center = false;
              for (int i = 0; i < 6; i++)
                  for (int j = 0; j < 6; j++) {
                      if (_elements[1][0]->poly_color[i] == _elements[2][element_index]->poly_color[j] &&
                          _elements[1][0]->poly_color[i] != black)
                          right_center = true;
                  }
              if (!right_center) {
                  CLOCK_L();
                  CLOCK_L();
                  continue;
              } else {
                  _elements[2][element_index]->_right_pos = true;
                  continue;
              }
          } else {
              CLOCK_L();
              pif_paf();
              UP();
              CLOCK_L();
              CLOCK_L();
              continue;
          }
      }
      if (element_index == 3) {
          element_index = element_raiser();
      } else if (element_index == 1) {
          all_right();
          element_index = element_raiser();
      } else if (element_index == 9) {
          all_right();
          all_right();
          element_index = element_raiser();
      } else if (element_index == 11) {
          all_left();
          element_index = element_raiser();
      }
      if (element_index == 4) {
          UP();
      } else if (element_index == 5) {
          UP_R();
      } else if (element_index == 8) {
          UP();
          UP();
      }
      element_index = 0;
      bool right_center = false;
      while (!right_center) {
          for (int i = 0; i < 6; i++)
              for (int j = 0; j < 6; j++) {
                  if (_elements[1][0]->poly_color[i] == _elements[2][element_index]->poly_color[j] &&
                      _elements[1][0]->poly_color[i] != black)
                      right_center = true;
              }
          if (!right_center) {
              DOWN();
              CENTER_RIGHT();
          }
      }
      if (_elements[2][element_index]->_orientation == bottom_side) {
          CLOCK_L();
          CLOCK_L();
      } else {
          CLOCK_R();
          CENTER_LEFT();
          CLOCK_L();
          CENTER_RIGHT();
      }
      _elements[2][2]->_right_pos = true;
  }
}

void rubiks_cube::lower_corners_itaration() {
    while (!_elements[0][2]->_right_pos || !_elements[0][3]->_right_pos || !_elements[0][6]->_right_pos ||
           !_elements[0][7]->_right_pos) {
        int element_index = find_element(green, corner_);
        if (element_index == 2 || element_index == 6 || element_index == 7 || element_index == 3) {
            if (element_index == 2) all_right();
            else if (element_index == 7) all_left();
            else if (element_index == 6) {
                all_left();
                all_left();
            }
            element_index = 3;
            if (_elements[0][element_index]->_orientation == straight) {
                bool right_center_1 = false;
                bool right_center_2 = false;
                for (int i = 0; i < 6; i++)
                    for (int j = 0; j < 6; j++) {
                        if (_elements[1][0]->poly_color[i] == _elements[0][element_index]->poly_color[j] &&
                            _elements[1][0]->poly_color[i] != black)
                            right_center_1 = true;
                    }
                for (int i = 0; i < 6; i++)
                    for (int j = 0; j < 6; j++) {
                        if (_elements[1][3]->poly_color[i] == _elements[0][element_index]->poly_color[j] &&
                            _elements[1][3]->poly_color[i] != black)
                            right_center_2 = true;
                    }
                if (!right_center_1 || !right_center_2) {
                    pif_paf();
                } else {
                    _elements[0][element_index]->_right_pos = true;
                }
            } else {
                if (element_index == 2) {
                    all_right();
                    element_index = 3;
                } else if (element_index == 6) {
                    all_right();
                    all_right();
                    element_index = 3;
                } else if (element_index == 7) {
                    all_left();
                    element_index = 3;
                }
                switch (_elements[0][element_index]->_orientation) {
                    case back_side:
                        for (int i = 0; i < 4; i++)
                            pif_paf();
                        _elements[0][3]->_right_pos = true;
                        continue;
                    case l_side:
                        for (int i = 0; i < 2; i++)
                            pif_paf();
                        _elements[0][3]->_right_pos = true;
                        continue;
                    case straight:
                        _elements[0][3]->_right_pos = true;
                        continue;
                }
            }
            continue;
        }
        if (element_index == 4) {
            all_left();
        } else if (element_index == 5) {
            all_right();
            all_right();
        } else if (element_index == 1) {
            all_right();
        }
        element_index = 0;
        bool right_center_1 = false;
        bool right_center_2 = false;
        while (!right_center_2 || !right_center_1) {
            right_center_1 = false;
            right_center_2 = false;
            for (int i = 0; i < 6; i++)
                for (int j = 0; j < 6; j++) {
                    if (_elements[1][0]->poly_color[i] == _elements[0][element_index]->poly_color[j] &&
                        _elements[1][0]->poly_color[i] != black)
                        right_center_1 = true;
                }
            for (int i = 0; i < 6; i++)
                for (int j = 0; j < 6; j++) {
                    if (_elements[1][3]->poly_color[i] == _elements[0][element_index]->poly_color[j] &&
                        _elements[1][3]->poly_color[i] != black)
                        right_center_2 = true;
                }
            if (!right_center_1 || !right_center_2) {
                DOWN();
                CENTER_RIGHT();
            }
        }
        switch (_elements[0][0]->_orientation) {
            case f_side:
                std::cerr << "FRONT" << '\n';
                exit(EXIT_FAILURE);
            case r_side:
                std::cerr << "R" << '\n';
                exit(EXIT_FAILURE);
            case bottom_side:
                for (int i = 0; i < 3; i++)
                    pif_paf();
                _elements[0][3]->_right_pos = true;
                continue;
            case straight:
                std::cerr << "WTF X2?!!" << '\n';
                exit(EXIT_FAILURE);
            case l_side:
                pif_paf();
                _elements[0][3]->_right_pos = true;
                continue;
            case back_side:
                for (int i = 0; i < 5; i++)
                    pif_paf();
                _elements[0][3]->_right_pos = true;
                continue;
            default:
                std::cerr << "WTF?!!!" << '\n';
                exit(EXIT_FAILURE);
        }
    }
}

void  rubiks_cube::middle_edges_iteration() {
    while (!_elements[2][1]->_right_pos || !_elements[2][3]->_right_pos || !_elements[2][9]->_right_pos ||
           !_elements[2][11]->_right_pos) {
        if (_elements[2][0]->poly_color[1] == black) {
            bool right_center = false;
            while (!right_center) {
                for (int i = 0; i < 6; i++) {
                    for (int j = 0; j < 6; j++) {
                        if (_elements[2][0]->poly_color[i] == _elements[1][0]->poly_color[j] &&
                        _elements[2][0]->poly_color[i] != black) {
                            right_center = true;
                        }
                    }
                }
                if (!right_center) {
                    DOWN();
                    CENTER_RIGHT();
                }
            }
            bool temp_color = false;
            switch (_elements[2][0]->_orientation) {
                case l_side:
                    for (int i = 0; i < 6; i++) {
                        if (_elements[2][0]->poly_color[i] == _elements[1][3]->poly_color[i] &&
                            _elements[2][0]->poly_color[i] != black) {
                            temp_color = true;
                        }
                    }
                    if (!temp_color) {
                        DOWN();
                        CENTER_RIGHT();
                    }
                    UP();
                    pif_paf();
                    all_left();
                    left_pif_paf();
                    all_right();
                    _elements[2][3]->_right_pos = true;
                    continue;
                case r_side:
                    for (int i = 0; i < 6; i++) {
                        if (_elements[2][0]->poly_color[i] == _elements[1][2]->poly_color[i] &&
                            _elements[2][0]->poly_color[i] != black) {
                            temp_color = true;
                        }
                    }
                    if (!temp_color) {
                        DOWN_R();
                        CENTER_LEFT();
                    }
                    UP_R();
                    left_pif_paf();
                    all_right();
                    pif_paf();
                    _elements[2][3]->_right_pos = true;
                    continue;
                default:
                    std::cout << "RETARD ALARM" <<'\n';
                    continue;
            }
        } else {
            bool temp_not_blue = false;
            for (int i = 0; i < 4; i++) {
                UP();
                if (_elements[2][0]->poly_color[1] == black) {
                   temp_not_blue = true;
                   break;
                }
            }
            if (temp_not_blue) {
                continue;
            } else {
                while (_elements[2][3]->_right_pos) {
                    DOWN();
                    CENTER_RIGHT();
                }
                pif_paf();
                all_left();
                left_pif_paf();
                all_right();
            }
        }
    }
}

void rubiks_cube::top_figure_solver() {
    while (true) {
        for (int i = 0; i < 4; i++) {
            if (_elements[2][5]->_orientation == straight && _elements[2][4]->_orientation == straight) {
                CLOCK_R();
                pif_paf();
                CLOCK_L();
                return;
            }
            UP();
        }
        for (int i = 0; i < 4; i++) {
            if (_elements[2][5]->_orientation == straight && _elements[2][8]->_orientation == straight) {
                CLOCK_R();
                pif_paf();
                pif_paf();
                CLOCK_L();
                return;
            }
            UP();
        }
        CLOCK_R();
        pif_paf();
        CLOCK_L();
    }
}

void rubiks_cube::top_cross_reposition_iteration() {
    while (!_elements[2][0]->_right_pos || !_elements[2][4]->_right_pos || !_elements[2][5]->_right_pos ||
            !_elements[2][8]->_right_pos) {
        bool first_one = false;
        bool second_one = false;
        bool third_one = false;
        bool fourth_one = false;
        for (int j = 0; j < 6; j++) {
            if (_elements[2][4]->poly_color[j] == _elements[1][3]->poly_color[j] &&
                _elements[2][4]->poly_color[j] != black) {
                first_one = true;
            }
        }
        for (int j = 0; j < 6; j++) {
            if (_elements[2][0]->poly_color[j] == _elements[1][0]->poly_color[j] &&
                _elements[2][0]->poly_color[j] != black) {
                second_one = true;
            }
        }
        for (int j = 0; j < 6; j++) {
            if (_elements[2][5]->poly_color[j] == _elements[1][2]->poly_color[j] &&
                _elements[2][5]->poly_color[j] != black) {
                third_one = true;
            }
        }
        for (int j = 0; j < 6; j++) {
            if (_elements[2][8]->poly_color[j] == _elements[1][5]->poly_color[j] &&
                _elements[2][8]->poly_color[j] != black) {
                fourth_one = true;
            }
        }
        if (first_one && second_one && third_one && fourth_one) {
            _elements[2][0]->_right_pos = true;
            _elements[2][4]->_right_pos = true;
            _elements[2][5]->_right_pos = true;
            _elements[2][8]->_right_pos = true;
            break;
        }
        CENTER_RIGHT();
        DOWN();
        for (int i = 0; i < 4; i++) {
            bool first_element = false;
            bool second_element = false;
            bool third_element = false;
            for (int j = 0; j < 6; j++) {
                if (_elements[2][4]->poly_color[j] == _elements[1][3]->poly_color[j] &&
                    _elements[2][4]->poly_color[j] != black) {
                    first_element = true;
                }
            }
            if (!first_element) {
                UP();
                continue;
            }
            for (int j = 0; j < 6; j++) {
                if (_elements[2][8]->poly_color[j] == _elements[1][5]->poly_color[j] &&
                    _elements[2][8]->poly_color[j] != black) {
                    second_element = true;
                }
            }
            if (second_element) {
                RIGHT();
                UP();
                RIGHT_R();
                UP();
                RIGHT();
                UP();
                UP();
                RIGHT_R();
                UP();
                break;
            }
            for (int j = 0; j < 6; j++) {
                if (_elements[2][5]->poly_color[j] == _elements[1][2]->poly_color[j] &&
                    _elements[2][5]->poly_color[j] != black) {
                    third_element = true;
                }
            }
            if (third_element) {
                RIGHT();
                UP();
                RIGHT_R();
                UP();
                RIGHT();
                UP();
                UP();
                RIGHT_R();
                UP();
                break;
            }
        }
    }
}

void rubiks_cube::top_corners_positioning_iteration() {
    while (!_elements[0][0]->_corners_position || !_elements[0][4]->_corners_position ||
    !_elements[0][5]->_corners_position || !_elements[0][1]->_corners_position) {
        bool first_col = false;
        bool second_col = false;
        bool first_corner = false;
        bool second_corner = false;
        bool third_corner = false;
        bool fourth_corner = false;
        for (int j = 0; j < 6; j++) {
            if (_elements[0][1]->poly_color[j] == _elements[1][0]->poly_color[j] &&
                _elements[0][1]->poly_color[j] != black) {
                first_col = true;
            }
        }
        for (int j = 0; j < 6; j++) {
            if (_elements[0][1]->poly_color[j] == _elements[1][2]->poly_color[j] &&
                _elements[0][1]->poly_color[j] != black) {
                second_col = true;
            }
        }
        if (second_col && first_col) {
            first_corner = true;
        }
        first_col = false;
        second_col = false;
        for (int j = 0; j < 6; j++) {
            if (_elements[0][0]->poly_color[j] == _elements[1][0]->poly_color[j] &&
                _elements[0][0]->poly_color[j] != black) {
                first_col = true;
            }
        }
        for (int j = 0; j < 6; j++) {
            if (_elements[0][0]->poly_color[j] == _elements[1][3]->poly_color[j] &&
                _elements[0][0]->poly_color[j] != black) {
                second_col = true;
            }
        }
        if (second_col && first_col) {
            second_corner = true;
        }
        first_col = false;
        second_col = false;
        for (int j = 0; j < 6; j++) {
            if (_elements[0][4]->poly_color[j] == _elements[1][5]->poly_color[j] &&
                _elements[0][4]->poly_color[j] != black) {
                first_col = true;
            }
        }
        for (int j = 0; j < 6; j++) {
            if (_elements[0][4]->poly_color[j] == _elements[1][3]->poly_color[j] &&
                _elements[0][4]->poly_color[j] != black) {
                second_col = true;
            }
        }
        if (second_col && first_col) {
            third_corner = true;
        }
        first_col = false;
        second_col = false;
        for (int j = 0; j < 6; j++) {
            if (_elements[0][5]->poly_color[j] == _elements[1][2]->poly_color[j] &&
                _elements[0][5]->poly_color[j] != black) {
                first_col = true;
            }
        }
        for (int j = 0; j < 6; j++) {
            if (_elements[0][5]->poly_color[j] == _elements[1][5]->poly_color[j] &&
                _elements[0][5]->poly_color[j] != black) {
                second_col = true;
            }
        }
        if (second_col && first_col) {
            fourth_corner = true;
        }
        if (first_corner && second_corner && third_corner && fourth_corner) {
            _elements[0][0]->_corners_position = true;
            _elements[0][4]->_corners_position = true;
            _elements[0][5]->_corners_position = true;
            _elements[0][1]->_corners_position = true;
            std::cout << "TOP CORNERS SET" << '\n';
            break;
        }
        for (int i = 0; i < 4; i++) {
            bool first_color = false;
            bool second_color = false;
            for (int j = 0; j < 6; j++) {
                if (_elements[0][1]->poly_color[j] == _elements[1][0]->poly_color[j] &&
                    _elements[0][1]->poly_color[j] != black) {
                    first_color = true;
                }
            }
            if (!first_color) {
                all_right();
                continue;
            }
            for (int j = 0; j < 6; j++) {
                if (_elements[0][1]->poly_color[j] == _elements[1][2]->poly_color[j] &&
                    _elements[0][1]->poly_color[j] != black) {
                    second_color = true;
                }
            }
            if (!second_color) {
                all_right();
                continue;
            }
            break;
        }
        RIGHT();
        UP_R();
        LEFT_R();
        UP();
        RIGHT_R();
        UP_R();
        LEFT();
        UP();
    }
}

void rubiks_cube::top_corners_orientation_iteration() {
    if (_elements[0][0]->_orientation == straight) _elements[0][0]->_right_pos = true;
    if (_elements[0][4]->_orientation == straight) _elements[0][4]->_right_pos = true;
    if (_elements[0][5]->_orientation == straight) _elements[0][5]->_right_pos = true;
    if (_elements[0][1]->_orientation == straight) _elements[0][1]->_right_pos = true;
}

void rubiks_cube::top_corners_reorientaion() {
    all_up();
    all_up();
    for (int i = 0; i < 4; i++) {
        while (_elements[0][3]->_orientation != bottom_side) {
            pif_paf();
        }
        DOWN();
    }
    _elements[0][2]->_right_pos = true;
    _elements[0][3]->_right_pos = true;
    _elements[0][6]->_right_pos = true;
    _elements[0][7]->_right_pos = true;
    all_up();
    all_up();
}
//-------------------------------
int rubiks_cube::find_element(colors temp_color, el_type temp_type) {
    int temp_index = 0;
    switch (temp_type) {
       case edge_:
           temp_index = 2;
           break;
       case corner_:
           temp_index = 0;
           break;
       case center_:
           temp_index = 1;
           break;
        default:
            std::cerr << "Incorrect el_type" << '\n';
            exit(EXIT_FAILURE);
    }
    for (int i = 0; i < _elements[temp_index].size(); i++) {
        if (!_elements[temp_index][i]->_right_pos && (_elements[temp_index][i]->poly_color[0] == temp_color ||
                _elements[temp_index][i]->poly_color[1] == temp_color ||
                _elements[temp_index][i]->poly_color[2] == temp_color ||
                _elements[temp_index][i]->poly_color[3] == temp_color ||
                _elements[temp_index][i]->poly_color[4] == temp_color ||
                _elements[temp_index][i]->poly_color[5] == temp_color)) return i;
    }
}

int rubiks_cube::element_raiser() {
    int turn_amount = 0;
    if (!_elements[2][2]->_right_pos) {
        CLOCK_L();
    } else {
        while (_elements[2][2]->_right_pos) {
            DOWN_R();
            turn_amount++;
        }
        CLOCK_L();
        for (int i = 0; i < turn_amount; i++) DOWN();
    }
    return 0;
}
//-------------------------------
rubiks_cube::~rubiks_cube() {
    for (auto & _element : _elements) {
        _element.clear();
    }
    _elements.clear();
}