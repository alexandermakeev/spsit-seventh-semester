#ifndef UNTITLED_GOTOSTATEMENT_H
#define UNTITLED_GOTOSTATEMENT_H


#include <string>
#include "Statement.h"
#include "Common.h"

class GotoStatement : public Statement {
    const std::string label;
public:
    GotoStatement(const std::string &label) : label(label) {}

    virtual void execute() override {
        if (labels.count(label)) {
            currentStatement = labels[label];
        }
    }
};


#endif //UNTITLED_GOTOSTATEMENT_H
