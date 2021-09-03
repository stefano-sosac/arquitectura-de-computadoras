
#include <stdio.h>
#include <stdlib.h>


int main (int argc, char **argv){

    printf("%d\n", argc);

    printf("%s\n", argv[0]);
    printf("%d\n", (int)atoi(argv[1]));

    return 0;
}

