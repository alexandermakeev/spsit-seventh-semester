#include <fstream>
#include <stdexcept>
#include "File.h"
#include "Util.h"

DirectPolygon File::read(std::string pathToFile) {
    std::ifstream input(pathToFile);
    if (!input.good()) throw "Файл не найден";
    std::string str;
    getline(input, str);
    if (str != POLYGON) throw "Многоугольник не найден";

    ArrayList<double> polygon;

    while (getline(input, str)) {
        if (str != DIRECT) {
            try {
                polygon.add(std::stod(str));
            } catch (std::invalid_argument &e) {
                throw "Не удалось прочитать данные";
            }
        } else {
            if (polygon.size() % 2 != 0) throw "Многоугольник должен иметь четное число точек";
            break;
        }
    }

    const std::size_t lineSize = 4;
    ArrayList<double> line(lineSize);
    while (getline(input, str)) {
        try {
            line.add(std::stod(str));
        } catch (std::invalid_argument &e) {
            throw "Не удалось прочитать данные";
        }
    }
    if (line.size() != lineSize) throw "Прямая должна иметь 2 координаты";

    const std::size_t polygonSize = polygon.size();
    ArrayList<Point> polygonPoints(polygonSize / 2);
    for (int i = 0; i < polygonSize; i += 2) {
        polygonPoints.add(Point(polygon.get(i), polygon.get(i + 1)));
    }

    ArrayList<Point> directPoints(lineSize / 2);
    for (int i = 0; i < lineSize; i += 2) {
        directPoints.add(Point(line.get(i), line.get(i + 1)));
    }

    return DirectPolygon(Shape(POLYGON, polygonPoints), Shape(DIRECT, directPoints));
}

void File::write(std::string pathToFile, ArrayList<Shape> shapes, bool rewrite) {

    std::ifstream input(pathToFile);
    if (input.good() && !rewrite) throw "Файл существует";

    std::ofstream output(pathToFile);

    for (int i = 0; i < shapes.size(); ++i) {
        writeShape(output, shapes.get(i));
    }
}

void File::write(std::string pathToFile, DirectPolygon directPolygon, bool rewrite) {
    std::ifstream input(pathToFile);
    if (input.good() && !rewrite) throw "Файл существует";

    std::ofstream output(pathToFile);

    writeShape(output, directPolygon.getPolygon());
    writeShape(output, directPolygon.getDirect());
}

void File::writeShape(std::ofstream &output, Shape shape) {
    output << shape.getName() << std::endl;
    ArrayList<Point> points = shape.getPoints();
    for (int j = 0; j < points.size(); ++j) {
        Point point = points.get(j);
        output << point.getX() << std::endl << point.getY() << std::endl;
    }
}
