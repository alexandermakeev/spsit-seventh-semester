#include <gtest/gtest.h>
#include "../../src/lab5/Calculator.h"


TEST(test, calc_test) {

    Calculator calculator;

    std::istringstream incorrectExpression("incorrect expression");
    EXPECT_THROW(calculator.evaluateExpression(incorrectExpression), char const *);

    std::istringstream divideByZero("5/0");
    EXPECT_THROW(calculator.evaluateExpression(divideByZero), char const *);

    struct Test {
        const char *expression;
        float result;
    };

    Test tests[] = {{"1+2",                           3},
                    {"2*2",                           4},
                    {"1+2^10",                        1025},
                    {"12+23*(4+2*3)",                 242},
                    {"((2+3.2)*(3.5+2))",             28.6f},
                    {"((2+3.2)*(3.5+2)+1.2)*(7.2+5)", 363.56f},
    };

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i) {
        std::istringstream expression(tests[i].expression);
        EXPECT_FLOAT_EQ(calculator.evaluateExpression(expression), tests[i].result);
    }
}