#include "Bishop.hpp"
#include "Board.hpp"
#include <GL/gl.h>

Bishop::Bishop(int index, Board *src_board) {
    _index = index;
    _src_board = src_board;
    float y = 0.501;
    _shape.resize(3);
    Point temp_point(-0.4, y, -0.45);
    _shape[0].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(-0.4, y, -0.4);
    _shape[0].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(-0.2, y, -0.3);
    _shape[0].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(-0.15, y, -0.25);
    _shape[0].push_back(temp_point);
    _line.push_back(temp_point);

    temp_point.set(-0.1, y, -0.25);
    _shape[1].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(-0.1, y, 0.1);
    _shape[1].push_back(temp_point);
    _shape[2].push_back(temp_point);
    _line.push_back(temp_point);

    temp_point.set(-0.2, y, 0.2);
    _shape[2].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(-0.2, y, 0.3);
    _shape[2].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(0, y, 0.45);
    _shape[2].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(0.2, y, 0.3);
    _shape[2].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(0.2, y, 0.2);
    _shape[2].push_back(temp_point);
    _line.push_back(temp_point);

    temp_point.set(0.1, y, 0.1);
    _shape[1].push_back(temp_point);
    _shape[2].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(0.1, y, -0.25);
    _shape[1].push_back(temp_point);
    _line.push_back(temp_point);

    temp_point.set(0.15, y, -0.25);
    _shape[0].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(0.2, y, -0.3);
    _shape[0].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(0.4, y, -0.4);
    _shape[0].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(0.4, y, -0.45);
    _shape[0].push_back(temp_point);
    _line.push_back(temp_point);
}

void Bishop::show_fields() {
    int i = _index;
    while (i % 8 != 7 && i / 8 != 7) {
        i += 8;
        i += 1;
        if (_src_board->get_element(i).check_figure()) {
            if (_src_board->get_element(i).check_player() !=
                _src_board->get_element(_index).check_player()) {
                _src_board->get_element(i).predict();
                break;
            } else {
                break;
            }
        } else {
            _src_board->get_element(i).predict();
        }
    }
    i = _index;
    while (i % 8 != 0 && i / 8 != 7) {
        i += 8;
        i -= 1;
        if (_src_board->get_element(i).check_figure()) {
            if (_src_board->get_element(i).check_player() !=
                _src_board->get_element(_index).check_player()) {
                _src_board->get_element(i).predict();
                break;
            } else {
                break;
            }
        } else {
            _src_board->get_element(i).predict();
        }
    }
    i = _index;
    while (i % 8 != 0 && i / 8 != 0) {
        i -= 8;
        i -= 1;
        if (_src_board->get_element(i).check_figure()) {
            if (_src_board->get_element(i).check_player() !=
                _src_board->get_element(_index).check_player()) {
                _src_board->get_element(i).predict();
                break;
            } else {
                break;
            }
        } else {
            _src_board->get_element(i).predict();
        }
    }
    i = _index;
    while (i % 8 != 7 && i / 8 != 0) {
        i -= 8;
        i += 1;
        if (_src_board->get_element(i).check_figure()) {
            if (_src_board->get_element(i).check_player() !=
                _src_board->get_element(_index).check_player()) {
                _src_board->get_element(i).predict();
                break;
            } else {
                break;
            }
        } else {
            _src_board->get_element(i).predict();
        }
    }
}

void Bishop::hide_fields() {
    int i = _index;
    while (i % 8 != 7 && i / 8 != 7) {
        i += 8;
        i += 1;
        _src_board->get_element(i).depredict();
    }
    i = _index;
    while (i % 8 != 0 && i / 8 != 7) {
        i += 8;
        i -= 1;
        _src_board->get_element(i).depredict();
    }
    i = _index;
    while (i % 8 != 0 && i / 8 != 0) {
        i -= 8;
        i -= 1;
        _src_board->get_element(i).depredict();
    }
    i = _index;
    while (i % 8 != 7 && i / 8 != 0) {
        i -= 8;
        i += 1;
        _src_board->get_element(i).depredict();
    }
}

void Bishop::transition(int index) {
    _index = index;
}

void Bishop::set_index(int index) {
    _index = index;
}

figures Bishop::type() {
    return bishop;
}

void Bishop::show() {
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