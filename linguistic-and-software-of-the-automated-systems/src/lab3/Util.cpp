#include "Util.h"

bool Util::isPositive(std::size_t number) {
    return number != std::string::npos;
}

/** удаление whitespace в начале и в конце строки
 * @line входная строка */
std::string Util::trim(std::string line) {
    size_t end = line.find_last_not_of(" \t");
    if (isPositive(end)) line = line.substr(0, end + 1);
    size_t start = line.find_first_not_of(" \t");
    if (isPositive(start)) line = line.substr(start);
    return line;
}

/** начинается ли диалог с тире*/
bool Util::isDashed(std::string line) {
    std::size_t index = line.find(DASH);
    return isPositive(index) && index == 0; //первый символ строки
}

/** используются ли кавычки
 * @line строка*/
bool Util::isQuoted(std::string line) {
    std::size_t index = line.find(QUOTE_OPEN);
    if (!isPositive(index)) return false;
    if (index == 0) { //прямая речь в начале предложения
        /*прямая речь заключена в кавычки*/
        std::size_t end = line.find(QUOTE_CLOSE + " –"); //по окончание диалога используется тире
        if (isPositive(end)) return end > index;
        /*весь диалог заключен в кавычки*/
        end = line.find(QUOTE_CLOSE);
        return isPositive(end) && end > index;
    } else {
        //прямая речь после двоеточия
        std::size_t start = line.find(": " + QUOTE_OPEN);
        return isPositive(start) && start < index;
    }
}

bool Util::isDialog(std::string line) {
    line = trim(line);
    return isDashed(line) || isQuoted(line);
}
