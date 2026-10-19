#ifndef COMMAND_H
#define COMMAND_H

#include <string>

struct Command {

    // create an enum to use for the command type
    // called it kind to avoid confusion
    enum class KIND {C_ARITHMETIC, C_PUSH, C_POP, C_LABEL, C_GOTO, C_IF, C_FUNCTION, C_CALL, C_RETURN};
    
    // set default to a label
    KIND kind = KIND::C_LABEL;

    // create an enum to use for the segment type
    enum class SEGMENT {CONSTANT, LCL, ARG, THIS, THAT, STATIC, TEMP, PTR};
    
    // set default to a constant
    SEGMENT segment = SEGMENT::CONSTANT;

    // create an enum to use for the segment type
    enum class ARITH_OP {ADD, SUB, NEG, EQ, GT, LT, AND, OR, NOT};
    
    // set default to EQ
    ARITH_OP arith_op = ARITH_OP::EQ;

    // store arg1 if it exists
    std::string arg1 = "";

    // store arg2 if it exists
    std::string arg2 = "";

    // default constructor and deconstructor
    Command() = default;
    ~Command() = default;

    // other constructor that takes inputs
    Command(KIND kind): kind(kind) {};
    Command(KIND kind, std::string arg1): kind(kind), arg1(arg1) {};
    Command(KIND kind, std::string arg1, std::string arg2): kind(kind), arg1(arg1), arg2(arg2) {};

    // getters and setters? then you make the other stuff private, can you make struct stuff private or is that just a class thing?
};

#endif
