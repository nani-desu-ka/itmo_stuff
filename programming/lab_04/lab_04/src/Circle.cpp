#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "Circle.hpp"

Circle::Circle() : radius(0), weight(0) {}

void Circle::initFromDialog(){
    std::cout << "Enter coordinates" << '\n';
    std::cout << "~>x: ";
    std::cin >> place.x;
    std::cout << "~>y: ";
    std::cin >> place.y;
    std::cout << "Enter radius: \n~> ";
    std::cin >> radius;
    std::cout << "Enter mass: \n~> ";
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
    std::cout << "Square: " << square() << '\n';
    std::cout << "Perimeter: " << perimeter() << '\n';
    std::cout << "Circle mass: " << mass() << '\n';
    std::cout << "Mass center: ";
    std::cout << "{" << position().x  << ", " << position().y << "}\n";
}

std::string Circle::classname() {
    return name;
}

unsigned int Circle::size() {
    return sizeof(*this);
}