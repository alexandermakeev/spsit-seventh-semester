#include <gtest/gtest.h>
#include "../../../src/lab4/stl/StlUtil.h"
#include "../../../src/lab4/Util.h"

TEST(test, stl_util_test) {

    StlUtil util;

    EXPECT_THROW(util.dividePolygons(StlDirectPolygon()), char const *); //пустые данные

    std::vector<Point> polygonPoints;
    polygonPoints.push_back(Point(0, 3));
    polygonPoints.push_back(Point(3, 0));
    polygonPoints.push_back(Point(2, -3));
    polygonPoints.push_back(Point(-2, -3));
    polygonPoints.push_back(Point(-3, 0));

    StlShape polygon(POLYGON, polygonPoints);

    std::vector<Point> directPoints;
    directPoints.push_back(Point(1, 1));
    directPoints.push_back(Point(0, 0));

    StlShape direct(DIRECT, directPoints);
    StlDirectPolygon directPolygon(polygon, direct);

    std::vector<StlShape> result = util.dividePolygons(directPolygon);

    EXPECT_TRUE(result.size() == 2); //количество многоугольников

    /*треугольник*/
    polygonPoints = std::vector<Point>();
    polygonPoints.push_back(Point(0, 0));
    polygonPoints.push_back(Point(1, 0));
    polygonPoints.push_back(Point(0, 1));

    polygon = StlShape(POLYGON, polygonPoints);
    directPolygon.setPolygon(polygon);
    result = util.dividePolygons(directPolygon);
    EXPECT_TRUE(result.size() == 2); //количество многоугольников


    /*квадрат*/
    polygonPoints = std::vector<Point>();
    polygonPoints.push_back(Point(0, 0));
    polygonPoints.push_back(Point(1, 0));
    polygonPoints.push_back(Point(1, 1));
    polygonPoints.push_back(Point(0, 1));

    polygon = StlShape(POLYGON, polygonPoints);
    directPolygon.setPolygon(polygon);
    result = util.dividePolygons(directPolygon);
    EXPECT_TRUE(result.size() == 2); //количество многоугольников
}
