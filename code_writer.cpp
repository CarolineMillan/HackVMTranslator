#include "codeWriter.h"
#include "command.h"
#include "constants.h"
#include <iostream>
#include <fstream>

CodeWriter::CodeWriter(std::string output) : outFile(output) {
    // open an output filestream for writing
    //outFile = std::ofstream(output);

    if (!outFile) {
        std::cerr << "Error: Couldn't open output file." << std::endl;
        return;
    }
}

void CodeWriter::writeCommand(Command cmd) {
    std::cerr << "1\n";
    std::cerr << "kind: " << static_cast<int>(cmd.kind) << "\n";
    // decides which method to use to write the output file
    switch (cmd.kind) {
        case Command::KIND::C_ARITHMETIC:
            // call writeArithmetic and return
            writeArithmetic(cmd);
            return;
        case Command::KIND::C_PUSH:
        case Command::KIND::C_POP:
            // call writePushPop and return
            writePushPop(cmd);
            return;
        case Command::KIND::C_LABEL:
            // call writeLabel and return
            writeLabel(cmd);
            return;
        case Command::KIND::C_GOTO:
            // call writeGOTO and return
            writeGoto(cmd);
            return;
        case Command::KIND::C_IF:
            // call writeIf and return
            writeIf(cmd);
            return;
        case Command::KIND::C_FUNCTION:
        case Command::KIND::C_CALL:
        case Command::KIND::C_RETURN:
        default:
        return;
    }
}

void CodeWriter::writeArithmetic(Command cmd) {
    std::cerr << "writing\n";
    // writes to the output file the assembly code that implements the given arithmeical-logical command
    //
    std::string str = "// " + current + "\n";

    std::string label = std::to_string(labelCounter);


    switch(cmd.arith_op) {
        case Command::ARITH_OP::ADD:
            str += "@SP\nAM=M-1\nD=M\nA=A-1\nM=D+M\n";
            break;
        case Command::ARITH_OP::SUB:
            str += "@SP\nAM=M-1\nD=M\nA=A-1\nM=M-D\n";
            break;
        case Command::ARITH_OP::NEG:
            str += "@SP\nA=M-1\nM=-M\n";
            break;
        case Command::ARITH_OP::EQ:
            str += "@SP\nAM=M-1\nD=M\nA=A-1\nD=M-D\n@TRUE_" + label + "\nD;JEQ\nD=0\n@END_" + label + "\n0;JMP\n(TRUE_" + label + ")\nD=-1\n(END_" + label + ")\n@SP\nA=M-1\nM=D\n";
            labelCounter++;
            break;
        case Command::ARITH_OP::GT:
            str += "@SP\nAM=M-1\nD=M\nA=A-1\nD=M-D\n@TRUE_" + label + "\nD;JGT\nD=0\n@END_" + label + "\n0;JMP\n(TRUE_" + label + ")\nD=-1\n(END_" + label + ")\n@SP\nA=M-1\nM=D\n";
            labelCounter++;
            break;
        case Command::ARITH_OP::LT:
            str += "@SP\nAM=M-1\nD=M\nA=A-1\nD=M-D\n@TRUE_" + label + "\nD;JLT\nD=0\n@END_" + label + "\n0;JMP\n(TRUE_" + label + ")\nD=-1\n(END_" + label + ")\n@SP\nA=M-1\nM=D\n";
            labelCounter++;
            break;
        case Command::ARITH_OP::AND:
            str += "@SP\nAM=M-1\nD=M\nA=A-1\nM=D&M\n";
            break;
        case Command::ARITH_OP::OR:
            str += "@SP\nAM=M-1\nD=M\nA=A-1\nM=D|M\n";
            break;
        case Command::ARITH_OP::NOT:
            str += "@SP\nA=M-1\nM=!M\n";
            break;
        default:
            break;
    }

    outFile << str;

}

void CodeWriter::writePushPop(Command cmd) {
    std::cerr << "writing\n";
    // writes to the output file the assembly code that implements the given push or pop command

    // address of the non-stack bit we need to look at, but not even just address, more the bit of the string that is dependent on segment not kind of command
    std::string sgmt_str = "";
    std::string full_str = "// " + current + "\n";

    // find sgmt_str
    switch(cmd.segment) {
        case Command::SEGMENT::CONSTANT:
            sgmt_str = "@" + cmd.arg2 + "\n";
            break;
        case Command::SEGMENT::LCL:
            sgmt_str = "@" + cmd.arg2 + "\nD=A\n@LCL\nD=D+M\n";
            break;
        case Command::SEGMENT::ARG:
            sgmt_str = "@" + cmd.arg2 + "\nD=A\n@ARG\nD=D+M\n";
            break;
        case Command::SEGMENT::THIS:
            sgmt_str = "@" + cmd.arg2 + "\nD=A\n@THIS\nD=D+M\n";
            break;
        case Command::SEGMENT::THAT:
            sgmt_str = "@" + cmd.arg2 + "\nD=A\n@THAT\nD=D+M\n";
            break;
        case Command::SEGMENT::STATIC:
            sgmt_str = "@" + std::to_string(constants::STATIC_ADDR + stoi(cmd.arg2)) + "\nD=A\n";
            break;
        case Command::SEGMENT::TEMP:
            sgmt_str = "@" + std::to_string(constants::TEMP_ADDR + stoi(cmd.arg2)) + "\nD=A\n";
            break;
        case Command::SEGMENT::PTR:
            if (cmd.arg2 == "0") {
                sgmt_str = "@THIS\nD=A\n";
            } else if (cmd.arg2 == "1") {
                sgmt_str = "@THAT\nD=A\n";
            } else {
                // TODO: error, ptr args can only be 0 or 1
            }
            break;
        default:
            break;
    }

    switch(cmd.kind) {
        case Command::KIND::C_PUSH:
            if (cmd.segment == Command::SEGMENT::CONSTANT) {
                full_str += sgmt_str + "D=A\n";
            } else {
                full_str += sgmt_str + "A=D\nD=M\n";
            }
            full_str += "@SP\nA=M\nM=D\n@SP\nM=M+1\n";
            break;
        case Command::KIND::C_POP:
            full_str += sgmt_str + "@R13\nM=D\n@SP\nM=M-1\nA=M\nD=M\n@R13\nA=M\nM=D\n";
            break;
        default:
            break;
    }

    // write full_str to the file
    outFile << full_str;

    
}

void CodeWriter::writeLabel(Command cmd) {

    std::string full_str = "// " + current + "\n";

    full_str += "(" + cmd.arg1 + ")\n";

    // write full_str to the file
    outFile << full_str;
}

void CodeWriter::writeGoto(Command cmd) {

    std::string full_str = "// " + current + "\n";

    full_str += "@" + cmd.arg1 + "\n0;JMP\n";

    // write full_str to the file
    outFile << full_str;
}

void CodeWriter::writeIf(Command cmd) {

    std::string full_str = "// " + current + "\n";

    full_str += "@SP\nAM=M-1\nD=M\n@" + cmd.arg1 + "\nD;JNE\n";

    // write full_str to the file
    outFile << full_str;
}
void CodeWriter::close() {
    // closes output file
    // this happens automagically when the file goes out of scope
}
