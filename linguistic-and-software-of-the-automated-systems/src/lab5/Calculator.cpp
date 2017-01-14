#include <cmath>
#include <stack>
#include <iostream>
#include "Calculator.h"

/**вычисление выражения
 * @expression выражение*/
float Calculator::evaluateExpression(std::istringstream &expression) {
    std::stack<float> digits;
    std::stack<char> operators;
    while (true) {
        //получение токена
        char token;
        expression >> token;
        if (!expression) break;
        if (token == ' ') continue; //whitespace
        if (isdigit(token) || token == '.') {
            /* получение числа */
            expression.putback(token);
            float digit;
            expression >> digit;
            digits.push(digit);
        } else if (token == '(') {
            operators.push(token);
        } else if (token == ')') {
            //выталкивание операций
            while (operators.top() != '(') {
                float a = digits.top();
                digits.pop();
                float b = digits.top();
                digits.pop();
                digits.push(apply(operators.top(), a, b));
                operators.pop();
            }
            operators.pop();
        } else if (OPERATORS.find(token) != std::string::npos) { //операция
            while (operators.size() != 0 &&
                   hasPrecedence(token, operators.top())) { //пока старые операции приоритетней новой
                float a = digits.top();
                digits.pop();
                float b = digits.top();
                digits.pop();
                digits.push(apply(operators.top(), a, b));
                operators.pop();
            }
            operators.push(token);
        } else throw "Can't read an expression";
    }

    while (operators.size() != 0) {
        float a = digits.top();
        digits.pop();
        float b = digits.top();
        digits.pop();
        digits.push(apply(operators.top(), a, b));
        operators.pop();
    }

    return digits.top();
}

/**вычисление значения
 * @operation операция
 * @a, @b числа
 */
float Calculator::apply(char operation, float b, float a) {
    switch (operation) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) throw "Divide by zero";
            return a / b;
        case '^':
            return (float) pow(a, b);
    }
    return 0;
}

/**
 * @a, b операторы
 * возвращает true если b имеет более высокий приоритет, чем a
 * */
bool Calculator::hasPrecedence(char a, char b) {
    return !(b == '(' || b == ')') && !((a == '*' || a == '/' || a == '^') && (b == '+' || b == '-'));
}
