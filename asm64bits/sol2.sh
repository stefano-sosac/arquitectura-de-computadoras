nasm -f elf64 -g getchar.asm -o getchar.o
ld getchar.o -o getchar
./getchar

nasm -f elf64 -g copystring.asm -o copystring.o
ld copystring.o -o copystring
./copystring

nasm -f elf64 -g concatstring.asm -o concatstring.o
ld concatstring.o -o concatstring
./concatstring

nasm -f elf64 -g splitstring.asm -o splitstring.o
ld splitstring.o -o splitstring
./splitstring