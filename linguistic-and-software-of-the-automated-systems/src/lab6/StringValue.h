#ifndef UNTITLED_STRINGVALUE_H
#define UNTITLED_STRINGVALUE_H


#include "Value.h"

class StringValue : public Value {
    const std::string value;
public:
    StringValue(const std::string value) : value(value) {}

    virtual Value *evaluate() override {
        return this;
    }

    virtual std::string toString() override {
        return value;
    }

    virtual float toNumber() override {
        return std::stof(value);
    }
};


#endif //UNTITLED_STRINGVALUE_H
