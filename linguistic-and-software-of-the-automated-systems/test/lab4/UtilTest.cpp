#include <gtest/gtest.h>
#include "../../src/lab4/Util.h"

TEST(test, util_test) {

    Util util;

    EXPECT_THROW(util.dividePolygons(DirectPolygon()), char const *); //пустые данные

    ArrayList<Point> polygonPoints;
    polygonPoints.add(Point(0, 3));
    polygonPoints.add(Point(3, 0));
    polygonPoints.add(Point(2, -3));
    polygonPoints.add(Point(-2, -3));
    polygonPoints.add(Point(-3, 0));

    Shape polygon(POLYGON, polygonPoints);

    ArrayList<Point> directPoints;
    directPoints.add(Point(1, 1));
    directPoints.add(Point(0, 0));

    Shape direct(DIRECT, directPoints);
    DirectPolygon directPolygon(polygon, direct);

    ArrayList<Shape> result = util.dividePolygons(directPolygon);

    EXPECT_TRUE(result.size() == 2); //количество многоугольников

    /*треугольник*/
    polygonPoints = ArrayList<Point>();
    polygonPoints.add(Point(0, 0));
    polygonPoints.add(Point(1, 0));
    polygonPoints.add(Point(0, 1));

    polygon = Shape(POLYGON, polygonPoints);
    directPolygon.setPolygon(polygon);
    result = util.dividePolygons(directPolygon);
    EXPECT_TRUE(result.size() == 2); //количество многоугольников


    /*квадрат*/
    polygonPoints = ArrayList<Point>();
    polygonPoints.add(Point(0, 0));
    polygonPoints.add(Point(1, 0));
    polygonPoints.add(Point(1, 1));
    polygonPoints.add(Point(0, 1));

    polygon = Shape(POLYGON, polygonPoints);
    directPolygon.setPolygon(polygon);
    result = util.dividePolygons(directPolygon);
    EXPECT_TRUE(result.size() == 2); //количество многоугольников
}
