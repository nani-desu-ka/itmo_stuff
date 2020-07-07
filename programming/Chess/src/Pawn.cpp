#include "Pawn.hpp"
#include "Board.hpp"

Pawn::Pawn(int index, Board *src_board) {
    _index = index;
    _src_board = src_board;
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
    _src_board->get_element(_index).set_player();
}

void Pawn::set_index(int index) {
    _index = index;
}

figures Pawn::type() {
    return pawn;
}