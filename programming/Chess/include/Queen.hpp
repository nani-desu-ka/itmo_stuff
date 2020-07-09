#pragma once
#include "Figure.hpp"
#include "Board.hpp"
#include <vector>

class Queen : public Figure {
public:
    Queen(int, Board *);
    void show_fields() override;
    void hide_fields() override;
    void transition(int) override;
    void set_index(int) override;
    void show() override;
    figures type() override;
private:
    int _index;
    Board *_src_board;
    std::vector<std::vector<Point>> _shape;
    std::vector<Point> _line;
};
