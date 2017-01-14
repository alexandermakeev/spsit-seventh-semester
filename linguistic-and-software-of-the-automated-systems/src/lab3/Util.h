#ifndef UNTITLED_UTIL_H
#define UNTITLED_UTIL_H

#include <cstddef>
#include <string>

static const std::string DASH = "–";
static const std::string QUOTE_OPEN = "«";
static const std::string QUOTE_CLOSE = "»";

class Util {
    bool isPositive(std::size_t number);

    std::string trim(std::string line);

    bool isDashed(std::string line);

    bool isQuoted(std::string line);

public:
    bool isDialog(std::string line);
};

#endif //UNTITLED_UTIL_H
