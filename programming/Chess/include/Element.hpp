#pragma once
#include <vector>
#include "Point.hpp"
#include "Enums.hpp"
#include "Color_c.hpp"

class element {
public:
    element(float, float, float, colors);
    void draw();

    void set_player_on();
    void set_player_off();

    void activate();
    void deactivate();

    void predict();
    bool predict_check();
    void depredict();

    void set_figure();
    void destroy_figure();
    bool check_figure();

    static color_c color_check(colors);
private:
    std::vector<std::vector<Point>> _faces;
    std::vector<colors> _colors;
    Point _position;
//    element_state _state = inactive;
    colors _buffer_color = none;
    bool _player_on = false;
    bool _player_active = false;
    bool _player_predicted = false;
    bool _figure_on = false;
};
