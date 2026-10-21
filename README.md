# HackVMTranslator

Work in progress.

A VM Translator written in C++. Takes an input file of VM code and translates it into Hack Assembly. This will be part of the Compiler project that I will build later on in the course.

In Project 7 we handled:
- push/pop commands
- arithmetic-logical commands

In Project 8 we will extend it to include:
- function commands
- branching commands

Currently passes the five tests from Project 7 of From NAND to Tetris:
- BasicTest
- SimpleAdd
- StackTest
- StaticTest
- PointerTest
(with comments and whitespace removed)

I am currently working on Project 8.


## Build & Run

Requires C++17. These commands have only been tested on macOS.

To build: ```g++ -std=c++17 *.cpp -o vmtranslator```

To run: ```./vmtranslator [input.vm] [output.asm]```

## TODO:
- [ ] get rid of whitespace and comments in the input file before parsing it
