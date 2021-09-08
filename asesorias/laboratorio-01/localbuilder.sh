nasm -g -f elf32 globalvar.asm -o globalvar.o
nasm -g -f elf32 incglobalvar.asm -o incglobalvar.o
nasm -g -f elf32 ecoarg.asm -o ecoarg.o
nasm -g -f elf32 suma2args.asm -o suma2args.o
nasm -g -f elf32 por5dir.asm -o por5dir.o
nasm -g -f elf32 por5iter.asm -o por5iter.o
nasm -g -f elf32 entre2.asm -o entre2.o
gcc -m32 entre2.o por5iter.o por5dir.o suma2args.o ecoarg.o incglobalvar.o globalvar.o main.c -o main
./main 1 2 3
