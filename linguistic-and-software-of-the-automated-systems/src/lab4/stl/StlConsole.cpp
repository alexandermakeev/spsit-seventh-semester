#include <iostream>
#include "StlConsole.h"
#include "../Util.h"

StlDirectPolygon StlConsole::read() {
    int verticesSize;
    console.read(&verticesSize, "Введите количество вершин многоугольника: ");

    std::vector<Point> polygonPoints;
    while (verticesSize-- > 0) {
        double x, y;
        console.read(&x, "x: ");
        console.read(&y, "y: ");
        polygonPoints.push_back(Point(x, y));
        std::cout << std::endl;
    }

    std::cout << "Введите координаты прямой" << std::endl;
    std::size_t const lineSize = 2;
    std::vector<Point> directPoints;
    for (int i = 0; i < lineSize; ++i) {
        double x, y;
        console.read(&x, "x: ");
        console.read(&y, "y: ");
        directPoints.push_back(Point(x, y));
        std::cout << std::endl;
    }

    return StlDirectPolygon(StlShape(POLYGON, polygonPoints), StlShape(DIRECT, directPoints));
}