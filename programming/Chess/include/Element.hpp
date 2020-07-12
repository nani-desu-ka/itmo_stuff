#pragma once
#include <vector>
#include "Point.hpp"
#include "Enums.hpp"
#include "Color_c.hpp"

class element {
public:
    element(float, float, float, float, float, colors);
    void draw();

    void set_player_on();
    void set_player_off();

    void activate();
    void deactivate();

    void predict();
    [[nodiscard]] bool predict_check() const;
    void depredict();

    void set_figure();
    void destroy_figure();
    bool check_figure();

    [[nodiscard]] int check_player() const;
    void set_player();
    void set_another_player();

    void finish();
    static color_c color_check(colors);
private:
    std::vector<std::vector<Point>> _faces;
    std::vector<colors> _colors;
    Point _position;
//    element_state _state = inactive;
    colors _buffer_color = none;
    int _which_player{};
    bool _player_on = false;
    bool _player_active = false;
    bool _player_predicted = false;
    bool _figure_on = false;
    bool _end_game = false;
};
