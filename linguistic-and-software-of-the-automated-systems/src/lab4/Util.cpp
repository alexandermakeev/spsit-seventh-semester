#include "Util.h"

double Util::multiplyVertices(Point a, Point b) {
    return a.getX() * b.getY() - b.getX() * a.getY();
}

/** является ли многоугольник выпуклым, произведение векторов должно быть одного знака
 * @points точки, составляющие многоугольник
 * @size размер массива */
bool Util::isConvex(ArrayList<Point> polygon) {
    double z = multiplyVertices(polygon.last(), polygon.first());
    for (int i = 1; i < polygon.size(); ++i) {
        double p = multiplyVertices(polygon.get(i - 1), polygon.get(i)) * z;
        if (p < 0) return false;
    }
    return true;
}

/**расчет значения уравнения прямой
 * @directFrom @directTo отрезок прямой
 * @point значения x и y функции прямой*/
double Util::evalFunction(Point directFrom, Point directTo, Point point) {
    return (directFrom.getY() - directTo.getY()) * point.getX() + (directTo.getX() - directFrom.getX()) * point.getY() +
           (directFrom.getX() * directTo.getY() - directTo.getX() * directFrom.getY());
}

/** пересечение прямой и отрезка многоугольника
 * точки отрезка должны принадлежать разным полуплоскостям и значения выражения должны быть разных знаков
 * @directFrom, @directTo прямая
 * @segment отрезок многоугольника
 * */
bool Util::isIntersect(Point directFrom, Point directTo, Point segmentFrom, Point segmentTo) {
    return evalFunction(directFrom, directTo, segmentFrom) > 0 ^ evalFunction(directFrom, directTo, segmentTo) > 0;
}

/** точка пересечения уравнений
 * @a, @b первый отрезок
 * @c, @d второй отрезок*/
Point Util::getLinesIntersection(Point a, Point b, Point c, Point d) {
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

ArrayList<Shape> Util::dividePolygons(DirectPolygon directPolygon) {

    Shape polygon = directPolygon.getPolygon();
    ArrayList<Point> polygonPoints = polygon.getPoints();

    if (polygonPoints.size() < 3) throw "Многоугольник должен иметь минимум 3 координаты";

    if (!isConvex(polygonPoints)) throw "Многоугольник не является выпуклым";

    Shape direct = directPolygon.getDirect();
    ArrayList<Point> directPoints = direct.getPoints();
    if (directPoints.size() != 2) throw "Прямая должна иметь 2 координаты";

    const std::size_t polygonSize = polygonPoints.size();

    ArrayList<Shape> result;

    Shape first("Многоугольник №1", ArrayList<Point>());
    Shape second("Многоугольник №2", ArrayList<Point>());
    bool isFirst = true;

    for (int i = 0; i < polygonSize; ++i) {

        if (isFirst) first.getPoints().add(polygonPoints.get(i));
        else second.getPoints().add(polygonPoints.get(i));

        if (isIntersect(directPoints.get(0), directPoints.get(1), polygonPoints.get(i), polygonPoints.get(i + 1))) {
            Point intersection;
            try {
                intersection = getLinesIntersection(directPoints.get(0), directPoints.get(1), polygonPoints.get(i),
                                                          polygonPoints.get(i + 1));
            } catch (char const *) {
                throw "Прямая не пересекает многоугольник";
            }
            first.getPoints().add(intersection);
            second.getPoints().add(intersection);
            isFirst = !isFirst;
        }
    }

    if (second.getPoints().size() == 0) throw "Прямая не пересекает многоугольник";

    result.add(first);
    result.add(second);

    return result;
}
