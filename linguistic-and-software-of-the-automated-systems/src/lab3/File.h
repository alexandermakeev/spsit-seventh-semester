#ifndef UNTITLED_FILE_H
#define UNTITLED_FILE_H

#include <string>

class File {
    bool isDirectory(std::string dirPath);

    void write(std::string pathToFile, std::string data);

public:
    void read(std::string pathToFile, std::string destDir);
};

#endif //UNTITLED_FILE_H
