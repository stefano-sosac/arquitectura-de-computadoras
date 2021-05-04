/* This is a template. */
/* Author: Gabriel J. */
/* IEE240 - Organizacion y Arquitectura de Computadoras */
/* C-wrapper for assembly functions */

#include <stdio.h>
#include <stdlib.h>
#include "readimglib.h"

/* FIXME: Colocar los prototipos de sus funciones */
void effectC(unsigned char *A, unsigned char *B, unsigned char *Cc, float alpha, int imgSize);
extern void effectASM(unsigned char *A, unsigned char *B, unsigned char *Cc, float alpha, int imgSize);
/* ---------------------------------------------- */

int main (int argc, char **argv){ 

    // Nombre de las imagenes a leer    
    char filenameA[] = "../data/baboon.pgm";
    char filenameB[] = "../data/lena.pgm";

    // Variables a utilizar en el programa principal
    int Nrows, Ncols, imgSize;
    char *A, *B, *Cc, *Casm;    // Punteros hacia las imagenes

    float alpha = 1.75; // FIXME >> este valor debe ingresarse por terminal. Usar argc, argv!
    struct timespec time1, time2; // Estructuras necesarias para medir tiempo de cada una de las funciones implementadas.

    // Extraer parametros de la imagen --> ambas imagenes tienen el mismo tamaño: no es necesario declarar Nrows y Ncols por imagen!
    // Esta funciones parte de la libreria readimglib.h --> solo reconoce imagenes pgm (P5).
    read_headppm(filenameA, &Nrows, &Ncols,"P5");

    // Reservo espacio de memoria para las imagenes de entrada A, B y las imagenes de salida Cc (funcion en C) y Casm (funcion ASM)
    A = (unsigned char*) malloc(Nrows * Ncols * sizeof(unsigned char));
    B = (unsigned char*) malloc(Nrows * Ncols * sizeof(unsigned char));
    Cc = (unsigned char*) malloc(Nrows * Ncols * sizeof(unsigned char));
    Casm = (unsigned char*) malloc(Nrows * Ncols * sizeof(unsigned char));
    
    // Leo las imagenes
    read_ppm2uchar(filenameA, A, Nrows*Ncols, "P5");
    read_ppm2uchar(filenameB, B, Nrows*Ncols, "P5");

    // FIXME >> para obtener mejores resultados, se debe ejecutar varias veces cada una de las funciones y calcular la mediana de los tiempos de ejecucion!
    // De esta forma evitamos considerar los tiempos iniciales de lectura de los datos de memoria. 

    imgSize = Nrows * Ncols;

    // Midiendo el tiempo de procesamiento para la funcion en C    
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);    // Inicio el contador de tiempo y guardo en la variable time1
    effectC(A,B,Cc,alpha,imgSize);  // Funcion implementada en C
    //for(int i=0; i<100; i++){printf("%u\t",Cc[i]);}
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);    // Detengo el contador de tiempo y guardo en la variable time2
    double tC = (double)((time2.tv_sec-time1.tv_sec) + (time2.tv_nsec-time1.tv_nsec)/1e9);  // Calculo el tiempo con la diferencia entre time2 y time1. 

    // Midiendo el tiempo de procesamiento para la funcion en ASM    
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
    effectASM(A,B,Casm,alpha,imgSize);
    //for(int i=0; i<100; i++){printf("%u\t", Casm[i]);}

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2); //toc
    double tASM = (double)((time2.tv_sec-time1.tv_sec) + (time2.tv_nsec-time1.tv_nsec)/1e9);
    
    // Imprimimos los tiempos de cada una de las funciones y el SU relativo de ASM respecto a C
    printf("El tiempo de ejecución en C es: %.5f us\n", tC*1e6);
    printf("El tiempo de ejecución en ASM es: %.5f us\n", tASM*1e6);
    printf("El speed-up es: %.2f \n", tC/tASM);


    // Guardar las imagenes --> Ejemplo:
    write_uchar2ppm("outputImgC.pgm", Cc, Nrows, Ncols, "P5"); // Guardo en el archivo outputImg,pgm la imagen en Cc.
    write_uchar2ppm("outputImgASM.pgm", Casm, Nrows, Ncols, "P5"); // Guardo en el archivo outputImg,pgm la imagen en Casm.

    // Liberar la memoria reservada por malloc! >> Importante no olvidar este paso!
    free(A);
    free(B);
    free(Cc);
    free(Casm);
    
    return 0;
}


// Funcion que implementa la operacion B + alpha(B-A), siendo A y B imagenes de entrada
void effectC(unsigned char *A, unsigned char *B, unsigned char *Cc, float alpha, int imgSize){
    unsigned char diff = 0;
    for(int i=0; i<imgSize; i++){
        diff = B[i]-A[i];
        Cc[i] = (unsigned char) ((float)B[i] + alpha*((float)diff));
        //printf("%d\t", B[i]-A[i]);
    }
}


