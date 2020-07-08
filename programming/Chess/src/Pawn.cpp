#include "Pawn.hpp"
#include "Board.hpp"
#include <GL/gl.h>

Pawn::Pawn(int index, Board *src_board) {
    _index = index;
    _src_board = src_board;
    float y = 0.51;
    Point temp_point(-0.4, y, -0.45);
    _shape.push_back(temp_point);
    temp_point.set(-0.4, y, -0.4);
    _shape.push_back(temp_point);
    temp_point.set(-0.3, y, -0.3);
    _shape.push_back(temp_point);
    temp_point.set(-0.3, y, -0.2);
    _shape.push_back(temp_point);
    temp_point.set(-0.15, y, -0.2);
    _shape.push_back(temp_point);
    temp_point.set(-0.1, y, -0.15);
    _shape.push_back(temp_point);
    temp_point.set(-0.1, y, 0.2);
    _shape.push_back(temp_point);
    temp_point.set(-0.15, y, 0.3);
    _shape.push_back(temp_point);
    temp_point.set(-0.15, y, 0.4);
    _shape.push_back(temp_point);
    temp_point.set(0.15, y, 0.4);
    _shape.push_back(temp_point);
    temp_point.set(0.15, y, 0.3);
    _shape.push_back(temp_point);
    temp_point.set(0.1, y, 0.2);
    _shape.push_back(temp_point);
    temp_point.set(0.1, y, -0.15);
    _shape.push_back(temp_point);
    temp_point.set(0.15, y, -0.2);
    _shape.push_back(temp_point);
    temp_point.set(0.3, y, -0.2);
    _shape.push_back(temp_point);
    temp_point.set(0.3, y, -0.3);
    _shape.push_back(temp_point);
    temp_point.set(0.4, y, -0.4);
    _shape.push_back(temp_point);
    temp_point.set(0.4, y, -0.45);
    _shape.push_back(temp_point);
}

void Pawn::show_fields() {
    int i = 1, max;
    max = _first ? 3 : 2;
    while (i != max && i < 64) {
        if (_src_board->get_element(_index + 8 * i).check_figure()) break;
        _src_board->get_element(_index + 8 * i).predict();
        i++;
    }
    if (_index % 8 != 7 && _src_board->get_element(_index + 8 + 1).check_figure() &&
                           _src_board->get_element(_index + 8 + 1).check_player() !=
                           _src_board->get_element(_index).check_player()) {
        _src_board->get_element(_index + 8 + 1).predict();
    }
    if (_index % 8 != 0 && _src_board->get_element(_index + 8 - 1).check_figure() &&
                           _src_board->get_element(_index + 8 - 1).check_player() !=
                           _src_board->get_element(_index).check_player()) {
        _src_board->get_element(_index + 8 - 1).predict();
    }
}

void Pawn::hide_fields() {
    int i = 1, max;
    max = _first ? 3 : 2;
    while (i != max && i < 64) {
        if (_src_board->get_element(_index + 8 * i).check_figure()) break;
        _src_board->get_element(_index + 8 * i).depredict();
        i++;
    }
    if (_index % 8 != 7 && _src_board->get_element(_index + 8 + 1).check_figure()) {
        _src_board->get_element(_index + 8 + 1).depredict();
    }
    if (_index % 8 != 0 && _src_board->get_element(_index + 8 - 1).check_figure()) {
        _src_board->get_element(_index + 8 - 1).depredict();
    }
}

void Pawn::transition(int index) {
    _index = index;
    _first = false;
}

void Pawn::set_index(int index) {
    _index = index;
}

figures Pawn::type() {
    return pawn;
}

void Pawn::show() {
    glBegin(GL_LINE_LOOP);
    glColor3f(1, 1, 1);
    for (auto &j : _shape) {
        glVertex3f(j.x + _index % 8 - 3.5, j.y, j.z + _index / 8 - 3.5);
    }
    glEnd();
}