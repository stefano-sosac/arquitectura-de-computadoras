nasm -f elf64 -o effectASM.o effectASM.asm
gcc -O0 preg.c effectASM.o -o preg -lm
./preg