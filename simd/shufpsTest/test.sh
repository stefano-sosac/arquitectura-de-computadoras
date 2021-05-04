nasm -g -f elf64 testShufps.asm  -o testShufps.o
gcc  -g testShufps.o example.c -o example  -lm
./example

