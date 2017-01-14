#include "DirectPolygon.h"

DirectPolygon::DirectPolygon() {}

DirectPolygon::DirectPolygon(const Shape &polygon, const Shape &direct) : polygon(polygon), direct(direct) {}

Shape &DirectPolygon::getPolygon() {
    return polygon;
}

void DirectPolygon::setPolygon(const Shape &polygon) {
    DirectPolygon::polygon = polygon;
}

Shape &DirectPolygon::getDirect() {
    return direct;
}

void DirectPolygon::setDirect(const Shape &direct) {
    DirectPolygon::direct = direct;
}
