#ifndef CODEWRITER_H
#define CODEWRITER_H

#include <string>
#include <fstream>
#include "command.h"


class CodeWriter {
public:

    // default constructor and deconstructor
    CodeWriter() = default;
    ~CodeWriter() = default;

    // contructor to open and output file stream for writing
    CodeWriter(std::string output);

    // decides which method to use to write to the output file
    void writeCommand(Command cmd);

    // writes to the output file the assembly code that implements the given arithmetical-logical command
    void writeArithmetic(Command cmd);

    // writes to the output file the assembly code that implements the given push or pop command
    void writePushPop(Command cmd);

    // closes output file
    void close();

    std::string current = "";

private:

    std::ofstream outFile;

};

#endif
