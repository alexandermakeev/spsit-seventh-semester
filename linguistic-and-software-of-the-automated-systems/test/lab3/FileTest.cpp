#include <gtest/gtest.h>
#include <dirent.h>
#include <fstream>
#include "../../src/lab3/File.h"
#include "../../src/lab3/exceptions/DirDoesNotExistException.h"
#include "../../src/lab3/exceptions/FileNotFoundException.h"
#include "../../src/lab3/Util.h"

TEST(test, exceptions_test) {
    File file;
    EXPECT_THROW(file.read("/home/alexander/1.txt", "/dir/does/not/exist"), DirDoesNotExistException);
    EXPECT_THROW(file.read("/path/to/file/does/not/exist", "/home/alexander/temp"), FileNotFoundException);
}

TEST(test, read_file_test) {
    File file;
    std::string pathToFile = "/home/alexander/1.txt";
    char dirPath[] = "/home/alexander/temp";
    file.read(pathToFile, dirPath);

    /*получение списка файлов в директории*/
    Util util;
    DIR *d;
    struct dirent *dir;
    d = opendir(dirPath);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            char inputPath[100];
            strcpy(inputPath, dirPath);
            strcat(inputPath, "/");
            strcat(inputPath, dir->d_name);

            /*проверка диалога в файле*/
            std::ifstream input(inputPath);
            std::string line;
            while (getline(input, line))
                EXPECT_TRUE(util.isDialog(line));
            input.close();
        }
        closedir(d);
        delete dir;
    }
}