#include <fstream>
#include <stdexcept>
#include <iostream>
#include "StlFile.h"
#include "../Util.h"

StlDirectPolygon StlFile::read(std::string pathToFile) {
    std::ifstream input(pathToFile);
    if (!input.good()) throw "Файл не найден";
    std::string str;
    getline(input, str);
    if (str != POLYGON) throw "Многоугольник не найден";

    std::vector<double> polygon;

    while (getline(input, str)) {
        if (str != DIRECT) {
            try {
                polygon.push_back(std::stod(str));
            } catch (std::invalid_argument &e) {
                throw "Не удалось прочитать данные";
            }
        } else {
            if (polygon.size() % 2 != 0) throw "Многоугольник должен иметь четное число точек";
            break;
        }
    }

    const std::size_t directSize = 4;
    std::vector<double> direct;
    while (getline(input, str)) {
        try {
            direct.push_back(std::stod(str));
        } catch (std::invalid_argument &e) {
            throw "Не удалось прочитать данные";
        }
    }
    if (direct.size() != directSize) throw "Прямая должна иметь 2 координаты";

    const std::size_t polygonSize = polygon.size();
    std::vector<Point> polygonPoints;
    for (int i = 0; i < polygonSize; i += 2) {
        polygonPoints.push_back(Point(polygon[i], polygon[i + 1]));
    }

    std::vector<Point> directPoints;
    for (int i = 0; i < directSize; i += 2) {
        directPoints.push_back(Point(direct[i], direct[i + 1]));
    }

    return StlDirectPolygon(StlShape(POLYGON, polygonPoints), StlShape(DIRECT, directPoints));
}

void StlFile::write(std::string pathToFile, std::vector<StlShape> shapes, bool rewrite) {
    std::ifstream input(pathToFile);
    if (input.good() && !rewrite) throw "Файл существует";

    std::ofstream output(pathToFile);

    for (int i = 0; i < shapes.size(); ++i) {
        writeShape(output, shapes[i]);
    }
}

void StlFile::write(std::string pathToFile, StlDirectPolygon directPolygon, bool rewrite) {
    std::ifstream input(pathToFile);
    if (input.good() && !rewrite) throw "Файл существует";

    std::ofstream output(pathToFile);

    writeShape(output, directPolygon.getPolygon());
    writeShape(output, directPolygon.getDirect());
}

void StlFile::writeShape(std::ofstream &output, StlShape shape) {
    output << shape.getName() << std::endl;
    std::vector<Point> points = shape.getPoints();
    for (int j = 0; j < points.size(); ++j) {
        Point point = points[j];
        output << point.getX() << std::endl << point.getY() << std::endl;
    }
}
