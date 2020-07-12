//Board init, draw, destruct

#include "Board.hpp"
#include "Enums.hpp"

Board::Board() {
    for (int z = -1; z < 9; z++) {
        for (int x = -1; x < 9; x++) {
            int temp_color;
            float multiplier = 1;
            float offset = 0;
            if (x > -1 && x < 8 && z > -1 && z < 8) {
                temp_color = (x + z) % 2;
            } else {
                temp_color = 2;
                multiplier = 1.25;
                offset = 0.1;
            }
            element temp_element(x - 3.5, 0, z - 3.5, multiplier, offset, static_cast<colors>(temp_color));
            if (x > -1 && x < 8 && z > -1 && z < 8) {
                _elements.push_back(temp_element);
            } else {
                _border.push_back(temp_element);
            }
        }
    }
}

void Board::draw() {
    for (auto &_element : _elements) {
        _element.draw();
    }
    for (auto &_element : _border) {
        _element.draw();
    }
}

element &Board::get_element(int temp_index) {
    return _elements[temp_index];
}

void Board::finisher() {
    for (auto &element : _elements) {
        element.finish();
    }
}

Board::~Board() {
    _elements.clear();
}