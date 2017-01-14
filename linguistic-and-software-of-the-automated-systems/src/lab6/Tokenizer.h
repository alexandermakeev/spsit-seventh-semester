#ifndef UNTITLED_TOKENIZER_H
#define UNTITLED_TOKENIZER_H


#include <vector>
#include <sstream>
#include "Token.h"

class Tokenizer {
public:
    std::vector<Token> tokenize(std::string content);
};


#endif //UNTITLED_TOKENIZER_H
