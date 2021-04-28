//gcc -S -masm=intel testCharFloat.c -o testCharFloat.s

#include <stdio.h>
#include <stdlib.h>


int main(){
    unsigned char A[10] = {0,1,2,3,4,5,6,7,8,9};
    unsigned char B[10] = {0,1,2,3,4,5,6,7,8,9};
    unsigned char C[10];

    float alpha = 1.75;

    for(int i=0; i<10; i++){
        C[i] = (unsigned char) ((float)B[i] + alpha*((float)(B[i]-A[i])));
    }

    return 0;
}