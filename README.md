# HackVMTranslator

Work in progress.

A VM Translator written in C++. Takes an input file of VM code and translates it into Hack Assembly. 
The back-end of the compiler in the course From NAND to Tetris, based on the Java Virtual Machine.

In Project 7 we handled:
- push/pop commands
- arithmetic-logical commands

In Project 8 we will extend it to include:
- function commands
- branching commands
- multiple input files

Currently passes the five tests from Project 7 of From NAND to Tetris:
- BasicTest
- SimpleAdd
- StackTest
- StaticTest
- PointerTest


and SimpleFunction from Project 8.

I am currently working on Project 8, handling multiple input files and the bootstrap code.


## Build & Run

Requires C++17. These commands have only been tested on macOS.

To build: ```g++ -std=c++17 *.cpp -o vmtranslator```

To run: ```./vmtranslator [input.vm] [output.asm]```

## TODO:
- [X] get rid of whitespace and comments in the input file before parsing it
- [ ] handle multiple input files
