#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>

#define SIZE 10

int main(){

    struct rusage rusg;

    for (size_t i = 0; i < 10; i++)
    {
        memset(malloc(SIZE * 1024 * 1024), '0', SIZE * 1024 * 1024);

        if(getrusage(RUSAGE_SELF, &rusg) == 0){
            printf("Used:%ld KB\n", rusg.ru_maxrss);
        } else {
            printf("Error in getrusage() occured\n");
        }
        
        sleep(1);
    }

    return 0;
}