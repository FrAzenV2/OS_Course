#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>


void * CustomRealloc(void * ptr, int new_size){
    if (ptr == NULL)
    {
        return malloc(new_size);
    }

    if (new_size == 0)
    {
        free(ptr);
        return ptr;
    }

    void *tmp = malloc(new_size);

    memcpy(tmp, ptr, sizeof(ptr));

    free(ptr);

    return tmp;
}

int main(){
	printf("Enter original array size: ");
	int n1=0;
	scanf("%d",&n1);

	int* array = (int*)malloc(sizeof(int) * n1);
	int i;
	for(i=0; i<n1; i++){
		array[i] = 100;
		printf("%d ", array[i]);
	}

	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);

	array = CustomRealloc(array, sizeof(int) * n2);

	for (size_t i = n1; i < n2; i++)
	{
		array[i] = 0;
	}

	for(i=0; i<n2;i++){
		printf("%d ", array[i]);
	}

	printf("\n");

    return 0;
}
