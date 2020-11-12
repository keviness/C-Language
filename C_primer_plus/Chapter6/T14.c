#include <stdio.h>

int main(void)
{
    int arry1[8], arry2[8];
    int element;
    int sum=0;
    printf("Enter the numbers:");
    for (int i=0; i<8; i++)
    {
        scanf("%d", &element);
        arry1[i] = element;
        sum = sum + element;
        arry2[i] = sum;
        printf("Enter the number:");
    }
    for (int j=0; j<8; j++)
    {
    printf("\n%3d %3d\n", arry1[j], arry2[j]);
    }

    return 0;
}