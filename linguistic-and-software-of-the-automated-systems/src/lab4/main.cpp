#include <cstddef>
#include <iostream>
#include <stdexcept>
#include "Util.h"
#include "File.h"
#include "Console.h"
#include "stl/StlFile.h"
#include "stl/StlUtil.h"
#include "stl/StlConsole.h"

#define CONSOLE_IN 1
#define READ_IN 2
#define EXIT 3
#define WRITE_OLD 1
#define WRITE_NEW 2
#define NEW_FILE 1
#define REWRITE 2
#define STL_DATA_STRUCTURES 1
#define CUSTOM_DATA_STRUCTURES 2

int custom() {

    Console console;
    File file;
    Util util;

    int mode;
    while (true) {

        while (true) {
            console.read(&mode, "1) Ввод с консоли \n2) Считать из файла \n3) Выход\nВыбор? ");
            if (mode == CONSOLE_IN || mode == READ_IN || mode == EXIT) break;
        }
        DirectPolygon directPolygon;

        if (mode == CONSOLE_IN) {
            directPolygon = console.read();
        } else if (mode == READ_IN) {

            std::string pathToFile;
            while (true) {
                std::cout << "Путь к файлу: ";
                std::cin >> pathToFile;
                try {
                    file.read(pathToFile);
                    break;
                } catch (const char * e) {
                    std::cerr << e;
                }
            }

            directPolygon = file.read(pathToFile);
        } else {
            return 0;
        }

        try {
            ArrayList<Shape> list = util.dividePolygons(directPolygon);

            while (true) {
                console.read(&mode, "1) Сохранить исходные данные \n2) Сохранить полученные данные \n3) Выход\nВыбор? ");
                if (mode == WRITE_OLD || mode == WRITE_NEW || mode == EXIT) break;
            }

            if (mode == EXIT) return 0;

            std::string pathToFile;
            while (true) {
                std::string expressionDialog = "Путь к файлу: ";
                std::cout << expressionDialog;
                std::cin >> pathToFile;
                try {
                    if (mode == WRITE_OLD) {
                        file.write(pathToFile, directPolygon);
                    } else {
                        file.write(pathToFile, list);
                    }
                    break;
                } catch (const char *e) {
                    std::cerr << e;
                    int writeMode;
                    while (true) {
                        console.read(&writeMode, "1) Выбрать другой файл \n2) Перезаписать\nВыбор? ");
                        if (writeMode == NEW_FILE || writeMode == REWRITE) break;
                    }

                    if (writeMode == REWRITE) {
                        if (mode == WRITE_OLD) {
                            file.write(pathToFile, directPolygon, true);
                        } else {
                            file.write(pathToFile, list, true);
                        }
                        break;
                    }
                }
            }
        } catch (const char *e) {
            std::cout << e << std::endl;
        }
    }
}

int stl() {

    StlFile file;
    StlUtil util;
    StlConsole console;

    int mode;
    while (true) {

        while (true) {
            console.read(&mode, "1) Ввод с консоли \n2) Считать из файла \n3) Выход\nВыбор? ");
            if (mode == CONSOLE_IN || mode == READ_IN || mode == EXIT) break;
        }
        StlDirectPolygon directPolygon;

        if (mode == CONSOLE_IN) {
            directPolygon = console.read();
        } else if (mode == READ_IN) {

            std::string pathToFile;
            while (true) {
                std::cout << "Путь к файлу: ";
                std::cin >> pathToFile;
                try {
                    file.read(pathToFile);
                    break;
                } catch (const char * e) {
                    std::cerr << e;
                }
            }

            directPolygon = file.read(pathToFile);
        } else {
            return 0;
        }

        try {
            std::vector<StlShape> list = util.dividePolygons(directPolygon);

            while (true) {
                console.read(&mode, "1) Сохранить исходные данные \n2) Сохранить полученные данные \n3) Выход\nВыбор? ");
                if (mode == WRITE_OLD || mode == WRITE_NEW || mode == EXIT) break;
            }

            if (mode == EXIT) return 0;

            std::string pathToFile;
            while (true) {
                std::string expressionDialog = "Путь к файлу: ";
                std::cout << expressionDialog;
                std::cin >> pathToFile;
                try {
                    if (mode == WRITE_OLD) {
                        file.write(pathToFile, directPolygon);
                    } else {
                        file.write(pathToFile, list);
                    }
                    break;
                } catch (const char *e) {
                    std::cerr << e;
                    int writeMode;
                    while (true) {
                        console.read(&writeMode, "1) Выбрать другой файл \n2) Перезаписать\nВыбор? ");
                        if (writeMode == NEW_FILE || writeMode == REWRITE) break;
                    }

                    if (writeMode == REWRITE) {
                        if (mode == WRITE_OLD) {
                            file.write(pathToFile, directPolygon, true);
                        } else {
                            file.write(pathToFile, list, true);
                        }
                        break;
                    }
                }
            }
        } catch (const char *e) {
            std::cout << e << std::endl;
        }
    }
}

int main() {

    std::cin.tie(&std::cout);

    std::cout << "                                      Добро пожаловать!\n\n"
              << "5 Заданы выпуклый многоугольник в плоскости и прямая. Определить, пересекает ли  \n"
              << "прямая многоугольник. Если пересекает, вычислить (создать) два многоугольника, на\n"
              << "которые исходный многоугольник был разделѐн прямой.\n"
              << "Выполнил студент:                                       Технлогического института\n"
              << "                                                                       группы 434\n"
              << "                                                   Макеев Александр Александрович\n\n"
              << "                                                                         2016 год\n";

    Console console;

    int mode;
    while (true) {
        console.read(&mode, "1) Использовать STL структуры данных \n2) Использовать разработанные структуры данных\nВыбор? ");
        if (mode == STL_DATA_STRUCTURES || mode == CUSTOM_DATA_STRUCTURES) break;
    }

    return mode == 1 ? stl() : custom();
}