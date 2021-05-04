// Recomendado ejecutar con:
// gcc -Wall -O0 mem-cache-eval.c -o mem-cache-eval
// getconf -a | grep CACHE

#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE (512*1024*1024)

int main()
{

    FILE *out_file = fopen("output3.txt", "w"); // write only 
    clock_t start, end;
    double cpu_time;
    int i = 0;
    int j = 0;
    /* MAX_SIZE array is too big for stack.This is an unfortunate rough edge of the way the stack works.
       It lives in a fixed-size buffer, set by the program executable's configuration according to the
       operating system, but its actual size is seldom checked against the available space. */
    /* int arr[MAX_SIZE]; */

    int *arr = (int*)malloc(MAX_SIZE * sizeof(int));
    //memset (arr,0,MAX_SIZE * sizeof(int));
    /* CPU clock ticks count start */

    for(int k = 0; k < 3; k++)
    {
        start = clock();

        /* Loop 1 */
        for (i = 0; i < MAX_SIZE; i++)
            arr[i] *= 3;

        /* CPU clock ticks count stop */
        end = clock();

        cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;

        printf("CPU time for loop 1 %.6f secs.\n", cpu_time);
    }

    for (j = 1 ; j <= 1024 ; j <<= 1)
    {
        /* CPU clock ticks count start */
        start = clock();

        /* Loop 2 */
        for (i = 0; i < MAX_SIZE; i += j)
            arr[i] *= 3;

        /* CPU clock ticks count stop */
        end = clock();

        cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;

        printf("CPU time for loop 2 (j = %d) %.6f secs.\n", j, cpu_time);
    }


    // loop intermedio --> Check caches L1, L2, L3
    for (j = 1; j <= 1572864; j += 4096) //desde 256 hasta 1024*1024*64
    {
        /* CPU clock ticks count start */
        start = clock();

        for (i = 0; i < j; i++)
            arr[i]++;
        /*
        for (long w = 0; w <= 64*1024*1024; w++)
        {
            long idx = (w*16) & (MAX_SIZE-1);
            start = clock();
            arr[idx]++;
            end = clock();
            cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;
            if ((w == (1<<4)) || (w == (1<<5)) || (w == (1<<6)) || (w == (1<<7)) || (w == (1<<8)) || (w == (1<<9)) || (w == (1<<10)) || (w == (1<<11)) || (w == (1<<12)) || (w == (1<<13)) || (w == (1<<14)) || (w == (1<<15)) || (w == (1<<16)) || (w == (1<<17)) || (w == (1<<18)) || (w == (1<<19)) || (w == (1<<20)) || (w == (1<<21)) || (w == (1<<22))){
                fprintf(out_file, "Digito = %ld %.8f secs.\n", w, cpu_time); // write to file 
            } 

        }*/
        /* CPU clock ticks count stop */
        end = clock();

        cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;

        fprintf(out_file, "%d, %.8f\n", j*4, cpu_time*1e3); // write to file 

        //printf("%ld\n", (ii*16));

        //printf("CPU time for loop 2.5 (Bytes = %ld) %.6f nsecs.\n", ii, cpu_time*1e9);
    }


    // Third loop, performing the same operations as loop 2,
    // but only touching 16KB of memory
    for (j = 1 ; j <= 1024 ; j <<= 1)
    {
        /* CPU clock ticks count start */
        start = clock();

        /* Loop 3 */
        for (i = 0; i < MAX_SIZE; i += j)
            arr[i & 0x1ffff] += 3;
            

        /* CPU clock ticks count stop */
        end = clock();

        //printf("%d, %d\n", 16384, 16384 & 0xfff);
        cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;

        printf("CPU time for loop 3 (j = %d) %.6f secs.\n", j, cpu_time);
    }

    for (j = 1 ; j <= 1024 ; j <<= 1)
    {
        /* CPU clock ticks count start */
        start = clock();

        /* Loop 3 */
        for (i = 0; i < MAX_SIZE; i += j)
            arr[i & 0x17ffff] += 3;
            

        /* CPU clock ticks count stop */
        end = clock();

        printf("%d, %d\n", i, i & 0x17ffff);
        cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;

        printf("CPU time for loop 3 (j = %d) %.6f secs.\n", j, cpu_time);
    }

    int steps = 256*1024*1024;
    int a[2];

    printf("\n");
    // Loop 1
    for (int k=0; k<3; k++){

    start = clock();
    for (i=0; i<steps; i++) { a[0]++; a[0]++; }
    end = clock();
    cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("CPU time for loop 1 %.6f usecs.\n", cpu_time*1e3);}

    // Loop 2
    start = clock();
    for (i=0; i<steps; i++) { a[0]++; a[1]++; }
    end = clock();
    cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("CPU time for loop 2 %.6f usecs.\n", cpu_time*1e3);


    free(arr);

    return 0;
}
