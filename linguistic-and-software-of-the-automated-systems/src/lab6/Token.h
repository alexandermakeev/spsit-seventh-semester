#ifndef UNTITLED_TOKEN_H
#define UNTITLED_TOKEN_H


#include <string>
#include "TokenType.h"

class Token {
public:
    const std::string text;
    const TokenType::Type type;

    Token(const std::string &text, const TokenType::Type type);
};


#endif //UNTITLED_TOKEN_H
