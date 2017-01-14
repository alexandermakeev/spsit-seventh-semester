#include <iostream>
#include <typeinfo>
#include <sstream>
#include "Console.h"
#include "Util.h"

DirectPolygon Console::read() {

    int verticesSize;
    read(&verticesSize, "Введите количество вершин многоугольника: ");

    ArrayList<Point> polygonPoints((size_t) verticesSize);
    while (verticesSize-- > 0) {
        double x, y;
        read(&x, "x: ");
        read(&y, "y: ");
        polygonPoints.add(Point(x, y));
        std::cout << std::endl;
    }

    std::cout << "Введите координаты прямой" << std::endl;
    std::size_t const lineSize = 2;
    ArrayList<Point> directPoints(lineSize);
    for (int i = 0; i < lineSize; ++i) {
        double x, y;
        read(&x, "x: ");
        read(&y, "y: ");
        directPoints.add(Point(x, y));
        std::cout << std::endl;
    }

    return DirectPolygon(Shape(POLYGON, polygonPoints), Shape(DIRECT, directPoints));
}

/**
 * чтение простого типа из консоли
 * @value указатель на переменную
 * @out строка для диалога ввода
 * */
template<typename T>
void Console::read(T *value, std::string out) {
    std::cout << out; //вывод строки диалога ввода
    while (true) {
        std::string s;
        std::cin >> s; //ввод строки
        try { //попытка преобразовать в число
            std::stringstream ss(s);
            if ((ss >> *value).fail() || !(ss >> std::ws).eof()) {
                throw std::bad_cast();
            }
            break;
        } catch (...) {
            std::cerr << "Не удалось прочитать число\n";
            std::cerr << out;
        }
    }
}
