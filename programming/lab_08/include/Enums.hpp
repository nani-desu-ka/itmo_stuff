#pragma once

enum colors {
    white,
    yellow,
    green,
    red,
    blue,
    orange,
    black,
};

enum el_type {
    _corner,
    _edge,
    _center,
};

enum orientation {
    straight,
    l_side,
    r_sight,
};

enum rotation {
    no_rotation,
    UD_rot,
    LR_rot,
    CLOCK_rot,
};

enum desolver {
    right_rot,
    right_r_rot,
    left_rot,
    left_r_rot,
    up_rot,
    up_r_rot,
    down_rot,
    down_r_rot,
    clock_l_rot,
    clock_r_rot,
};