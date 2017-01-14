#ifndef UNTITLED_VALUE_H
#define UNTITLED_VALUE_H


#include <string>
#include "Expression.h"

class Value : public Expression {
public:
    virtual std::string toString() = 0;

    virtual float toNumber() = 0;
};


#endif //UNTITLED_VALUE_H
