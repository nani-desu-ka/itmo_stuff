#include "Knight.hpp"
#include "Board.hpp"
#include <GL/gl.h>

Knight::Knight(int index, Board *src_board) {
    _index = index;
    _src_board = src_board;
    float y = 0.501;
    _shape.resize(12);
    Point temp_point(-0.45, y, -0.45);
    _shape[0].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(-0.45, y, -0.36);
    _shape[0].push_back(temp_point);
    _line.push_back(temp_point);

    temp_point.set(-0.25, y, -0.36);
    _shape[1].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(-0.25, y, -0.3);
    _shape[1].push_back(temp_point);
    _line.push_back(temp_point);

    temp_point.set(-0.3, y, -0.3);
    _shape[2].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(-0.3, y, -0.17);
    _shape[2].push_back(temp_point);
    _line.push_back(temp_point);

    temp_point.set(-0.3, y, -0.17);
    _shape[3].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(-0.3, y, -0.07);
    _shape[3].push_back(temp_point);
    _line.push_back(temp_point);

    temp_point.set(-0.3, y, -0.07);
    _shape[4].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(-0.1, y, 0.13);
    _shape[4].push_back(temp_point);
    _line.push_back(temp_point);

    temp_point.set(-0.1, y, 0.13);
    _shape[5].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(-0.35, y, 0.01);
    _shape[5].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(-0.45, y, 0.13);
    _shape[5].push_back(temp_point);

    temp_point.set(-0.45, y, 0.13);
    _shape[6].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(-0.4, y, 0.23);
    _shape[6].push_back(temp_point);
    _line.push_back(temp_point);

    temp_point.set(-0.4, y, 0.23);
    _shape[7].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(-0.25, y, 0.35);
    _shape[7].push_back(temp_point);
    _line.push_back(temp_point);

    temp_point.set(-0.25, y, 0.35);
    _shape[8].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(-0.1, y, 0.4);
    _shape[8].push_back(temp_point);
    _line.push_back(temp_point);

    temp_point.set(0, y, 0.4);
    _shape[9].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(0.2, y, 0.5);
    _shape[9].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(0.2, y, 0.4);
    _shape[9].push_back(temp_point);
    _line.push_back(temp_point);

    temp_point.set(0.2, y, 0.4);
    _shape[8].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(0.25, y, 0.35);
    _shape[8].push_back(temp_point);
    _line.push_back(temp_point);

    temp_point.set(0.25, y, 0.35);
    _shape[7].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(0.35, y, 0.23);
    _shape[7].push_back(temp_point);
    _line.push_back(temp_point);

    temp_point.set(0.35, y, 0.23);
    _shape[6].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(0.35, y, 0.13);
    _shape[6].push_back(temp_point);
    _line.push_back(temp_point);

    temp_point.set(0.35, y, 0.13);
    _shape[4].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(0.3, y, -0.07);
    _shape[4].push_back(temp_point);
    _line.push_back(temp_point);

    temp_point.set(0.3, y, -0.07);
    _shape[3].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(0.3, y, -0.17);
    _shape[3].push_back(temp_point);
    _line.push_back(temp_point);

    temp_point.set(0.3, y, -0.17);
    _shape[2].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(0.4, y, -0.3);
    _shape[2].push_back(temp_point);
    _line.push_back(temp_point);

    temp_point.set(0.25, y, -0.3);
    _shape[1].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(0.25, y, -0.36);
    _shape[1].push_back(temp_point);
    _line.push_back(temp_point);

    temp_point.set(0.45, y, -0.36);
    _shape[0].push_back(temp_point);
    _line.push_back(temp_point);
    temp_point.set(0.45, y, -0.45);
    _shape[0].push_back(temp_point);
    _line.push_back(temp_point);
}

void Knight::show_fields() {
    if (_index % 8 != 7 && _index < 48) {
        if (_src_board->get_element(_index + 16 + 1).check_figure()) {
            if (_src_board->get_element(_index + 16 + 1).check_player() !=
                _src_board->get_element(_index).check_player()) {
                _src_board->get_element(_index + 16 + 1).predict();
            }
        } else {
            _src_board->get_element(_index + 16 + 1).predict();
        }
    }
    if (_index % 8 != 0 && _index < 48) {
        if (_src_board->get_element(_index + 16 - 1).check_figure()) {
            if (_src_board->get_element(_index + 16 - 1).check_player() !=
                _src_board->get_element(_index).check_player()) {
                _src_board->get_element(_index + 16 - 1).predict();
            }
        } else {
            _src_board->get_element(_index + 16 - 1).predict();
        }
    }
    if (_index % 8 != 7 && _index > 15) {
        if (_src_board->get_element(_index - 16 + 1).check_figure()) {
            if (_src_board->get_element(_index - 16 + 1).check_player() !=
                _src_board->get_element(_index).check_player()) {
                _src_board->get_element(_index - 16 + 1).predict();
            }
        } else {
            _src_board->get_element(_index - 16 + 1).predict();
        }
    }
    if (_index % 8 != 0 && _index > 15) {
        if (_src_board->get_element(_index - 16 - 1).check_figure()) {
            if (_src_board->get_element(_index - 16 - 1).check_player() !=
                _src_board->get_element(_index).check_player()) {
                _src_board->get_element(_index - 16 - 1).predict();
            }
        } else {
            _src_board->get_element(_index - 16 - 1).predict();
        }
    }
    if (_index % 8 < 6 && _index < 56) {
        if (_src_board->get_element(_index + 8 + 2).check_figure()) {
            if (_src_board->get_element(_index + 8 + 2).check_player() !=
                _src_board->get_element(_index).check_player()) {
                _src_board->get_element(_index + 8 + 2).predict();
            }
        } else {
            _src_board->get_element(_index + 8 + 2).predict();
        }
    }
    if (_index % 8 > 1 && _index < 56) {
        if (_src_board->get_element(_index + 8 - 2).check_figure()) {
            if (_src_board->get_element(_index + 8 - 2).check_player() !=
                _src_board->get_element(_index).check_player()) {
                _src_board->get_element(_index + 8 - 2).predict();
            }
        } else {
            _src_board->get_element(_index + 8 - 2).predict();
        }
    }
    if (_index % 8 < 6 && _index > 7) {
        if (_src_board->get_element(_index - 8 + 2).check_figure()) {
            if (_src_board->get_element(_index - 8 + 2).check_player() !=
                _src_board->get_element(_index).check_player()) {
                _src_board->get_element(_index - 8 + 2).predict();
            }
        } else {
            _src_board->get_element(_index - 8 + 2).predict();
        }
    }
    if (_index % 8 > 1 && _index > 7) {
        if (_src_board->get_element(_index - 8 - 2).check_figure()) {
            if (_src_board->get_element(_index - 8 - 2).check_player() !=
                _src_board->get_element(_index).check_player()) {
                _src_board->get_element(_index - 8 - 2).predict();
            }
        } else {
            _src_board->get_element(_index - 8 - 2).predict();
        }
    }
}

void Knight::hide_fields() {
    if (_index % 8 != 7 && _index < 48) {
        _src_board->get_element(_index + 16 + 1).depredict();
    }
    if (_index % 8 != 0 && _index < 48) {
        _src_board->get_element(_index + 16 - 1).depredict();
    }
    if (_index % 8 != 7 && _index > 15) {
        _src_board->get_element(_index - 16 + 1).depredict();
    }
    if (_index % 8 != 0 && _index > 15) {
        _src_board->get_element(_index - 16 - 1).depredict();
    }
    if (_index % 8 < 6 && _index < 56) {
        _src_board->get_element(_index + 8 + 2).depredict();
    }
    if (_index % 8 > 1 && _index < 56) {
        _src_board->get_element(_index + 8 - 2).depredict();
    }
    if (_index % 8 < 6 && _index > 7) {
        _src_board->get_element(_index - 8 + 2).depredict();
    }
    if (_index % 8 > 1 && _index > 7) {
        _src_board->get_element(_index - 8 - 2).depredict();
    }
}

void Knight::transition(int index) {
    _index = index;
}

void Knight::set_index(int index) {
    _index = index;
}

figures Knight::type() {
    return knight;
}

void Knight::show() {
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