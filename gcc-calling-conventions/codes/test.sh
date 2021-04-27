nasm -f elf64 -o effectASM.o ./codes/effectASM.asm
nasm -f elf64 -o effectSIMD.o ./codes/effectSIMD.asm
gcc ./codes/preg.c effectASM.o effectSIMD.o -o lab4 -lm

./lab4 1.75