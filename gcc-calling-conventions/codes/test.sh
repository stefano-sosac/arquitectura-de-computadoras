#nasm -f elf64 -o effectASM.o ./codes/effectASM.asm
#gcc preg.c effectASM.o effectSIMD.o -o lab4 -lm

gcc preg.c -o preg -lm
./preg