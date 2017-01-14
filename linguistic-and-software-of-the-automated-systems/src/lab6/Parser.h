#ifndef UNTITLED_PARSER_H
#define UNTITLED_PARSER_H


#include <vector>
#include <map>
#include "TokenType.h"
#include "Token.h"
#include "Value.h"
#include "Statement.h"
#include "StringValue.h"
#include "NumberValue.h"
#include "VariableExpression.h"
#include "OperatorExpression.h"
#include "AssignStatement.h"
#include "PrintStatement.h"
#include "InputStatement.h"
#include "GotoStatement.h"
#include "IfThenStatement.h"

class Parser {
private:
    int position;
    std::vector<Token> tokens;

    Token get(int offset);

    Token last(int offset);

    Token consume(std::string name);

    Token consume(TokenType::Type type);

    bool match(TokenType::Type type);

    bool match(TokenType::Type type1, TokenType::Type type2);

    bool match(std::string name);

    /** parses expressions to a single expression*/
    Expression *operation() {
        Expression *expression = atomic();

        while (match(TokenType::OPERATOR) ||
               match(TokenType::EQUALS)) {
            char operation = last(1).text[0];
            Expression *right = atomic();
            expression = new OperatorExpression(expression, right, operation);
        }

        return expression;
    }

    /** atomic operation*/
    Expression *atomic() {
        if (match(TokenType::WORD)) {
            return new VariableExpression(last(1).text);
        } else if (match(TokenType::NUMBER)) {
            return new NumberValue(std::stof(last(1).text));
        } else if (match(TokenType::STRING)) {
            return new StringValue(last(1).text);
        } else if (match(TokenType::LEFT_PAREN)) {
            Expression *expression = operation();
            consume(TokenType::RIGHT_PAREN);
            return expression;
        }
        throw "Couldn't parse";
    }

public:
    Parser(const std::vector<Token> &tokens);

    std::vector<Statement *> parse() {
        std::vector<Statement *> statements;

        while (true) {
            while (match(TokenType::LINE)); //skip empty lines

            if (match(TokenType::LABEL)) {
                labels[last(1).text] = (int) statements.size();
            } else if (match(TokenType::WORD, TokenType::EQUALS)) {
                std::string name = last(2).text;
                Expression *value = operation();
                statements.push_back(new AssignStatement(name, value));
            } else if (match("print")) {
                statements.push_back(new PrintStatement(operation()));
            } else if (match("input")) {
                statements.push_back(new InputStatement(consume(TokenType::WORD).text));
            } else if (match("goto")) {
                statements.push_back(new GotoStatement(consume(TokenType::WORD).text));
            } else if (match("if")) {
                Expression *condition = operation();
                consume("then");
                std::string label = consume(TokenType::WORD).text;
                statements.push_back(new IfThenStatement(condition, label));
            } else break;
        }

        return statements;
    }
};


#endif //UNTITLED_PARSER_H
