#ifndef UNTITLED_UTIL_H
#define UNTITLED_UTIL_H


#include <cstddef>
#include "Point.h"
#include "../lab1/Stack.h"
#include "ArrayList.h"
#include "Shape.h"
#include "DirectPolygon.h"

static const std::string POLYGON = "polygon";
static const std::string DIRECT = "direct";

class Util {
    double multiplyVertices(Point a, Point b);

    bool isConvex(ArrayList<Point> polygon);

    double evalFunction(Point directFrom, Point directTo, Point point);

    bool isIntersect(Point directFrom, Point directTo, Point segmentFrom, Point segmentTo);

    Point getLinesIntersection(Point a, Point b, Point c, Point d);

public:
    ArrayList<Shape> dividePolygons(DirectPolygon directPolygon);
};


#endif //UNTITLED_UTIL_H
