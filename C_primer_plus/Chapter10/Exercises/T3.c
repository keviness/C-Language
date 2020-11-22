#include <stdio.h>
#define SIZE 5

void copy_arry(double ar[], const double br[], int r);
void copy_ptr(double *ar, const double *br, int r);
void copy_ptrs(double *ar, const double *br, double *end);
void show_arry(const double *ar, int r);

int main(void)
{
    double source[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[SIZE];
    double target2[SIZE];
    double target3[SIZE];

    copy_arry(target1, source, SIZE);
    copy_ptr(target2, source, SIZE);
    copy_ptrs(target3, source, source+SIZE);
    printf("The source arry:\n");
    show_arry(source, SIZE);
    printf("The target1 arry:\n");
    show_arry(target1, SIZE);
    printf("The target2 arry:\n");
    show_arry(target2, SIZE);
    printf("The target3 arry:\n");
    show_arry(target3, SIZE);

    return 0;
}

void show_arry(const double *arry, int r)
{
    int i;
    for (i=0; i<r; i++)
        printf("%2g ", *(arry+i));
    putchar('\n');
}

void copy_arry(double target[], const double source[], int r)
{
    int i;
    for (i=0; i<r; i++)
    {
        target[i] = source[i];
    }
}

void copy_ptr(double *target, const double *source, int r)
{
    int i;
    for (i=0; i<r; i++)
        *(target+i) = *(source+i);
}

void copy_ptrs(double *target, const double *source, double *end)
{
    int i;
    for (i=SIZE; *end != *source; i--,end--)
    {
        *(target+i) = *(end);
    }
}