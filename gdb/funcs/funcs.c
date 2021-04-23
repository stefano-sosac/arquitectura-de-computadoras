// la funcion main llama a genvector
// la funcion genvector llama a incdouble

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

extern double incdouble(double d);

void genvector(double *v, int size){
	for(int i = 0; i < size; i++){
		v[i] = incdouble(v[i]);
	}
}


int main(int argc, char** argv){

	int size = 0;
	if (argc != 2) {
		printf("usage: ./funcs <numero_entero>\n");
	}
	else {
		size = atoi(argv[1]);
	}	

	double *v;
	v = (double *)malloc(sizeof(double)*size);

	genvector(v,size);	

	return 0;
}
