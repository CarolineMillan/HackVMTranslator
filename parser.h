#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <fstream>
#include "command.h"

class Parser {
public:

    // default constructor
    Parser() = default;

    // constructor that opens an input file
    Parser(std::string input);

    // default deconstructer
    ~Parser() = default;

    // checks to see if there is another line
    bool hasMoreLines();

    // gets the next line and sets it to be the current line
    void advance();

    // returns the parsed command for the current line
    Command parseLine();

    // returns type of current command
    const std::string commandType();

    // returns first arg if it exists
    // TODO: should this be const? think
    std::string arg1();

    // returns second arg if it exists
    int arg2();

    // store the parsed input as tokens, unless you don't store the whole thing and just parse one line at a time
    //std::vector<Command> commands;

    // have a function here to parse the whole input, or do we parse one line at a time and send it to the code writer in the same loop in main? This means only looping through it once rather than twice which is probably faster
private:

    // store the current line, default to empty string
    std::string current = "";

    std::ifstream inFile;

};

#endif
