#ifndef VMTRANSLATOR_H
#define VMTRANSLATOR_H

#include <string>
#include "parser.h"
#include "codeWriter.h"

class VMTranslator {
public:

    // default constructor and deconstructor
    VMTranslator() = default;
    ~VMTranslator() = default;

    // constructor with filepaths
    VMTranslator(std::string input, std::string output);

    // run the translation
    void translate();
private:

    // keep a handle on the parser and codewriter
    Parser parser;
    CodeWriter codeWriter;
};

#endif
