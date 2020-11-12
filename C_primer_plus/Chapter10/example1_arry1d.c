/*Arry show and multiply*/
#include <stdio.h>
#define SIZE 5
void show(int *pt, int n);
void multiply(int *pr, int m, double num);
int main(void)
{
    int * pt;
    int number;
    int arry1[SIZE] = {10,2,3,4,5};
    printf("The array is:\n");
    show(arry1, SIZE);
    multiply(arry1, SIZE, 2.5);
    printf("Now yhe array is:\n");
    show(arry1, SIZE);

    return 0;
}
void show(int *pt, int n)
{
    for (int i=0; i<n; i++)
    {
        printf("%d ", *(pt+i));
    }
    putchar('\n');
}
void multiply(int *pr, int m, double num)
{
    for (int i=0; i<m; i++)
    {
        *pr *= num;
        pr++;
    }
}