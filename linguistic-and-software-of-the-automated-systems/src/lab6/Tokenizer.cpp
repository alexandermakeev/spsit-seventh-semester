#include "Tokenizer.h"
#include "TokenizeState.h"

#include <iostream>

std::vector<Token> Tokenizer::tokenize(std::string content) {
    std::vector<Token> tokens;

    std::string charTokens = "\n=+-*/<>()";
    TokenType::Type tokenTypes[] = {
            TokenType::LINE,
            TokenType::EQUALS,
            TokenType::OPERATOR,
            TokenType::OPERATOR,
            TokenType::OPERATOR,
            TokenType::OPERATOR,
            TokenType::OPERATOR,
            TokenType::OPERATOR,
            TokenType::LEFT_PAREN,
            TokenType::RIGHT_PAREN,
    };

    std::string token = "";
    TokenizeState::State state = TokenizeState::DEFAULT;

    for (int i = 0; i < content.length(); i++) {
        char c = content[i];
        switch (state) {
            case TokenizeState::DEFAULT:
                if (charTokens.find(c) != std::string::npos) {
                    tokens.push_back(Token(std::string(1, c), tokenTypes[charTokens.find(c)]));
                } else if (isalpha(c)) {
                    token += c;
                    state = TokenizeState::WORD;
                } else if (isdigit(c)) {
                    token += c;
                    state = TokenizeState::NUMBER;
                } else if (c == '"') {
                    state = TokenizeState::STRING;
                }
                break;
            case TokenizeState::WORD:
                if (isalpha(c) || isdigit(c)) {
                    token += c;
                } else if (c == ':') {
                    tokens.push_back(Token(token, TokenType::LABEL));
                    token = "";
                    state = TokenizeState::DEFAULT;
                } else {
                    tokens.push_back(Token(token, TokenType::WORD));
                    token = "";
                    state = TokenizeState::DEFAULT;
                    i--; //default state
                }
                break;
            case TokenizeState::NUMBER:
                if (isdigit(c)) {
                    token += c;
                } else {
                    tokens.push_back(Token(token, TokenType::NUMBER));
                    token = "";
                    state = TokenizeState::DEFAULT;
                    i--; //default state
                }
                break;
            case TokenizeState::STRING:
                if (c == '"') {
                    tokens.push_back(Token(token, TokenType::STRING));
                    token = "";
                    state = TokenizeState::DEFAULT;
                } else {
                    token += c;
                }
                break;
        }
    }

    return tokens;

}
