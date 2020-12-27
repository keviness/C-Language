#include <stdio.h>
#define MAX 10

int main(void)
{
    int i;
    int array[MAX];
    int count = 0;
    int retry;

    printf("Enter the integer: \n");

    do
    {
        printf("The %d number:", count+1);
        scanf("%d", &array[count++ % MAX]);

        printf("Do you want to continue?(y/1|n/0):");
    } while (scanf("%d", &retry)==1 && retry==1);

    i = count - MAX;
    if (i < 0) i = 0;
    for (; i < count; i++)
    {
        printf("The %d number: %d \n", i+1, array[i%MAX]);
    }

    return 0;
} 