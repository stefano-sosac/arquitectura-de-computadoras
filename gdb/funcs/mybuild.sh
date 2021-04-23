nasm -g -f elf64 incdouble.asm -o incdouble.o
gcc -g incdouble.o funcs.c -o funcs -lm
