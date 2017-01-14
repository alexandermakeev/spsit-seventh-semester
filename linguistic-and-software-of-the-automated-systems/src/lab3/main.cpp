#include <iostream>
#include <fstream>
#include <cstring>
#include "exceptions/DirDoesNotExistException.h"
#include "exceptions/FileNotFoundException.h"
#include "File.h"

int main() {

    std::cout << "                                      Добро пожаловать!\n\n"
              << "Выделить в заданном текстовом файле все диалоги (начинающиеся с новой строки и\n"
              << "символа «тире»). Сохранить диалоги в отдельных текстовых файлах. Использовать\n"
              << "правила построения диалогов, применяющиеся в русскоязычных текстах.\n"
              << "Примечание: В обязательном порядке протестировать программу на больших по\n"
              << "размеру текстах. \n\n"
              << "Выполнил студент:                                       Технлогического института\n"
              << "                                                                       группы 434\n"
              << "                                                   Макеев Александр Александрович\n\n"
              << "                                                                        2016 год.\n";

    File file;


    while (true) {
        while (true) {
            try {
                std::string pathToFile;
                std::cout << "Путь к файлу: ";
                getline(std::cin, pathToFile);

                std::string dirPath;
                std::cout << "Путь к папке: ";
                getline(std::cin, dirPath);

                file.read(pathToFile, dirPath);
                std::cout << "Диалоги записаны" << std::endl << std::endl;
                break;
            } catch (FileNotFoundException &e) {
                std::cout << e.what() << std::endl;
            } catch (DirDoesNotExistException &e) {
                std::cout << e.what() << std::endl;
            }
        }
    }

    return 0;
}
