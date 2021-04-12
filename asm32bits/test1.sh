nasm -f elf32 -o asmMedia32.o asmMedia32.asm
gcc -m32 -march=i686 laboratorio0-p1.c asmMedia32.o -o labp1
./labp1 9 10 15 2