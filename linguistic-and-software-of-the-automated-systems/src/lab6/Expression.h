#ifndef UNTITLED_EXPRESSION_H
#define UNTITLED_EXPRESSION_H

class Value;

class Expression {
public:
    virtual Value *evaluate() = 0;
};


#endif //UNTITLED_EXPRESSION_H
