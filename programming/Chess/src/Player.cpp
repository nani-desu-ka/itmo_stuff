#include "Player.h"

Player::Player(Board *temp_board) {
    _src_board = temp_board;
}

void Player::change_pos(direction temp_direction) {
    _src_board->get_element(_position).set_player_off();
    switch (temp_direction) {
        case up:
            _position += 8;
            _position %= 64;
            _src_board->get_element(_position).set_player_on();
            return;
        case down:
            _position -= 8;
            _position %= 64;
            _src_board->get_element(_position).set_player_on();
            return;
        case left:
            _position--;
            _position %= 64;
            _src_board->get_element(_position).set_player_on();
            return;
        case right:
            _position++;
            _position %= 64;
            _src_board->get_element(_position).set_player_on();
            return;
    }
}