nasm -f elf64 -o effectASM.o effectASM.asm
gcc preg.c effectASM.o -o preg -lm
./preg