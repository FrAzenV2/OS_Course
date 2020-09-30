#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    printf("Enter N:\n");
    scanf("%d", &N);

    int* arrayn = (int*)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++)
    {
        arrayn[i] = i;
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d ", arrayn[i]);
    }

    printf("\n");

    free(arrayn);

    return 0;
}
