#ifndef UNTITLED_STLSHAPE_H
#define UNTITLED_STLSHAPE_H


#include <string>
#include <vector>
#include "../Point.h"

class StlShape {
    std::string name;
    std::vector<Point> points;

public:
    StlShape();

    StlShape(const std::string &name, const std::vector<Point> &points);

    const std::string &getName() const;

    void setName(const std::string &name);

    std::vector<Point> &getPoints();

    void setPoints(const std::vector<Point> &points);
};


#endif //UNTITLED_STLSHAPE_H
