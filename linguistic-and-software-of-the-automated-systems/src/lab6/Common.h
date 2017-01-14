#ifndef UNTITLED_COMMON_H
#define UNTITLED_COMMON_H

#include <string>
#include <map>
#include "Value.h"

static std::map<std::string, Value*> variables;
static std::map<std::string, int> labels;
static int currentStatement;

#endif //UNTITLED_COMMON_H
