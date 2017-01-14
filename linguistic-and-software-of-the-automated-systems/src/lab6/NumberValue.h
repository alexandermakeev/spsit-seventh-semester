#ifndef UNTITLED_NUMBERVALUE_H
#define UNTITLED_NUMBERVALUE_H


#include "Value.h"

class NumberValue : public Value {
    const float value;
public:
    NumberValue(const float value) : value(value) {}

    virtual Value *evaluate() override {
        return this;
    }

    virtual std::string toString() override {
        return std::to_string(value);
    }

    virtual float toNumber() override {
        return value;
    }
};


#endif //UNTITLED_NUMBERVALUE_H
