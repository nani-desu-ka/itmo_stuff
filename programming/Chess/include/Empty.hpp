#pragma once
#include "Figure.hpp"
#include "Board.hpp"

class Empty : public Figure {
public:
    void show_fields() override;
    void hide_fields() override;
    void transition(int) override;
    void set_index(int) override;
    void show() override;
    figures type() override;
private:
    Board *_src_board;
};
