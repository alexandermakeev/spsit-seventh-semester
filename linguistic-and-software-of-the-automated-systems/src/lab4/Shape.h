#ifndef UNTITLED_SHAPE_H
#define UNTITLED_SHAPE_H


#include <string>
#include "Point.h"
#include "ArrayList.h"

class Shape {
    std::string name;
    ArrayList<Point> points;

public:
    Shape(const std::string &name, const ArrayList<Point> &points);

    Shape();

    const std::string &getName() const;

    void setName(const std::string &name);

    ArrayList<Point> &getPoints();

    void setPoints(const ArrayList<Point> &points);
};


#endif //UNTITLED_SHAPE_H
