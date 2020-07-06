#pragma once
#include "Point.hpp"
#include "Enums.hpp"

class Figure {
public:
    virtual void show_fields();
    virtual void transition(Point);
    virtual void show();
};

class Pawn : Figure {
public:
    void show_fields() override;
    void transition(Point) override;
    void show() override;
private:
    Point _poisition;
    colors _skin = red;
};

