#include "VMTranslator.h"

VMTranslator::VMTranslator(std::string input, std::string output): dir(input), codeWriter(output) {}

void VMTranslator::translate() {
    // read and write the output line by line
    
    // bootstrap
    codeWriter.writeInit();

    for (auto const& path: std::filesystem::directory_iterator(dir)) {

        if (path.path().extension() == ".vm") {
            // create a parser for the new file
            Parser parser(path.path().string());

            // add the file name to the codeWriter to be used for variable naming
            codeWriter.currentFileName = path.path().stem();
        
            while (parser.hasMoreLines()) {

                // get the line
                parser.advance();
                
                // read the line
                Command cmd = parser.parseLine();

                // save the current line
                codeWriter.current = parser.current;

                // write the line
                codeWriter.writeCommand(cmd);
            }
        }
    }
};
