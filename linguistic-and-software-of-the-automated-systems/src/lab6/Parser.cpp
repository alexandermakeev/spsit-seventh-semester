#include "Parser.h"

Parser::Parser(const std::vector<Token> &tokens) : tokens(tokens) {
    position = 0;
}

/** returns next two tokens if they're given type*/
bool Parser::match(TokenType::Type type1, TokenType::Type type2) {
    if (get(0).type != type1 || get(1).type != type2) return false;
    position += 2;
    return true;
}

/** returns unconsumed token */
Token Parser::get(int offset) {
    if (position + offset >= tokens.size()) {
        return Token("", TokenType::_EOF);
    }
    return tokens[position + offset];
}

/** returns previously consumed token*/
Token Parser::last(int offset) {
    return tokens[position - offset];
}

/** returns next token if it's given name and WORD TokenType, otherwise throws an exception*/
Token Parser::consume(std::string name) {
    if (!match(name)) throw "Expected " + name;
    return last(1);
}


/** returns next token if it's given type, otherwise throws an exception*/
Token Parser::consume(TokenType::Type type) {
    if (get(0).type != type) throw "Expected " + type;
    return tokens[position++];
}

/**returns next token if it's a WORD TokenType with a given name*/
bool Parser::match(std::string name) {
    if (get(0).type != TokenType::WORD || get(0).text != name) return false;
    position++;
    return true;
}

/**returns next token if it's the given type*/
bool Parser::match(TokenType::Type type) {
    if (get(0).type != type) return false;
    position++;
    return true;
}