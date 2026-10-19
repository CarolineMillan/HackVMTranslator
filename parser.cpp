#include "parser.h"
#include <iostream>
#include <fstream>

Parser::Parser(std::string input) {
    // constructor that opens an input file
    //
    inFile = std::ifstream(input);

    // if we can't open it for reading return an error
    if (!inFile) {
        throw std::runtime_error("couldn't open file for reading: " + input);
        return;
    }
}

bool Parser::hasMoreLines() {
    // checks to see if there is another line
    //
    return inFile.peek() != EOF;
}

void Parser::advance() {
    // gets the next line and sets it to the current line
    //
    // TODO: convince yourself that this advances iFile
    std::getline(inFile, current);
}

Command Parser::parseLine() {
    // turn current into a command
    //
    // TODO: remove comments and whitespace from input text
    Command cmd;

    // TODO: split this up into helper functions

    // get cmdType
    std::string cmdType = "";
    int i = 0;

    while (i < current.size() && current[i] != ' ') {
        cmdType += current[i];
        i++;
    }
std::cerr << "word: [" << cmdType << "]\n";

    // now match on the cmd
    // can't use a switch statement because this is a string not an integer/enumerated value
    if (cmdType == "push") {
        cmd.kind = Command::KIND::C_PUSH;
    } else if (cmdType == "pop") {
        cmd.kind = Command::KIND::C_POP;
    } else if (cmdType == "add") {
        cmd.kind = Command::KIND::C_ARITHMETIC;
        cmd.arith_op = Command::ARITH_OP::ADD;
    } else if (cmdType == "sub") {
        cmd.kind = Command::KIND::C_ARITHMETIC;
        cmd.arith_op = Command::ARITH_OP::SUB;
    } else if (cmdType == "neg") {
        cmd.kind = Command::KIND::C_ARITHMETIC;
        cmd.arith_op = Command::ARITH_OP::NEG;
    } else if (cmdType == "eq") {
        cmd.kind = Command::KIND::C_ARITHMETIC;
        cmd.arith_op = Command::ARITH_OP::EQ;
    } else if (cmdType == "gt") {
        cmd.kind = Command::KIND::C_ARITHMETIC;
        cmd.arith_op = Command::ARITH_OP::GT;
    } else if (cmdType == "lt") {
        cmd.kind = Command::KIND::C_ARITHMETIC;
        cmd.arith_op = Command::ARITH_OP::LT;
    } else if (cmdType == "and") {
        cmd.kind = Command::KIND::C_ARITHMETIC;
        cmd.arith_op = Command::ARITH_OP::AND;
    } else if (cmdType == "or") {
        cmd.kind = Command::KIND::C_ARITHMETIC;
        cmd.arith_op = Command::ARITH_OP::OR;
    } else if (cmdType == "not") {
        cmd.kind = Command::KIND::C_ARITHMETIC;
        cmd.arith_op = Command::ARITH_OP::NOT;
    } else if (cmdType == "label") {
        cmd.kind = Command::KIND::C_LABEL;
    } else if (cmdType == "goto") {
        cmd.kind = Command::KIND::C_GOTO;
    } else if (cmdType == "if-goto") {
        cmd.kind = Command::KIND::C_IF;
    } else if (cmdType == "function") {
        cmd.kind = Command::KIND::C_FUNCTION;
    } else if (cmdType == "call") {
        cmd.kind = Command::KIND::C_CALL;
    } else if (cmdType == "return") {
        cmd.kind = Command::KIND::C_RETURN;
    }

    // now onto arguments
    // incrmement i beyond the whitespace
    
    
    if (cmd.kind != Command::KIND::C_ARITHMETIC) {
        std::string segment = "";
        i++;

        while (i < current.size() && current[i] != ' ') {
            segment += current[i];
            i++;
        }

        if (segment == "constant") {
            cmd.segment = Command::SEGMENT::CONSTANT;
        } else if (segment == "local") {
            cmd.segment = Command::SEGMENT::LCL;
        } else if (segment == "argument") {
            cmd.segment = Command::SEGMENT::ARG;
        } else if (segment == "this") {
            cmd.segment = Command::SEGMENT::THIS;
        } else if (segment == "that") {
            cmd.segment = Command::SEGMENT::THAT;
        } else if (segment == "static") {
            cmd.segment = Command::SEGMENT::STATIC;
        } else if (segment == "temp") {
            cmd.segment = Command::SEGMENT::TEMP;
        } else if (segment == "pointer") {
            cmd.segment = Command::SEGMENT::PTR;
        }
    }

    // if we have one of the following commands, look for the second argumnet
    if (cmd.kind == Command::KIND::C_PUSH || cmd.kind == Command::KIND::C_POP || cmd.kind == Command::KIND::C_FUNCTION || cmd.kind == Command::KIND::C_CALL) {
        std::string arg2 = "";
        i++;

        while (i < current.size() && current[i] != ' ') {
            arg2 += current[i];
            i++;
        }
        cmd.arg2 = arg2;
    }

    return cmd;
}

const std::string Parser::commandType() {
    // returns command type from the line
    return "";
}

std::string Parser::arg1() {
    // returns first argument in the line
    return "";
}


int Parser::arg2() {
    // returns second argument in the line
    return 0;
}
