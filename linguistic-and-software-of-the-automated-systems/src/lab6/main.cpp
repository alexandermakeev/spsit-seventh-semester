#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include "Tokenizer.h"
#include "Parser.h"

int main() {

    Tokenizer tokenizer;

    std::ifstream in("/home/alexander/ClionProjects/untitled/src/lab6/test.txt");

    std::string content;
    std::string line;
    while (getline(in, line)) {
        content = content + line + "\n";
    }

    std::vector<Token> tokens = tokenizer.tokenize(content);

    Parser parser(tokens);
    std::vector<Statement*> statements = parser.parse();


    currentStatement = 0;
    while (currentStatement < statements.size()) {
        int thisStatement = currentStatement;
        currentStatement++;
        statements[thisStatement]->execute();
    }

    return 0;
}