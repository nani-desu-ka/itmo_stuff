// Single cube draw

#include "Element.hpp"
#include "Enums.hpp"
#include <cmath>
#include <GL/freeglut.h>
#include <GL/gl.h>

color_c element::color_check(colors needed_col) {
    color_c temp_color;
    switch (needed_col) {
        case white:
            temp_color.red = 1;
            temp_color.green = 0.87;
            temp_color.blue = 0.60;
            return temp_color;
        case brown:
            temp_color.red = 0.36;
            temp_color.green = 0.07;
            temp_color.blue = 0.01;
            return temp_color;
        case dark_brown:
            temp_color.red = 0.17;
            temp_color.green = 0.03;
            temp_color.blue = 0;
            return temp_color;
        case darkest_brown:
            temp_color.red = 0.12;
            temp_color.green = 0.02;
            temp_color.blue = 0;
            return temp_color;
        case green:
            temp_color.red = 0;
            temp_color.green = 1;
            temp_color.blue = 0;
            return temp_color;
        case positive_green:
            temp_color.red = 0;
            temp_color.green = 0.5;
            temp_color.blue = 0;
            return temp_color;
        case red:
            temp_color.red = 1;
            temp_color.green = 0;
            temp_color.blue = 0;
            return temp_color;
        case yellow:
            temp_color.red = 1;
            temp_color.green = 1;
            temp_color.blue = 0;
            return temp_color;
        default:
            temp_color.red = 0.14;
            temp_color.green = 0;
            temp_color.blue = 0;
            return temp_color;
    }
}

element::element(float position_x, float position_y, float position_z, colors temp_color_1) {
    Point temp_position(position_x, position_y, position_z);
    _position = temp_position;
    _buffer_color = temp_color_1;
    _faces.resize(6);

    Point temp_point(0.5, -0.5, -0.5);
    _faces[0].push_back(temp_point);
    temp_point.set(0.5, 0.5, -0.5);
    _faces[0].push_back(temp_point);
    temp_point.set(-0.5, 0.5, -0.5);
    _faces[0].push_back(temp_point);
    temp_point.set(-0.5, -0.5, -0.5);
    _faces[0].push_back(temp_point);

    temp_point.set(0.5, 0.5, 0.5);
    _faces[1].push_back(temp_point);
    temp_point.set(0.5, 0.5, -0.5);
    _faces[1].push_back(temp_point);
    temp_point.set(-0.5, 0.5, -0.5);
    _faces[1].push_back(temp_point);
    temp_point.set(-0.5, 0.5, 0.5);
    _faces[1].push_back(temp_point);

    temp_point.set(-0.5, -0.5, 0.5);
    _faces[2].push_back(temp_point);
    temp_point.set(-0.5, 0.5, 0.5);
    _faces[2].push_back(temp_point);
    temp_point.set(-0.5, 0.5, -0.5);
    _faces[2].push_back(temp_point);
    temp_point.set(-0.5, -0.5, -0.5);
    _faces[2].push_back(temp_point);

    temp_point.set(0.5, -0.5, -0.5);
    _faces[3].push_back(temp_point);
    temp_point.set(0.5, 0.5, -0.5);
    _faces[3].push_back(temp_point);
    temp_point.set(0.5, 0.5, 0.5);
    _faces[3].push_back(temp_point);
    temp_point.set(0.5, -0.5, 0.5);
    _faces[3].push_back(temp_point);

    temp_point.set(0.5, -0.5, -0.5);
    _faces[4].push_back(temp_point);
    temp_point.set(0.5, -0.5, 0.5);
    _faces[4].push_back(temp_point);
    temp_point.set(-0.5, -0.5, 0.5);
    _faces[4].push_back(temp_point);
    temp_point.set(-0.5, -0.5, -0.5);
    _faces[4].push_back(temp_point);

    temp_point.set(0.5, -0.5, 0.5);
    _faces[5].push_back(temp_point);
    temp_point.set(0.5, 0.5, 0.5);
    _faces[5].push_back(temp_point);
    temp_point.set(-0.5, 0.5, 0.5);
    _faces[5].push_back(temp_point);
    temp_point.set(-0.5, -0.5, 0.5);
    _faces[5].push_back(temp_point);

    _colors.push_back(black);
    _colors.push_back(_buffer_color);
    _colors.push_back(black);
    _colors.push_back(black);
    _colors.push_back(darkest_brown);
    _colors.push_back(black);
}

void element::draw() {
    color_c temp_color;
    int i = 0;
    for (auto &_face : _faces) {
        temp_color = color_check(_colors[i]);
        if (i == 1) {
            if (_player_on) {
                temp_color = color_check(yellow);
            }
        }
        glBegin(GL_POLYGON);
        glColor3f(temp_color.red, temp_color.green, temp_color.blue);
        for (auto &j : _face) {
            glVertex3f(j.x + _position.x, j.y + _position.y, j.z + _position.z);
        }
        glEnd();
        i++;
    }
}

void element::set_player_on() {
    _player_on = true;
}

void element::set_player_off() {
    _player_on = false;
}