#include "Element.hpp"
#include <cmath>
#include <GL/freeglut.h>
#include <GL/gl.h>

color_c element::color_check(colors needed_col) {
    color_c temp_color;
    switch (needed_col) {
        case white:
            temp_color.red = 1;
            temp_color.green = 1;
            temp_color.blue = 1;
            return temp_color;
        case yellow:
            temp_color.red = 1;
            temp_color.green = 1;
            temp_color.blue = 0;
            return temp_color;
        case green:
            temp_color.red = 0;
            temp_color.green = 1;
            temp_color.blue = 0;
            return temp_color;
        case red:
            temp_color.red = 1;
            temp_color.green = 0;
            temp_color.blue = 0;
            return temp_color;
        case blue:
            temp_color.red = 0;
            temp_color.green = 0;
            temp_color.blue = 1;
            return temp_color;
        case orange:
            temp_color.red = 1;
            temp_color.green = 0.55;
            temp_color.blue = 0;
            return temp_color;
        default:
            temp_color.red = 0.1;
            temp_color.green = 0.1;
            temp_color.blue = 0.1;
            return  temp_color;
    }
}

element::element(float position_x, float position_y, float position_z, colors temp_color_1,
                               colors temp_color_2, colors temp_color_3, colors temp_color_4, colors temp_color_5,
                               colors temp_color_6, orientation temp_orientation) {
    _orientation = temp_orientation;
    Point temp_position(position_x, position_y, position_z);
    _position = temp_position;
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

    poly_color.push_back(temp_color_1);
    poly_color.push_back(temp_color_2);
    poly_color.push_back(temp_color_3);
    poly_color.push_back(temp_color_4);
    poly_color.push_back(temp_color_5);
    poly_color.push_back(temp_color_6);
}
void element::draw() {
    color_c temp_color;
    double temp_x = 0, temp_y = 0, temp_z = 0;
    for (int i = 0; i < _faces.size(); i++) {
        temp_color = color_check(poly_color[i]);
        glBegin(GL_POLYGON);
        for (auto &j : _faces[i]) {
                glColor3f(temp_color.red, temp_color.green, temp_color.blue);
            switch (_rotation) {
                case no_rotation:
                    temp_x = j.x;
                    temp_y = j.y;
                    temp_z = j.z;
                    break;
                case UD_rot:
                    temp_x = j.x;
                    temp_y = (j.y) * cos(_angle) - (j.z) * sin(_angle);
                    temp_z = (j.z) * cos(_angle) + (j.y) * sin(_angle);
                    break;
                case LR_rot:
                    temp_x = (j.x) * cos(_angle) - (j.z) * sin(_angle);
                    temp_y = j.y;
                    temp_z = (j.z) * cos(_angle) + (j.x) * sin(_angle);
                    break;
                case CLOCK_rot:
                    temp_x = (j.x) * cos(_angle) - (j.y) * sin(_angle);
                    temp_y = (j.y) * cos(_angle) + (j.x) * sin(_angle);
                    temp_z = j.z;
                    break;
                default:
                    temp_x = j.x;
                    temp_y = j.y;
                    temp_z = j.z;
                    break;
            }
            glVertex3f(temp_x + _position.x, temp_y + _position.y,
                    temp_z + _position.z);
            j.x = temp_x;
            j.y = temp_y;
            j.z = temp_z;
        }
        glEnd();
    }
}