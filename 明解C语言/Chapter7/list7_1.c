#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

int main(void)
{
    int arr[SIZE] = {12, 21, 1, 2, 4, 5, 6};
    int choice[SIZE-1] = {0};
    srand(time(NULL));
    int x = rand();
    int i, j;
    i = j = 0;
    /*
    for (i=j=0; i<SIZE-1; i++)
    {
        if (i != x)
        {
            choice[j++] = arr[i];
        }
    }
    */
    while (i < SIZE)
    {
        if (i != x)
        {
            choice[j++] = arr[i];
        }
        i++;
    } 
    printf("The array: \n");
    for (i=0; i<j; i++)
    {
        printf("%d ", choice[j]);
    }

    return 0;
}

