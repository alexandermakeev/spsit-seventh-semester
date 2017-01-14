add_executable(lab3_test UtilTest.cpp FileTest.cpp ../../src/lab3/Util.cpp ../../src/lab3/File.cpp ../../src/lab3/File.h )

target_link_libraries(lab3_test gtest gtest_main)