#pragma once
#include "Enums.hpp"
#include "Board.hpp"
#include "Figure.hpp"
#include "vector"

class Player {
public:
    explicit Player(Board *);
    void pick();
    void change_pos(direction);
    void mirror();
    bool path(int);
    ~Player();
private:
    std::vector<Figure *> _figures;
//    bool _active = false;
    int _position = 0;
    int _prev_position = 0;
    Board *_src_board;
};
