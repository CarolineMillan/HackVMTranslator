#include "VMTranslator.h"

VMTranslator::VMTranslator(std::string input, std::string output): parser(input), codeWriter(output) {
    // create a parser and a codewriter to open input and output filestreams
    
    //parser = Parser(input);
    //codeWriter = CodeWriter(output);
}

void VMTranslator::translate() {
    // read and write the output line by line
    
    while (parser.hasMoreLines()) {


        // get the line
        parser.advance();
        
        // read the line
        Command cmd = parser.parseLine();

        // save the current line
        codeWriter.current = parser.current;

        // write the line
        codeWriter.writeCommand(cmd);

        // TODO: [AI generated advice] Keep an eye on the last line of your input file. If it has no trailing newline and your parser mishandles that, the last command can get dropped. It didn’t here, but it’s worth knowing if a later test comes up one command short.
    }

    // close file streams
    codeWriter.close();
};
