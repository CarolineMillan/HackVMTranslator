#include <iostream>
#include <exception>
#include "VMTranslator.h"

int main(int argc, char* argv[]) {

    if (argc != 3) {
        std::cerr << "Expected two arguments: [input_dir] [output_file]" << std::endl;
        return 2;
    }

    std::string input = argv[1];
    std::string output = argv[2];


    try {
        VMTranslator vm(input, output);
        vm.translate();
    } catch (const std::exception& err) {
        std::cerr << err.what() << std::endl;
        return 1;
    }

    return 0;
}
