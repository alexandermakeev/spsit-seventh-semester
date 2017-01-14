add_executable(lab5_test CalculatorTest.cpp ../../src/lab5/Calculator.h ../../src/lab5/Calculator.cpp)
target_link_libraries(lab5_test gtest gtest_main)