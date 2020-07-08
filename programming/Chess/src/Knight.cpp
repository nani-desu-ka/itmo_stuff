#include "Knight.hpp"
#include "Board.hpp"

Knight::Knight(int index, Board *src_board) {
    _index = index;
    _src_board = src_board;
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

void Knight::show() {}