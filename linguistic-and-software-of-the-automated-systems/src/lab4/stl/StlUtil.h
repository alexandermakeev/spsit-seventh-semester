#ifndef UNTITLED_STLUTIL_H
#define UNTITLED_STLUTIL_H


#include "StlDirectPolygon.h"

class StlUtil {
    double multiplyVertices(Point a, Point b);

    bool isConvex(std::vector<Point> polygon);

    double evalFunction(Point directFrom, Point directTo, Point point);

    bool isIntersect(Point directFrom, Point directTo, Point segmentFrom, Point segmentTo);

    Point getLinesIntersection(Point a, Point b, Point c, Point d);

public:
    std::vector<StlShape> dividePolygons(StlDirectPolygon directPolygon);
};


#endif //UNTITLED_STLUTIL_H
