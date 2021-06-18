# Check threads max per process
# cat /proc/sys/kernel/threads-max
gcc -pthread -o threadtesttool threadtesttool.c
# time ./threadtesttool 4 3000000

