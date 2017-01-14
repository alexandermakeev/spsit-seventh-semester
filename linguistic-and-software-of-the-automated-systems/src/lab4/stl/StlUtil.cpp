#include "StlUtil.h"

double StlUtil::multiplyVertices(Point a, Point b) {
    return a.getX() * b.getY() - b.getX() * a.getY();
}

bool StlUtil::isConvex(std::vector<Point> polygon) {
    double z = multiplyVertices(polygon[polygon.size()-1], polygon[0]);
    for (int i = 1; i < polygon.size(); ++i) {
        double p = multiplyVertices(polygon[i-1], polygon[i]) * z;
        if (p < 0) return false;
    }
    return true;
}

double StlUtil::evalFunction(Point directFrom, Point directTo, Point point) {
    return (directFrom.getY() - directTo.getY()) * point.getX() + (directTo.getX() - directFrom.getX()) * point.getY() +
           (directFrom.getX() * directTo.getY() - directTo.getX() * directFrom.getY());
}

bool StlUtil::isIntersect(Point directFrom, Point directTo, Point segmentFrom, Point segmentTo) {
    return evalFunction(directFrom, directTo, segmentFrom) > 0 ^ evalFunction(directFrom, directTo, segmentTo) > 0;
}

Point StlUtil::getLinesIntersection(Point a, Point b, Point c, Point d) {
    double a1 = a.getY() - b.getY();
    double a2 = c.getY() - d.getY();
    double b1 = b.getX() - a.getX();
    double b2 = d.getX() - c.getX();
    double c1 = b.getX() * a.getY() - a.getX() * b.getY();
    double c2 = d.getX() * c.getY() - c.getX() * d.getY();
    double delta = a1 * b2 - a2 * b1;
    if (delta == 0) throw "Линии коллинеарны";
    double x = (b2 * c1 - b1 * c2) / delta;
    double y = (a1 * c2 - a2 * c1) / delta;
    return Point(x, y);
}

std::vector<StlShape> StlUtil::dividePolygons(StlDirectPolygon directPolygon) {
    StlShape polygon = directPolygon.getPolygon();
    std::vector<Point> polygonPoints = polygon.getPoints();

    if (polygonPoints.size() < 3) throw "Многоугольник должен иметь минимум 3 координаты";

    if (!isConvex(polygonPoints)) throw "Многоугольник не является выпуклым";

    StlShape direct = directPolygon.getDirect();
    std::vector<Point> directPoints = direct.getPoints();
    if (directPoints.size() != 2) throw "Прямая должна иметь 2 координаты";

    const std::size_t polygonSize = polygonPoints.size();

    std::vector<StlShape> result;

    StlShape first("Многоугольник №1", std::vector<Point>());
    StlShape second("Многоугольник №1", std::vector<Point>());
    bool isFirst = true;

    for (int i = 0; i < polygonSize; ++i) {

        if (isFirst) first.getPoints().push_back(polygonPoints[i]);
        else second.getPoints().push_back(polygonPoints[i]);

        if (isIntersect(directPoints[0], directPoints[1], polygonPoints[i], polygonPoints[i+1])) {
            Point intersection = getLinesIntersection(directPoints[0], directPoints[1], polygonPoints[i], polygonPoints[i+1]);
            first.getPoints().push_back(intersection);
            second.getPoints().push_back(intersection);
            isFirst = !isFirst;
        }
    }

    if (second.getPoints().size() == 0) throw "Прямая не пересекает многоугольник";

    result.push_back(first);
    result.push_back(second);

    return result;
}
