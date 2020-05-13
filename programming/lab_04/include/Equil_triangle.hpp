#pragma once
#include "Interfaces.hpp"

class Equil_triangle : public Figure {
    CVector2D place;
    double side_size;
    double weight;
    std::string name = "Равнобедренный треугольник";
public:
    Equil_triangle();
    ~Equil_triangle() = default;
    void initFromDialog() override;
    double square() override;
    double perimeter() override;
    double mass() const override;
    CVector2D position() override;
    bool operator< (const IPhysObject &) const override;
    bool operator== (const IPhysObject &) const override;
    unsigned int size() override;
    void draw() override;
    std::string classname() override;
};
