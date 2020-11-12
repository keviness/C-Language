/*** review14: memcpy() ***/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10
void show_array(const double array[], int num);
int my_compare(const void *ptr1, const void *ptr2);

int main(void)
{
    double array1[SIZE] = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 9.0, 10.1, 12.3};
    double target[SIZE/2];

    puts("The array:");
    show_array(array1, SIZE);
    memcpy(target, array1+5, sizeof(double)*(SIZE/2));
    puts("The result of the target array:");
    show_array(target, SIZE/2);
    qsort(array1, SIZE, sizeof(double), my_compare);
    puts("The result of the array1 after quick sorted:");
    show_array(array1, SIZE);
} 

void show_array(const double array[], int num)
{
    int i;

    for (i=0; i<num; i++)
    {
        printf("%g ", array[i]);
    }
    putchar('\n');
}

/*
int my_compare(const void *ptr1, const void *ptr2)
{
    const double *a = (const double *)ptr1;
    const double *b = (const double *)ptr2;

    if (*a > *b)
    {
        return -1;
    }
    else if (*a < *b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
*/

int my_compare(const void *ptr1, const void *ptr2)
{
    const double *a = (const double *)ptr1;
    const double *b = (const double *)ptr2;

    return (*b - *a);
}