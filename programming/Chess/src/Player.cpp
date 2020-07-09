#include "Player.hpp"
#include "Turn.hpp"

//Figures
#include "Pawn.hpp"
#include "Empty.hpp"
#include "Knight.hpp"
#include "Bishop.hpp"
#include "Castle.hpp"
#include "Queen.hpp"
#include "King.hpp"
//

Player::Player(Board *temp_board) {
    _src_board = temp_board;
    for (int i = 0; i < 8; i++) {
        if (i == 0 || i == 7) {
            _figures.push_back(new Castle(i, _src_board));
            _src_board->get_element(i).set_figure();
            _src_board->get_element(i).set_player();
            continue;
        }
        if (i == 1 || i == 6) {
            _figures.push_back(new Knight(i, _src_board));
            _src_board->get_element(i).set_figure();
            _src_board->get_element(i).set_player();
            continue;
        }
        if (i == 2 || i == 5) {
            _figures.push_back(new Bishop(i, _src_board));
            _src_board->get_element(i).set_figure();
            _src_board->get_element(i).set_player();
            continue;
        }
        _figures.push_back(new Empty());
    }
    for (int i = 8; i < 16; i++) {
        _figures.push_back(new Pawn(i, _src_board));
        _src_board->get_element(i).set_figure();
        _src_board->get_element(i).set_player();
    }
    for (int i = 16; i < 64; i++) {
        _figures.push_back(new Empty());
    }
}

void Player::board_prepare() {
    for (int i = 0; i < 64; i++) {
        if (_figures[i]->type() == empty) _src_board->get_element(i).set_another_player();
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

void Player::mirror() {
    for (int i = 0; i < 32; i++) {
        std::swap(_figures[i], _figures[63 - i]);
        _figures[i]->set_index(i);
        _figures[63 - i]->set_index(63 - i);
        if (first_mirror) {
            if (_figures[i]->type() != empty) {
                _src_board->get_element(i).set_figure();
                _src_board->get_element(i).set_player();
            } else {
                _src_board->get_element(i).destroy_figure();
            }
            if (_figures[63 - i]->type() != empty) {
                _src_board->get_element(63 - i).set_figure();
                _src_board->get_element(63 - i).set_player();
            } else {
                _src_board->get_element(63 - i).destroy_figure();
            }
        } else {
            if (_figures[i]->type() != empty) {
                _src_board->get_element(i).set_figure();
                _src_board->get_element(i).set_player();
            }
            if (_figures[63 - i]->type() != empty) {
                _src_board->get_element(63 - i).set_figure();
                _src_board->get_element(63 - i).set_player();
            }
        }
    }
    if (!first_mirror) {
        _figures[63 - prev_player_pos] = new Empty;
        _src_board->get_element(63 - prev_player_pos).set_another_player();
        _position = prev_player_pos;
        _src_board->get_element(_position).set_player_on();
    }
    first_mirror = !first_mirror;
}

void Player::pick() {
    _src_board->get_element(_prev_position).deactivate();
    if (_src_board->get_element(_position).predict_check()) {
        _src_board->get_element(_position).set_player_off();
        _figures[_prev_position]->hide_fields();
        _figures[_prev_position]->transition(_position);
        if (_position != _prev_position) {
            _figures[_position] = _figures[_prev_position];
            _figures[_prev_position] = new Empty();
            _src_board->get_element(_position).set_figure();
            _src_board->get_element(_prev_position).destroy_figure();
            _src_board->get_element(_position).set_player();
        }
        mirror();
        prev_player_pos = _position;
        turn++;
        turn %= 2;
        return;
    }
    _figures[_prev_position]->hide_fields();
    _prev_position = _position;
    if (!path(_position)) return;
    _src_board->get_element(_position).activate();
}

void Player::show() {
    for (auto j : _figures) {
        j->show();
    }
}

void Player::give_figure(figures temp_figure, int index) {
    switch (temp_figure) {
        case castle:
            _figures[index] = new Castle(index, _src_board);
            _src_board->get_element(index).set_player();
            _src_board->get_element(index).set_figure();
            return;
        case bishop:
            _figures[index] = new Bishop(index, _src_board);
            _src_board->get_element(index).set_player();
            _src_board->get_element(index).set_figure();
            return;
        case pawn:
            _figures[index] = new Pawn(index, _src_board);
            _src_board->get_element(index).set_player();
            _src_board->get_element(index).set_figure();
            return;
        case knight:
            _figures[index] = new Knight(index, _src_board);
            _src_board->get_element(index).set_player();
            _src_board->get_element(index).set_figure();
            return;
        case queen:
            _figures[index] = new Queen(index, _src_board);
            _src_board->get_element(index).set_player();
            _src_board->get_element(index).set_figure();
            return;
        case hideo_kojima:
            _figures[index] = new King(index, _src_board);
            _src_board->get_element(index).set_player();
            _src_board->get_element(index).set_figure();
            return;
        default:
            _figures[index] = new Empty();
    }
}
Player::~Player() {
    _figures.clear();
}