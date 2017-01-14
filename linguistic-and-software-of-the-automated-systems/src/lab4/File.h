#ifndef UNTITLED_FILE_H
#define UNTITLED_FILE_H


#include <string>
#include "Shape.h"
#include "DirectPolygon.h"

class File {
    void writeShape(std::ofstream &output, Shape shape);

public:
    DirectPolygon read(std::string pathToFile);

    void write(std::string pathToFile, ArrayList<Shape> shapes, bool rewrite = false);

    void write(std::string pathToFile, DirectPolygon directPolygon, bool rewrite = false);
};


#endif //UNTITLED_FILE_H
