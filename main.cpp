#include <iostream>
#include "VMTranslator.h"

// argc is the arg count and argv is the arg values
int main(int argc, char* argv[]) {
    // basically just run the translation

    if (argc != 3) {
        // then the user hasn't provided both an input and an output file
        std::cerr << "Expected two arguments: [input_file] [output_file]" << std::endl;
        return 2;
    }

    std::string input = argv[1];
    std::string output = argv[2];

    VMTranslator vm(input, output);
    vm.translate();
}
