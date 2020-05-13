#pragma once
#include "Interfaces.hpp"

class Circle : public Figure {
    CVector2D place;
    double radius;
    double weight;
    std::string name = "Circle";
public:
    Circle();
    ~Circle() = default;
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
