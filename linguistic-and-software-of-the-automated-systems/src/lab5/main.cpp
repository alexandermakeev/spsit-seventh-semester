#include <iostream>
#include "Calculator.h"

int main() {

    std::cout << "Разбор и вычисление математических выражений (калькулятор)\n"
              << "Выполнил студент                                434 группы\n"
              << "                                          Макеев Александр\n"
              << "                                                      2016\n\n";

    Calculator calculator;

    std::cin.tie(&std::cout);

    for (;;) {

        std::string data;
        std::cout << "Введите выражение: ";
        getline(std::cin, data);

        std::istringstream expression(data.c_str());

        try {
            std::cout << "Результат: " << calculator.evaluateExpression(expression);
        } catch (char const *e) {
            std::cerr << e << std::endl;
        }

        std::cout << std::endl << std::endl;

    }

}