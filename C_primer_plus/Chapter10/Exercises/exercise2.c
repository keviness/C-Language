/*** Chapter10: exercise2 ***/
#include <stdio.h>
#define SIZE 5

void copy_arr(double target[], double source[], int num);
void copy_ptr(double *target, double *source, int num);
void copy_ptrs(double *target, double *source, double*source1);
void show_arr(double *target, int num);

int main(void)
{
    double source[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[SIZE];
    double target2[SIZE];
    double target3[SIZE];

    printf("The source array: \n");
    show_arr(source, SIZE);

    //copy_arr();
    printf("target1 \n");
    copy_arr(target1, source, SIZE);
    show_arr(target1, SIZE);

    //copy_ptr()
    printf("target2 \n");
    copy_ptr(target2, source, SIZE);
    show_arr(target2, SIZE);

    //copy_ptrs()
    printf("target3 \n");
    copy_ptrs(target3, source, source+5);
    show_arr(target3, SIZE);

    return 0;
}

void show_arr(double *parr, int num)
{
    for (int i=0; i<SIZE; i++)
    {
        printf("%lf ", parr[i]);
    }
    putchar('\n');
}

void copy_arr(double target[], double source[], int num)
{
    for (int i=0; i<num; i++)
    {
        target[i] = source[i];
    }
}

void copy_ptr(double *target, double *source, int num)
{
    for (int i=0; i<num; i++)
    {
        target[i] = source[i];
    }
}

void copy_ptrs(double *target, double *source, double*target2)
{
    while (target != target2)
    {
        *target = *source;
        target++;
        source++;
    }
}