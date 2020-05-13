#include <cmath>
#include <iostream>
#include "Circle.hpp"

Circle::Circle() : radius(0), weight(0) {}

void Circle::initFromDialog(){
    std::cout << "Введите координаты" << '\n';
    std::cout << "~>x: ";
    std::cin >> place.x;
    std::cout << "~>y: ";
    std::cin >> place.y;
    std::cout << "Введите радиус: \n~> ";
    std::cin >> radius;
    std::cout << "Введите массу: \n~> ";
    std::cin >> weight;
}

double Circle::square() {
    return M_PI * pow(radius, 2);
}

double Circle::perimeter() {
    return 2 * M_PI * radius;
}

double Circle::mass() const {
    return weight;
}

CVector2D Circle::position() {
    return place;
}

bool Circle::operator== (const IPhysObject & circle) const {
    return mass() == circle.mass();
}

bool Circle::operator< (const IPhysObject & circle) const {
    return mass() < circle.mass();
}

void Circle::draw() {
    std::cout << "Площадь: " << square() << '\n';
    std::cout << "Периметр: " << perimeter() << '\n';
    std::cout << "Масса круга: " << mass() << '\n';
    std::cout << "Центр масс: ";
    std::cout << "{" << position().x  << ", " << position().y << "}\n";
}

std::string Circle::classname() {
    return name;
}

unsigned int Circle::size() {
    return sizeof(*this);
}