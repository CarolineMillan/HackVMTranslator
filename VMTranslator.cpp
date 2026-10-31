#include "VMTranslator.h"

// TODO: change parser for a directory filepath
VMTranslator::VMTranslator(std::string input, std::string output): dir(input), codeWriter(output) {
    // create a parser and a codewriter to open input and output filestreams
    
    //parser = Parser(input);
    //codeWriter = CodeWriter(output);
}

void VMTranslator::translate() {
    // read and write the output line by line
    
    // TODO: this currently handles one file. put it in a loop to handle a whole directory, including bootstrap code at the beginning.
    //
    //
    // TODO:
    // - [X] add the bootstrap code
    // - [X] loop through everything in the directory filepath
    // - [X] create a parser for the file
    // - [X] update codeWriter.currentFileName for the variable names
    // - [X] run the current code for this file
    // - [ ] add in proper labels to the codewriter, claude told you where to do it
    //
    
    // bootstrap
    codeWriter.writeInit();

    for (auto const& path: std::filesystem::directory_iterator(dir)) {

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

            // TODO: [AI generated advice] Keep an eye on the last line of your input file. If it has no trailing newline and your parser mishandles that, the last command can get dropped. It didn’t here, but it’s worth knowing if a later test comes up one command short.
        }
    }

    // close file streams
    codeWriter.close();
};
