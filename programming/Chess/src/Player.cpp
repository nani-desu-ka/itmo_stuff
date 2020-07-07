#include "Player.hpp"
#include "Pawn.hpp"
#include "Empty.hpp"

Player::Player(Board *temp_board) {
    _src_board = temp_board;
    for (int i = 0; i < 8; i++) {
        _figures.push_back(new Empty());
    }
    _figures.push_back(new Pawn(8, _src_board));
    _src_board->get_element(8).set_figure();
    for (int i = 9; i < 17; i++) {
        _figures.push_back(new Empty());
    }
    _figures.push_back(new Pawn(17, _src_board));
    _src_board->get_element(17).set_figure();
    for (int i = 18; i < 64; i++) {
        _figures.push_back(new Empty());
    }
}

void Player::change_pos(direction temp_direction) {
    _src_board->get_element(_position).set_player_off();
    switch (temp_direction) {
        case up:
            _position += 8;
            _position = _position > 63 ? _position - 8 : _position;
            _src_board->get_element(_position).set_player_on();
            return;
        case down:
            _position -= 8;
            _position = _position < 0 ? _position + 8 : _position;
            _src_board->get_element(_position).set_player_on();
            return;
        case left:
            if (_position % 8 != 0) _position--;
            _src_board->get_element(_position).set_player_on();
            return;
        case right:
            if (_position % 8 != 7) _position++;
            _src_board->get_element(_position).set_player_on();
            return;
    }
}

bool Player::path(int index) {
    if (_figures[index]->type() == empty) return false;
    _figures[index]->show_fields();
    return true;
}

void Player::pick() {
    _src_board->get_element(_prev_position).deactivate();
    if (_src_board->get_element(_position).predict_check()) {
        _figures[_prev_position]->hide_fields();
        _figures[_prev_position]->transition(_position);
        if (_position != _prev_position) {
            _figures[_position] = _figures[_prev_position];
            _figures[_prev_position] = new Empty();
            _src_board->get_element(_position).set_figure();
            _src_board->get_element(_prev_position).destroy_figure();
        }
        return;
    }
    _figures[_prev_position]->hide_fields();
    _prev_position = _position;
    if (!path(_position)) return;
    _src_board->get_element(_position).activate();
}

Player::~Player() {
    _figures.clear();
}