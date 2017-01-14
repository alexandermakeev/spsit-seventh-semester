#ifndef UNTITLED_FILENOTFOUNDEXCEPTION_H
#define UNTITLED_FILENOTFOUNDEXCEPTION_H

class FileNotFoundException {
public:
    virtual const char *what() const throw() {
        return "Файл не найден";
    }
};

#endif //UNTITLED_FILENOTFOUNDEXCEPTION_H
