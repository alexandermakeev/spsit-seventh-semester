#ifndef UNTITLED_STLFILE_H
#define UNTITLED_STLFILE_H


#include <string>
#include "StlDirectPolygon.h"
#include "../Shape.h"
#include "../File.h"

class StlFile {
    void writeShape(std::ofstream &output, StlShape shape);
public:
    StlDirectPolygon read(std::string pathToFile);

    void write(std::string pathToFile, std::vector<StlShape> shapes, bool rewrite = false);

    void write(std::string pathToFile, StlDirectPolygon directPolygon, bool rewrite = false);
};


#endif //UNTITLED_STLFILE_H
