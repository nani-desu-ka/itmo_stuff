#include "Castle.hpp"
#include "Board.hpp"
#include <GL/gl.h>

Castle::Castle(int index, Board *src_board) {
    _index = index;
    _src_board = src_board;
    float y = 0.501;
    _shape.resize(7);
    Point temp_point(-0.45, y, -0.45);
    _shape[0].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(-0.45, y, -0.25);
    _shape[0].push_back(temp_point);
    _line.push_back(temp_point);

    temp_point.set(-0.35, y, -0.25);
    _shape[1].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(-0.35, y, -0.15);
    _shape[1].push_back(temp_point);
    _line.push_back(temp_point);

    temp_point.set(-0.25, y, -0.15);
    _shape[2].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(-0.25, y, 0.15);
    _shape[2].push_back(temp_point);
    _line.push_back(temp_point);

    temp_point.set(-0.35, y, 0.15);
    _shape[3].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(-0.35, y, 0.3);
    _shape[3].push_back(temp_point);
    _line.push_back(temp_point);

    temp_point.set(-0.27, y, 0.3);
    _shape[4].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(-0.27, y, 0.4);
    _shape[4].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(0.27, y, 0.4);
    _shape[4].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(0.27, y, 0.3);
    _shape[4].push_back(temp_point);
    _line.push_back(temp_point);

    temp_point.set(0.35, y, 0.3);
    _shape[3].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(0.35, y, 0.15);
    _shape[3].push_back(temp_point);
    _line.push_back(temp_point);

    temp_point.set(0.25, y, 0.15);
    _shape[2].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(0.25, y, -0.15);
    _shape[2].push_back(temp_point);
    _line.push_back(temp_point);

    temp_point.set(0.35, y, -0.15);
    _shape[1].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(0.35, y, -0.25);
    _shape[1].push_back(temp_point);
    _line.push_back(temp_point);

    temp_point.set(0.45, y, -0.25);
    _shape[0].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(0.45, y, -0.45);
    _shape[0].push_back(temp_point);
    _line.push_back(temp_point);
}

void Castle::show_fields() {
//    if (_first) {}
    int i = _index;
    while (i % 8 != 7) {
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
    while (i % 8 != 0) {
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
    while (i / 8 != 7) {
        i += 8;
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
    while (i / 8 != 0) {
        i -= 8;
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

void Castle::hide_fields() {
    int i = _index;
    while (i % 8 != 7) {
        i += 1;
        _src_board->get_element(i).depredict();
    }
    i = _index;
    while (i / 8 != 7) {
        i += 8;
        _src_board->get_element(i).depredict();
    }
    i = _index;
    while (i % 8 != 0) {
        i -= 1;
        _src_board->get_element(i).depredict();
    }
    i = _index;
    while (i / 8 != 0) {
        i -= 8;
        _src_board->get_element(i).depredict();
    }
}

void Castle::transition(int index) {
    _index = index;
    _first = false;
}

void Castle::set_index(int index) {
    _index = index;
}

figures Castle::type() {
    return castle;
}

void Castle::show() {
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