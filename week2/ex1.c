#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>



int main()
{
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;
    printf(" %i, %f, %d\n", a, b, c);
    printf("%lu, %lu, %lu\n", sizeof(a), sizeof(b),sizeof(c));
    return 0;
}
