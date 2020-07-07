#pragma once
#include "Point.hpp"
#include "Enums.hpp"

class Figure {
public:
    virtual void show_fields() = 0;
    virtual void hide_fields() = 0;
    virtual void transition(int) = 0;
//    virtual void show() = 0;
//    virtual void get_player();
    virtual figures type() = 0;
};

