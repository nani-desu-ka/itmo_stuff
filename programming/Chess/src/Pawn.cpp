#include "Pawn.hpp"
#include "Board.hpp"
#include <GL/gl.h>

Pawn::Pawn(int index, Board *src_board) {
    _index = index;
    _src_board = src_board;
    float y = 0.501;
    _shape.resize(7);
    Point temp_point(-0.4, y, -0.45);
    _shape[0].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(-0.4, y, -0.4);
    _shape[0].push_back(temp_point);
    _line.push_back(temp_point);
    _shape[5].push_back(temp_point);
    temp_point.set(-0.3, y, -0.3);
    _shape[1].push_back(temp_point);
    _shape[5].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(-0.3, y, -0.2);
    _shape[1].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(-0.15, y, -0.2);
    _shape[2].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(-0.1, y, -0.15);
    _shape[2].push_back(temp_point);
    _shape[3].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(-0.1, y, 0.2);
    _shape[3].push_back(temp_point);
    _shape[6].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(-0.15, y, 0.3);
    _shape[4].push_back(temp_point);
    _shape[6].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(-0.15, y, 0.4);
    _shape[4].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(0.15, y, 0.4);
    _shape[4].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(0.15, y, 0.3);
    _shape[4].push_back(temp_point);
    _shape[6].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(0.1, y, 0.2);
    _shape[3].push_back(temp_point);
    _shape[6].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(0.1, y, -0.15);
    _shape[2].push_back(temp_point);
    _shape[3].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(0.15, y, -0.2);
    _shape[2].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(0.3, y, -0.2);
    _shape[1].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(0.3, y, -0.3);
    _shape[1].push_back(temp_point);
    _shape[5].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(0.4, y, -0.4);
    _shape[0].push_back(temp_point);
    _shape[5].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(0.4, y, -0.45);
    _shape[0].push_back(temp_point);
    _line.push_back(temp_point);
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
    int player = _src_board->get_element(_index).check_player();
    for (auto &i : _shape) {
        glColor3f((player + 1) % 2, (player + 1) % 2, (player + 1) % 2);
        glBegin(GL_POLYGON);
        for (auto &j : i) {
            glVertex3f(j.x + _index % 8 - 3.5, j.y, j.z + _index / 8 - 3.5);
        }
        glEnd();
    }
    glColor3f(player, player, player);
    glBegin(GL_LINE_LOOP);
    for (auto &j : _line) {
        glVertex3f(j.x + _index % 8 - 3.5, j.y + 0.01, j.z + _index / 8 - 3.5);
    }
    glEnd();
}