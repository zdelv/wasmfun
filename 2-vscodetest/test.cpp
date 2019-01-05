#include <iostream>
#include <emscripten.h>
#include <emscripten/bind.h>
#include <cmath>

class Point {
private:
    int x;
    int y;

public:
    int getX() const { return this->x; }
    void setX(int _x) { this->x = _x; }
    int getY() const { return this->y; }
    void setY(int _y) { this->y = _y; }

    float distanceToOrigin() {
        return std::sqrt(std::pow(this->getX(), 2) + std::pow(this->getY(), 2));
    }

    Point(int _x, int _y)
        : x(_x), y(_y) {}
};

EMSCRIPTEN_BINDINGS(point_test) {
    emscripten::class_<Point>("Point")
        .constructor<int, int>()
        .property("x", &Point::getX, &Point::setX)
        .property("y", &Point::getY, &Point::setY)
        .function("distanceToOrigin", &Point::distanceToOrigin)
        ;
}