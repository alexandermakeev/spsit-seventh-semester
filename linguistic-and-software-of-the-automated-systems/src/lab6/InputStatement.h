#ifndef UNTITLED_INPUTSTATEMENT_H
#define UNTITLED_INPUTSTATEMENT_H


#include <string>
#include <iostream>
#include <stdexcept>
#include "Statement.h"
#include "StringValue.h"
#include "NumberValue.h"
#include "Common.h"

class InputStatement : public Statement {
    const std::string name;
public:
    InputStatement(std::string name) : name(name) {}

    virtual void execute() override {
        std::string line;
        std::getline(std::cin, line);
        try {
            float value = std::stof(line);
            variables[name] = new NumberValue(value);
        } catch(std::invalid_argument &e) {
            variables[name] = new StringValue(line);
        }
    }
};


#endif //UNTITLED_INPUTSTATEMENT_H
