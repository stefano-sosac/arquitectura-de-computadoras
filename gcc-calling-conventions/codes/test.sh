nasm -g -f elf64 -o effectASM.o effectASM.asm
gcc -g -O0 preg.c effectASM.o -o preg -lm
./preg