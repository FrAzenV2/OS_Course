#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubble_sort(int array[], int arr_size)
{
    for (int i = 0 ; i < arr_size - 1; i++)
        for (int j = 0 ; j < arr_size - i - 1; j++)
          if (array[j] > array[j+1])
            swap(&array[j],&array[j+1]);

}

int main()
{
  int array[100], n;

  printf("Enter number of elements\n");
  scanf("%d", &n);

  printf("Enter %d integers\n", n);

  for (int i = 0; i < n; i++)
    scanf("%d", &array[i]);

  bubble_sort(array, n);

  printf("Sorted list in ascending order:\n");

  for (int i = 0; i < n; i++)
     printf("%d ", array[i]);

  return 0;
}
