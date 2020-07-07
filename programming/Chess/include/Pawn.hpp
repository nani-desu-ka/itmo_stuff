#pragma once
#include "Figure.hpp"
#include "Board.hpp"

class Pawn : public Figure {
public:
    Pawn(int, Board *);
    void show_fields() override;
    void hide_fields() override;
    void transition(int) override;
//    void show() override;
    figures type() override;
private:
    bool _first = true;
    int _index;
    Board *_src_board;
};
