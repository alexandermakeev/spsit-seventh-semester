#ifndef UNTITLED_ASSIGNSTATEMENT_H
#define UNTITLED_ASSIGNSTATEMENT_H


#include <string>
#include "Expression.h"
#include "Statement.h"
#include "Common.h"

class AssignStatement : public Statement {
    const std::string name;
    Expression *value;

public:
    AssignStatement(const std::string &name, Expression *value) : name(name), value(value) {}

    virtual void execute() override {
        variables[name] = value->evaluate();
    }
};


#endif //UNTITLED_ASSIGNSTATEMENT_H
