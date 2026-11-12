#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <fstream>
#include "command.h"

class Parser {
public:

    Parser() = default;
    Parser(std::string input);
    ~Parser() = default;

    // checks to see if there is another line
    bool hasMoreLines();

    // gets the next line and sets it to be the current line
    void advance();

    // returns the parsed command for the current line
    Command parseLine();

    // store the current line, default to empty string
    std::string current = "";

private:

    std::ifstream inFile;

};

#endif
