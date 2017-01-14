#ifndef UNTITLED_IFTHENSTATEMENT_H
#define UNTITLED_IFTHENSTATEMENT_H


#include <string>
#include "Statement.h"
#include "Expression.h"
#include "Common.h"

class IfThenStatement : public Statement {
    Expression *condition;
    const std::string label;

public:
    IfThenStatement(Expression *condition, const std::string &label) : condition(condition), label(label) {}

    virtual void execute() override {
        if (labels.count(label)) {
            float value = condition->evaluate()->toNumber();
            if (value != 0) {
                currentStatement = labels[label];
            }
        }
    }
};


#endif //UNTITLED_IFTHENSTATEMENT_H
