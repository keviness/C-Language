/***example16.20: <string.h>:memcpy() memmove()***/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10
//_Static_assert(sizeof(double) == sizeof(int), "double not twice int");

void show_int_array(const int ptr[], int num);
void show_double_array(const double arr[], int num);

int main(void)
{
    int target[SIZE];
    int target1[SIZE];
    int target2[SIZE];
    double target3[SIZE];
    double target4[SIZE];
    int values[SIZE] = {1, 3, 4, 5, 2, 3, 4, 6, 12, 34};
    double curious[SIZE/2] = {1.2, 3.4, 5.6, 6.7, 7.8};
    double target_double[SIZE/2];

    puts("The original data of values:");
    show_int_array(values, SIZE);
    puts("The data of curious:");
    show_double_array(curious, SIZE/2);
    puts("*************");
    memcpy(target, values, sizeof(int)*SIZE);
    puts("The result of the target array:");
    show_int_array(target, SIZE);
    puts("*************");
    memcpy(values+5, values, sizeof(int)*SIZE);
    puts("The result of the values array:");
    show_int_array(values, SIZE);
    puts("************\n");

    puts("************");
    memmove(target_double, curious, sizeof(double)*(SIZE/2));
    puts("The result of the target_double:");
    show_double_array(target_double, SIZE/2);
    puts("***********");
    memmove(curious+2, curious, sizeof(double)*(SIZE/2));
    puts("The result of the curious array:");
    show_double_array(curious, SIZE/2);
    puts("***********\n");

    puts("**************");
    memcpy(target1, curious, sizeof(double)*(SIZE/2));
    puts("The result of the target1 array:");
    show_int_array(target1, SIZE/2);
    puts("**************");
    memmove(target2, curious, sizeof(double)*(SIZE/2));
    puts("The result of the target2 array:");
    show_int_array(target2, SIZE/2);
    puts("**************\n");

    puts("*****************");
    memcpy(target3, values, sizeof(int)*(SIZE));
    puts("The result of target3 array:");
    show_double_array(target3, SIZE);
    puts("****************");
    memmove(target4, values, sizeof(int)*SIZE);
    puts("The result of target4 array:");
    show_double_array(target4, SIZE);

    return 0;
}

void show_int_array(const int ptr[], int num)
{
    for (int i=0; i<num; i++)
    {
        printf("%d ", ptr[i]);
    }
    putchar('\n');
}

void show_double_array(const double arr[], int num)
{
    for (int i=0; i<num; i++)
    {
        printf("%g ", arr[i]);
    }
    putchar('\n');
}