#ifndef UNTITLED_TOKENTYPE_H
#define UNTITLED_TOKENTYPE_H

namespace TokenType {
    enum Type {
        WORD,
        NUMBER,
        STRING,
        LABEL,
        LINE,
        EQUALS,
        OPERATOR,
        LEFT_PAREN,
        RIGHT_PAREN,
        _EOF
    };
}

#endif //UNTITLED_TOKENTYPE_H
