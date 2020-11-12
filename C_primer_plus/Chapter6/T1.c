#include <stdio.h>

int main(void)
{
    int arry[20];
    int number;
    for (int i=0; i<=7; i++)
    {
        printf("Enter your number:");
        scanf("%d", &number);
        arry[i] = number; 
    }
    printf("The numbers of the arry is: ");
    for (int j=0; j<=7; ++j)
    {
        printf("%d ", arry[j]);
    }

    return 0;
}