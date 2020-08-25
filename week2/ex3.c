#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <string.h>

void draw_triangle(int);

int main(int arg){

    draw_triangle(arg);
    return 0;
}

draw_triangle(int n){
    for(int i = 0;i<n;i++){
        int amount = 1+i*2;
        for(int j=0;j<n-amount/2;j++) printf(" ");
        for(int j=0;j<amount;j++) printf("*");
        for(int j=0;j<n-amount/2;j++) printf(" ");
        printf("\n");
    }
}

