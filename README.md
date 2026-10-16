# HackVMTranslator

g++ -std=c++17 -g -fsanitize=address *.cpp -o vmtranslator
./vmtranslator "input/SimpleAdd.vm" "output/SimpleAdd.asm"
