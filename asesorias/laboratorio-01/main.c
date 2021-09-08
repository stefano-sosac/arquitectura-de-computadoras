
#include <stdio.h>
#include <stdlib.h>

extern int globalvar();
extern int incglobalvar();
extern int ecoarg();
extern int suma2args(int a, int b);
extern int por5dir(int n);
extern int por5iter(int n);
extern int entre2(int n);

int main(int argc, char** argv){
    printf("%d\n", globalvar() );
    printf("%d\n", incglobalvar() );
    printf("%d\n", ecoarg( (int)atoi(argv[1]) ) );
    printf("%d\n", suma2args( (int)atoi(argv[1]), (int)atoi(argv[2])) );
    printf("%d\n", por5dir( (int)atoi(argv[1]) ) );
    printf("%d\n", por5iter( (int)atoi(argv[1]) ) );
    printf("%d\n", entre2( (int)atoi(argv[1]) ) );
    return 0;
}
