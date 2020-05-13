#include "custom_class.hpp"

Point::Point(int x, int y) : x(x), y(y) {};

bool operator> (Point left, int right) {
 return left.x > right;
}

bool operator< (Point left, int right) {
    return left.x < right;
}

bool operator== (Point left, int right) {
    return left.x == right;
}

bool operator> (Point left, Point right) {
    return left.x > right.x;
}

bool operator< (Point left, Point right) {
    return left.x < right.x;
}

bool operator== (Point left, Point right) {
    return left.x == right.x;
}

bool operator% (Point left, int right) {
    return left.x % right;
}