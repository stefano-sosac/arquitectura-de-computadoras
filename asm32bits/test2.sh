nasm -f elf32 -o asmMedia32.o asmMedia32.asm
nasm -f elf32 -o asmMedia32womin.o asmMedia32womin.asm
gcc -m32 -march=i686 laboratorio0-p2.c asmMedia32.o asmMedia32womin.o -o labp2
./labp2 9 10 15 2