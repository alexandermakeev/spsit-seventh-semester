#include "StlDirectPolygon.h"

StlDirectPolygon::StlDirectPolygon() {}

StlDirectPolygon::StlDirectPolygon(const StlShape &polygon, const StlShape &direct) : polygon(polygon),
                                                                                      direct(direct) {}

StlShape &StlDirectPolygon::getPolygon() {
    return polygon;
}

void StlDirectPolygon::setPolygon(const StlShape &polygon) {
    StlDirectPolygon::polygon = polygon;
}

StlShape &StlDirectPolygon::getDirect() {
    return direct;
}

void StlDirectPolygon::setDirect(const StlShape &direct) {
    StlDirectPolygon::direct = direct;
}
