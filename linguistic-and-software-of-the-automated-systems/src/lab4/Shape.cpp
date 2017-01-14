#include "Shape.h"

Shape::Shape(const std::string &name, const ArrayList<Point> &points) : name(name), points(points) {}

Shape::Shape() {}

const std::string &Shape::getName() const {
    return name;
}

void Shape::setName(const std::string &name) {
    Shape::name = name;
}

ArrayList<Point> &Shape::getPoints() {
    return points;
}

void Shape::setPoints(const ArrayList<Point> &points) {
    Shape::points = points;
}

