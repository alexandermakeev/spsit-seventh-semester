#ifndef UNTITLED_OPERATOREXPRESSION_H
#define UNTITLED_OPERATOREXPRESSION_H


#include "Expression.h"
#include "Value.h"
#include "NumberValue.h"
#include "StringValue.h"

class OperatorExpression : public Expression {
    Expression *left;
    Expression *right;
    const char operation;
public:
    OperatorExpression(Expression *left, Expression *right, const char operation) : left(left), right(right),
                                                                                  operation(operation) {}

    virtual Value *evaluate() override {

        Value *leftVal = left->evaluate();
        Value *rightVal = right->evaluate();

        switch (operation) {
            case '=':
                if (NumberValue *v = dynamic_cast<NumberValue *>(leftVal)) {
                    return new NumberValue((leftVal->toNumber() == rightVal->toNumber()) ? 1 : 0);
                } else {
                    return new NumberValue(leftVal->toString() == rightVal->toString() ? 1 : 0);
                }
            case '+':
                if (NumberValue *v = dynamic_cast<NumberValue *>(leftVal)) {
                    return new NumberValue(leftVal->toNumber() + rightVal->toNumber());
                } else {
                    return new StringValue(leftVal->toString() + rightVal->toString());
                }
            case '-':
                return new NumberValue(leftVal->toNumber() - rightVal->toNumber());
            case '*':
                return new NumberValue(leftVal->toNumber() * rightVal->toNumber());
            case '/':
                return new NumberValue(leftVal->toNumber() / rightVal->toNumber());
            case '<':
                if (NumberValue *v = dynamic_cast<NumberValue *>(leftVal)) {
                    return new NumberValue((leftVal->toNumber() < rightVal->toNumber()) ? 1 : 0);
                } else {
                    return new NumberValue((leftVal->toString() < rightVal->toString()) ? 1 : 0);
                }
            case '>':
                if (NumberValue *v = dynamic_cast<NumberValue *>(leftVal)) {
                    return new NumberValue((leftVal->toNumber() > rightVal->toNumber()) ? 1 : 0);
                } else {
                    return new NumberValue((leftVal->toString() > rightVal->toString()) ? 1 : 0);
                }
        }
        throw "Unknown operator.";

    }
};


#endif //UNTITLED_OPERATOREXPRESSION_H
