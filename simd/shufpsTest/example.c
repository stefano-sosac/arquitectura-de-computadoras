#include <stdio.h>
#include <stdlib.h>

extern void testShufps(float *u, float *v);

int main(){
    //float u[4] = {1.0, 2.0, 3.0, 4.0};
    //float v[4] = {5.0, 6.0, 7.0, 8.0};

    float u[4] = {4.0, 3.0, 2.0, 1.0};
    float v[4] = {8.0, 7.0, 6.0, 5.0};

    int i;

    printf("\n u: ");
    for(i=3; i>=0; i--){printf("%.1f \t",u[i]);}
    printf("\n v: ");
    for(i=3; i>=0; i--){printf("%.1f \t",v[i]);}
    testShufps(u, v);
    printf("\n u: ");
    for(i=3; i>=0; i--){printf("%.1f \t",u[i]);}
    printf("\n");

    return 0;

}