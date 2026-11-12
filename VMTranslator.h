#ifndef VMTRANSLATOR_H
#define VMTRANSLATOR_H

#include <string>
#include <filesystem>
#include "parser.h"
#include "codeWriter.h"

class VMTranslator {
public:

    VMTranslator() = default;
    VMTranslator(std::string input, std::string output);
    ~VMTranslator() = default;

    void translate();
private:

    std::filesystem::path dir;
    CodeWriter codeWriter;
};

#endif
