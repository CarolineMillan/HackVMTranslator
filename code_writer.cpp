#include "codeWriter.h"
#include "command.h"
#include <iostream>
#include <fstream>

CodeWriter::CodeWriter(std::string output) {
    // open an output filestream for writing
    outFile = std::ofstream(output);

    if (!outFile) {
        std::cerr << "Error: Couldn't open output file." << std::endl;
        return;
    }
}

void CodeWriter::writeCommand(Command cmd) {
    // decides which method to use to write the output file
    switch (cmd.kind) {
        case Command::KIND::C_ARITHMETIC:
            // call writeArithmetic and return
            writeArithmetic(cmd);
            return;
        case Command::KIND::C_PUSH:
        case Command::KIND::C_POP:
            // call writePushPop and return
            // TODO: where to get segment and index from? are they the arguments in command?
            writePushPop(cmd, "", 0);
            return;
        case Command::KIND::C_LABEL:
        case Command::KIND::C_GOTO:
        case Command::KIND::C_IF:
        case Command::KIND::C_FUNCTION:
        case Command::KIND::C_CALL:
        case Command::KIND::C_RETURN:
        default:
        return;
    }
}

void CodeWriter::writeArithmetic(Command cmd) {
    // writes to the output file the assembly code that implements the given arithmeical-logical command
}

void CodeWriter::writePushPop(Command cmd, std::string segment, int index) {
    // writes to the output file the assembly code that implements the given push or pop command
}

void CodeWriter::close() {
    // closes output file
    // this happens automagically when the file goes out of scope
}
