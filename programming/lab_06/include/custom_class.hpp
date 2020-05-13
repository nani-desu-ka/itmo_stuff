#pragma once

class Point {
public:
    Point(int, int);
    friend bool operator> (Point, int);
    friend bool operator< (Point, int);
    friend bool operator== (Point, int);
    friend bool operator> (Point, Point);
    friend bool operator< (Point, Point);
    friend bool operator== (Point, Point);
    friend bool operator% (Point, int);
private:
    int x, y;
};
