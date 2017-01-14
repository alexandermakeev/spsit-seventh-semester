#ifndef UNTITLED_STLDIRECTPOLYGON_H
#define UNTITLED_STLDIRECTPOLYGON_H


#include "StlShape.h"

class StlDirectPolygon {
    StlShape polygon;
    StlShape direct;

public:
    StlDirectPolygon();

    StlDirectPolygon(const StlShape &polygon, const StlShape &direct);

    StlShape &getPolygon();

    void setPolygon(const StlShape &polygon);

    StlShape &getDirect();

    void setDirect(const StlShape &direct);
};


#endif //UNTITLED_STLDIRECTPOLYGON_H
