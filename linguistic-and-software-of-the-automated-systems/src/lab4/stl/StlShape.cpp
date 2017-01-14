#include "StlShape.h"

StlShape::StlShape() {}

StlShape::StlShape(const std::string &name, const std::vector<Point> &points) : name(name), points(points) {}

const std::string &StlShape::getName() const {
    return name;
}

void StlShape::setName(const std::string &name) {
    StlShape::name = name;
}

std::vector<Point> &StlShape::getPoints() {
    return points;
}

void StlShape::setPoints(const std::vector<Point> &points) {
    StlShape::points = points;
}
