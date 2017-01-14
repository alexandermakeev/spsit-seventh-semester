#include <sys/stat.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include "File.h"
#include "Util.h"
#include "exceptions/FileNotFoundException.h"
#include "exceptions/DirDoesNotExistException.h"

bool File::isDirectory(std::string dirPath) {
    char pathArray[dirPath.length()];
    std::strcpy(pathArray, dirPath.c_str());
    struct stat sb;
    return stat(pathArray, &sb) == 0 && S_ISDIR(sb.st_mode);
}

void File::write(std::string pathToFile, std::string data) {
    std::ofstream output(pathToFile);
    output << data << std::endl;
    output.close();
}

/**
 * чтение файла
 * @pathToFile путь к файлу
 * @destDir путь к папке сохранения
 * */
void File::read(std::string pathToFile, std::string destDir) {
    std::ifstream input(pathToFile);
    if (!input.good()) throw FileNotFoundException(); //существование файла

    if (!isDirectory(destDir)) throw DirDoesNotExistException(); //существование папки
    destDir = destDir + '/'; //для сохранения в нее файлов

    Util util;
    int count = 0; //счетчик для наименования сохраняемых файлов
    std::string line;

    while (getline(input, line))
        if (util.isDialog(line))
            write(destDir + std::to_string(++count), line);

    input.close();
}
