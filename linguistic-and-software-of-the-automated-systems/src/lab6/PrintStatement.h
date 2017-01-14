#ifndef UNTITLED_PRINTSTATEMENT_H
#define UNTITLED_PRINTSTATEMENT_H


#include <iostream>
#include "Statement.h"
#include "Expression.h"
#include "Value.h"

class PrintStatement : public Statement {
    Expression *expression;
public:
    PrintStatement(Expression *expression) : expression(expression) {}

    virtual void execute() override {
        std::cout << expression->evaluate()->toString() << std::endl;
    }
};


#endif //UNTITLED_PRINTSTATEMENT_H
