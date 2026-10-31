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

    // writes to the output file the assembly code that implements the given Label command
    void writeLabel(Command cmd);

    // writes to the output file the assembly code that implements the given Goto command
    void writeGoto(Command cmd);
    //
    // writes to the output file the assembly code that implements the given If-goto command
    void writeIf(Command cmd);

    // writes to the output file the assembly code that implements the given call command
    void writeCall(Command cmd);

    // writes to the output file the assembly code that implements the given return command
    void writeReturn(Command cmd);

    // writes to the output file the assembly code that implements the given function command
    void writeFunction(Command cmd);

    // writes to the output file the bootstrap code
    void writeInit();

    // closes output file
    void close();

    std::string current = "";

    std::string currentFileName = "";

private:

    std::ofstream outFile;

    int labelCounter = 0;

};

#endif
