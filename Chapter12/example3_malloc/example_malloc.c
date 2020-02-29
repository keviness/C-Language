#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double * ptd;
    int max;
    int number;
    int i;

    puts("How many numbers do you want:");
    if (scanf("%d", &max) != 1)
    {
        puts("The error, please input a interge!");
        exit(EXIT_FAILURE);
    }
    ptd = (double *) malloc(max * sizeof(double));
    if (ptd == NULL)
    {
        puts("The Memory allocated failed!");
        exit(EXIT_FAILURE);
    }

    puts("Enter the number you want to save:");
    while (i<max && scanf("%g", &ptd[i])==1)
    {
        i++;
    }

    printf("The %d numbers you input in the array: \n", number = i);
    for (i=0; i<number; i++)
    {
        printf("the %d number is: %g \n", i+1, ptd[i]);
        if (i % 7 == 0)
        {
            putchar('\n');
        }
    }
    if (i % 7 != 6)
        putchar('\n');

    return 0;
}