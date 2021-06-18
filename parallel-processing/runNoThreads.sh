rm nothreadtesttool
gcc -pthread -o threadtesttool threadtesttool.c
ln -s threadtesttool nothreadtesttool
# time ./nothreadtesttool

