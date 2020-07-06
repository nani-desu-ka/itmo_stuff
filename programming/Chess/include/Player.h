#pragma once
#include "Enums.hpp"
#include "Board.hpp"

class Player {
public:
    Player(Board *);
    void pick(int);
    void change_pos(direction);
private:
    bool _active;
    int _position = 0;
    Board *_src_board;
};
