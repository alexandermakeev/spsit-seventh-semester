#ifndef UNTITLED_VARIABLEEXPRESSION_H
#define UNTITLED_VARIABLEEXPRESSION_H


#include <string>
#include "Expression.h"
#include "NumberValue.h"
#include "Common.h"

class VariableExpression : public Expression {
    const std::string name;
public:
    VariableExpression(const std::string &name) : name(name) {}

    virtual Value *evaluate() override {
        if (variables.count(name)) {
            return variables[name];
        }
        return new NumberValue(0);
    }
};


#endif //UNTITLED_VARIABLEEXPRESSION_H
