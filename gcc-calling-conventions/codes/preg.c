/* This is a template. */
/* Author: Gabriel J. */
/* IEE240 - Organizacion y Arquitectura de Computadoras */
/* C-wrapper for assembly functions */

#include <stdio.h>
#include <stdlib.h>
#include "readimglib.h"

/* FIXME: Colocar los prototipos de sus funciones */


/* ---------------------------------------------- */

int main (int argc, char **argv){ 

    char filenameA[] = "./data/baboon.pgm";
    char filenameB[] = "./data/lena.pgm";

    int Nrows, Ncols;
    char *A, *B;

    // Extraer parametros de la imagen --> ambas imagenes tienen el mismo tamaño: no es necesario declarar Nrows y Ncols por imagen!
    read_headppm(filenameA, &Nrows, &Ncols,"P5");

    A = (char*) malloc(Nrows * Ncols * sizeof(char));
    B = (char*) malloc(Nrows * Ncols * sizeof(char));
    Cc = (char*) malloc(Nrows * Ncols * sizeof(char));
    Casm = (char*) malloc(Nrows * Ncols * sizeof(char));
    
    // Leo las imagenes
    read_ppm2uchar(filenameA, A, Nrows*Ncols, "P5");
    read_ppm2uchar(filenameB, B, Nrows*Ncols, "P5");

    /* FIXME: colocar sus funciones */
    imgSize = Nrows * Ncols;
    effectC(A,B,Cc,imgSize);

    // Guardar las imagenes --> Ejemplo:
    write_uchar2ppm("outputImg.pgm", B, Nrows, Ncols, "P5"); // Guardo en el archivo outputImg,pgm la imagen en A.

    free(A);
    free(B);
    free(Cc);
    free(Casm);
    /* FIXME: liberar memoria!! */

    return 0;
}