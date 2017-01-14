#ifndef UNTITLED_CONSOLE_H
#define UNTITLED_CONSOLE_H


#include "Shape.h"
#include "DirectPolygon.h"

class Console {
public:
    template<typename T>
    void read(T *value, std::string out);
    DirectPolygon read();
};


#endif //UNTITLED_CONSOLE_H
