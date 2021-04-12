/* This is a template. Do not modify! */
/* Author: Gabriel J. */
/* IEE240 - Organizacion y Arquitectura de Computadoras */
/* C-wrapper for assembly functions */

#include <stdio.h>
#include <stdlib.h>

extern int asmMedia32(int *a, int N);
// calling conventions --> rdi, rsi, rdx, rcx, r8, r9
// int *a --> pointer to array, int r --> pointer to result, int N--> size of array

int main (int argc, char **argv){
    int i, N, r1, r2;
    int *arr;

    N = argc - 1; 
    arr = (int*) malloc(N*sizeof(int));
    //printf("%d\n", sizeof(arr));
    
    if (argc < 2){
        N = 3;
        for (i = 0; i < N; i++) arr[i] = i;
    } else{
        for (i = 1; i < argc; i++) arr[i-1] = (int)atoi(argv[i]);
    }

    r1 = asmMedia32(arr, N);
    for (i = 0; i < N; i++) printf("%d\t",arr[i]);
    printf("\nLa media del arreglo es: %d \n", r1);

    free(arr);

    return 0;
}

