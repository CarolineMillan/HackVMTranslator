#include "VMTranslator.h"

VMTranslator::VMTranslator(std::string input, std::string output) {
    // create a parser and a codewriter to open input and output filestreams
    
    parser = Parser(input);
    codeWriter = CodeWriter(output);
}

void VMTranslator::translate() {
    // read and write the output line by line
    
    while (parser.hasMoreLines()) {

        // get the line
        parser.advance();
        
        // read the line
        Command cmd = parser.parseLine();

        // write the line
        codeWriter.writeCommand(cmd);
    }

    // close file streams
    codeWriter.close();
};
