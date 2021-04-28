/* This is a template. */
/* Author: Gabriel J. */
/* IEE240 - Organizacion y Arquitectura de Computadoras */
/* C-wrapper for assembly functions */

#include <stdio.h>
#include <stdlib.h>
#include "readimglib.h"

/* FIXME: Colocar los prototipos de sus funciones */
void effectC(unsigned char *A, unsigned char *B, unsigned char *Cc, float alpha, int imgSize);
void effectASM(unsigned char *A, unsigned char *B, unsigned char *Cc, float alpha, int imgSize);
/* ---------------------------------------------- */

int main (int argc, char **argv){ 

    char filenameA[] = "../data/baboon.pgm";
    char filenameB[] = "../data/lena.pgm";

    int Nrows, Ncols, imgSize;
    char *A, *B, *Cc;

    float alpha = 1.75;
    struct timespec time1, time2;

    // Extraer parametros de la imagen --> ambas imagenes tienen el mismo tamaño: no es necesario declarar Nrows y Ncols por imagen!
    read_headppm(filenameA, &Nrows, &Ncols,"P5");

    A = (unsigned char*) malloc(Nrows * Ncols * sizeof(unsigned char));
    B = (unsigned char*) malloc(Nrows * Ncols * sizeof(unsigned char));
    Cc = (unsigned char*) malloc(Nrows * Ncols * sizeof(unsigned char));
    //Casm = (unsigned char*) malloc(Nrows * Ncols * sizeof(unsigned char));
    
    // Leo las imagenes
    read_ppm2uchar(filenameA, A, Nrows*Ncols, "P5");
    read_ppm2uchar(filenameB, B, Nrows*Ncols, "P5");

    /* FIXME: colocar sus funciones */
    imgSize = Nrows * Ncols;
    for(int i=0; i<imgSize; i++){
        Cc[i] = (unsigned char) ((float)B[i] + alpha*((float)(B[i]-A[i])));
    }
    
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
    effectC(A,B,Cc,imgSize);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2); //toc
    double tC = (double)((time2.tv_sec-time1.tv_sec) + (time2.tv_nsec-time1.tv_nsec)/1e9);

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
    effectASM(A,B,Cc,imgSize);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2); //toc
    double tC = (double)((time2.tv_sec-time1.tv_sec) + (time2.tv_nsec-time1.tv_nsec)/1e9);
    
    // Guardar las imagenes --> Ejemplo:
    write_uchar2ppm("outputImg.pgm", Cc, Nrows, Ncols, "P5"); // Guardo en el archivo outputImg,pgm la imagen en A.

    free(A);
    free(B);
    free(Cc);
    //free(Casm);
    /* FIXME: liberar memoria!! */

    return 0;
}


void effectC(unsigned char *A, unsigned char *B, unsigned char *Cc, float alpha, int imgSize){
    for(int i=0; i<imgSize; i++){
        Cc[i] = (unsigned char) ((float)B[i] + alpha*((float)(B[i]-A[i])));
    }
}
