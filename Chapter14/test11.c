/*** Chapter14: test11 ***/
#include <stdio.h>
#include <string.h>
#include <math.h>
#define SIZE 100
#define PFUCT 4

void print_array(double *arr);
double get_opposite(double num);
double get_double(double num);
void transform(double *arr1, double *arr2, int num, double(*pfunc)(double));

int main(void)
{
    double array1[SIZE];
    double target[SIZE];
    double (*pfunc[PFUCT])(double num) = {sin, sqrt, get_double, get_opposite};
    puts("Generate the list:");
    for (int i=0; i<SIZE; i++)
    {
        array1[i] = i;
    }
    puts("The initial array:");
    print_array(array1);

    for (int i=0; i<PFUCT; i++)
    {
        transform(target, array1, SIZE, pfunc[i]);
        puts("The result array:");
        print_array(target);
    }
    puts("The done~");

    return 0;
}

double get_opposite(double num)
{
    return (-1 * num);
}

double get_double(double num)
{
    return (2 * num);
}

void print_array(double *arr)
{
    for (int i=0; i<SIZE; i++)
    {
        printf("%.3f ", arr[i]);
        if (i%10 == 9)
        {
            putchar('\n');
        }
    }
    putchar('\n');
}

void transform(double *target, double *arr, int num, double(*pfct)(double num))
{
    for (int i=0; i<num; i++)
    {
        target[i] = pfct(arr[i]);
    }
}