#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <string.h>

void swap_ints(int,int);


int main(){

    int a, b;
    printf("Type in 2 integers to swap them!\n");
    scanf("%d %d",&a,&b);
    swap_ints(&a, &b);
    printf("%i, %i",a, b);
    return 0;
}

swap_ints(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
