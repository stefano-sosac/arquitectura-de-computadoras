#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){

	int cont = 0;

	if (argc == 1) {
		cont = 2;
	}
	else {
		cont = atoi(argv[1]);
	}

	while (cont > 0) {
		printf("hello world\n");
		cont--;
	}

	return 0;
}
