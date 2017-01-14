#ifndef UNTITLED_DIRECTPOLYGON_H
#define UNTITLED_DIRECTPOLYGON_H


#include "Shape.h"

class DirectPolygon {
    Shape polygon;
    Shape direct;

public:
    DirectPolygon();

    DirectPolygon(const Shape &polygon, const Shape &direct);

    Shape &getPolygon();

    void setPolygon(const Shape &polygon);

    Shape &getDirect();

    void setDirect(const Shape &direct);
};


#endif //UNTITLED_DIRECTPOLYGON_H
