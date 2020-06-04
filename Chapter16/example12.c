/*** example16.17: qsort() ***/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10
int compare(const void *ptr1, const void *ptr2);
void fill_array(double arr[], int num);
void show_array(double arr[], int num);

int main(void)
{
    double arr[SIZE];
    fill_array(arr, SIZE);
    puts("The elements of the array:");
    show_array(arr, SIZE);
    qsort(arr, SIZE, sizeof(double), compare);
    puts("The result after quick sorted:");
    show_array(arr, SIZE);
}

void fill_array(double arr[], int num)
{
    for (int i=0; i<num; i++)
    {
        arr[i] = (double)rand()/((double)rand() + 0.1);
    }
}

void show_array(double arr[], int num)
{
    for (int i=0; i<num; i++)
    {
        printf("%g ", arr[i]);
    }
    putchar('\n');
}

int compare(const void *ptr1, const void *ptr2)
{
    const double *ar1 = (const double *)ptr1;
    const double *ar2 = (const double *)ptr2;

    if (*ar1 > *ar2)
    {
        return 1;
    }
    else if (*ar1 < *ar2)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}