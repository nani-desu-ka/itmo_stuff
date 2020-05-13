#include <iostream>
#include <cmath>
#include "Equil_triangle.hpp"

Equil_triangle::Equil_triangle() : side_size(0), weight(0) {}

void Equil_triangle::initFromDialog(){
    std::cout << "Enter coordinates" << '\n';
    std::cout << "~>x: ";
    std::cin >> place.x;
    std::cout << "~>y: ";
    std::cin >> place.y;
    std::cout << "Enter side length: \n~> ";
    std::cin >> side_size;
    std::cout << "Enter mass: \n~> ";
    std::cin >> weight;
}

double Equil_triangle::square() {
    return sqrt(3) * pow(side_size, 2) / 4;
}

double Equil_triangle::perimeter() {
    return 3 * side_size;
}

double Equil_triangle::mass() const {
    return weight;
}

CVector2D Equil_triangle::position() {
    return place;
}

bool Equil_triangle::operator== (const IPhysObject & circle) const {
    return mass() == circle.mass();
}

bool Equil_triangle::operator< (const IPhysObject & circle) const {
    return mass() < circle.mass();
}

void Equil_triangle::draw() {
    std::cout << "Square: " << square() << '\n';
    std::cout << "Perimeter: " << perimeter() << '\n';
    std::cout << "Equilateral triangle mass: " << mass() << '\n';
    std::cout << "Mass center: ";
    std::cout << "{" << position().x  << ", " << position().y << "}\n";
}

std::string Equil_triangle::classname() {
    return name;
}

unsigned int Equil_triangle::size() {
    return sizeof(*this);
}