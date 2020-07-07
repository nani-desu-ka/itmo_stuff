#include "Bishop.hpp"
#include "Board.hpp"

Bishop::Bishop(int index, Board *src_board) {
    _index = index;
    _src_board = src_board;
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