# HackVMTranslator

A VM Translator written in C++. Takes an input file of VM code and translates it into Hack Assembly. 
The back-end of the compiler in the course From NAND to Tetris, based on the Java Virtual Machine.

Supports:
- push/pop commands
- arithmetic-logical commands
- function commands
- branching commands
- multiple input files

It has passed the tests from Projects 7 and 8 of From NAND to Tetris:
- BasicTest
- SimpleAdd
- StackTest
- StaticTest
- PointerTest
- BasicLoop
- FibonacciSeries
- SimpleFunction
- NestedCall
- FibonacciElement
- StaticsTest

The bootstrap code was added for the last three tests, therefore the previous tests can no longer be run successfully on this project because it assumes that a `Sys.init` function exists. This was done intentionally by the authors of the course to allow you to unit test your code as you worked through the project and they stated this in the book. The tests passed in the order they were supposed to, and the .asm files are in the output folder. 

The tests that currently pass with the bootstrap code are: `NestedCall`, `FibonacciElement` and `StaticsTest`.

## Build & Run

Requires C++17. These commands have only been tested on macOS.

The input must be a directory of `.vm` files. The output must be the name of the output file, and it must include the `.asm` extension. If you would like to output to a directory, you must create the directory first.

To build: ```g++ -std=c++17 *.cpp -o vmtranslator```

To run: ```./vmtranslator [input_dir] [output_filename.asm]```

For example: ``` ./vmtranslator input/StaticsTest output/StaticsTest.asm ```
