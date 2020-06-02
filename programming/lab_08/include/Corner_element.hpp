#pragma once
#include "Interfaces.hpp"

class corner_element : element {
public:
    void draw() override;
    el_type element_type() override;
private:
    el_type _typename = _corner;
};
