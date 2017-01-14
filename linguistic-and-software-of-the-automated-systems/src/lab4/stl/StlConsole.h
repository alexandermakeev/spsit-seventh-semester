#ifndef UNTITLED_STLCONSOLE_H
#define UNTITLED_STLCONSOLE_H


#include "StlDirectPolygon.h"
#include "../Console.h"

class StlConsole {
    Console console;
public:
    template<typename T>
    void read(T *value, std::string out) {
        console.read(value, out);
    }
    StlDirectPolygon read();
};

#endif //UNTITLED_STLCONSOLE_H
