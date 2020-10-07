#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SIZE 10

int main(){

    for (int i = 0; i < 10; i++)
    {
        memset(malloc(SIZE * 1024 * 1024), '0', SIZE * 1024 * 1024);
        sleep(1);
    }

    return 0;
}