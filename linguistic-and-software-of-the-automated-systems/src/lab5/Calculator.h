#ifndef UNTITLED_CALCULATOR_H
#define UNTITLED_CALCULATOR_H


#include <sstream>

class Calculator {
    const std::string OPERATORS = "+-*/^";

    float apply(char operation, float a, float b);

    bool hasPrecedence(char a, char b);

public:
    float evaluateExpression(std::istringstream &expression);
};


#endif //UNTITLED_CALCULATOR_H
