#pragma once
#include <vector>

enum colors {
    white,
    yellow,
    green,
    red,
    blue,
    orange,
};

enum el_type {
    _corner,
    _edge,
    _center,
};

struct Point {
    int x, y;
};

class element {
public:
    virtual void draw() = 0;
    virtual el_type element_type() = 0;
private:
    Point position;
    std::vector<colors> poly_color;
};

class rubiks_cube {
public:
    rubiks_cube();
    void draw();
    void rotation(int);
    void find_element(colors, el_type);
    ~rubiks_cube();
private:
    std::vector<element*> elements;
};
class corner_element : element {
public:
    void draw() override;
    el_type element_type() override;
private:
    el_type _typename = _corner;
};

class center_element : element {
public:
    void draw() override;
    el_type element_type() override;
private:
    el_type _typename = _center;
};

class edge_element : element {
public:
    void draw() override;
    el_type element_type() override;
private:
    el_type _typename = _edge;
};