#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <string.h>

int main(){

    char str[50];
    printf("Write some string to get it inversed!\n");
    scanf("%s", str);
    for(int i=strlen(str);i>-1;i--)
        printf("%c",str[i]);
    return 0;
}
