/*** Chapter16:exercise5 ***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define SIZE 100
void sample(int arr[], int size, int num);

int main(void)
{
    int array[SIZE];
    int num;

    for (int i=0; i<SIZE; i++)
    {
        array[i] = i+2;
    }
    puts("How many items do you want:");
    while (scanf("%d", &num)==1 && num>0)
    {
         if (num > SIZE)
        {
            puts("The items number must less than array size");
            break;
        }
        puts("The items:");
        sample(array, SIZE, num);
        puts("\nHow many items do you want:");
    }
    puts("The Done~");

    return 0;
}

void sample(int arr[], int size, int num)
{
    bool chosen[size];
    int index;

    for (int i=0; i<size; i++)
    {
        chosen[i] = false;
    }
    srand(time(NULL));
    for (int j=0; j<num; j++)
    {
        index = rand()%size;
        while (chosen[index])
        {
            index = rand()%size;
        }
        printf("%d ", arr[index]);
        chosen[index] = true;
    }
}
