#include <gtest/gtest.h>
#include "../../src/lab4/File.h"
#include "../../src/lab4/Util.h"

TEST(test, file_test) {

    /*read tests*/
    int linePointsSize = 2;
    int polygonPointsSize = 5;

    File file;
    Util util;

    EXPECT_THROW(file.read("/file/does/not/exist"), char const *); //файл не существует
    DirectPolygon directPolygon = file.read("/home/alexander/ClionProjects/untitled/test/lab4/data/read.txt");
    EXPECT_TRUE(directPolygon.getDirect().getPoints().size() == linePointsSize); //количество точек прямой
    EXPECT_TRUE(directPolygon.getPolygon().getPoints().size() == polygonPointsSize); //количество точек многоугольника

    std::string outPath = "/home/alexander/ClionProjects/untitled/test/lab4/data/write.txt";

    /*исходные данные*/
    EXPECT_THROW(file.write(outPath, DirectPolygon()), char const *); //файл уже существует
    EXPECT_NO_THROW(file.write(outPath, DirectPolygon(), true)); //пустые данные
    EXPECT_NO_THROW(file.write(outPath, directPolygon, true));

    /*результаты*/
    ArrayList<Shape> shapes = util.dividePolygons(directPolygon);
    EXPECT_THROW(file.write(outPath, shapes), char const *);
    EXPECT_NO_THROW(file.write(outPath, shapes, true));
}