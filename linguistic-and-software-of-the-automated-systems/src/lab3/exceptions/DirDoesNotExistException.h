#ifndef UNTITLED_DIRDOESNOTEXISTEXCEPTION_H
#define UNTITLED_DIRDOESNOTEXISTEXCEPTION_H

class DirDoesNotExistException {
public:
    virtual const char *what() const throw() {
        return "Папка не существует";
    }
};

#endif //UNTITLED_DIRDOESNOTEXISTEXCEPTION_H
