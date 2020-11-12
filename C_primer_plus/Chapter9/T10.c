#include <stdio.h>

int main(void)
{
    long number;
    int n;
    printf("Enter the number and integer:");
    while (scanf("%ld %d",&number, &n) == 2)
    {
        if (n == 10)
            printf("the number convert is:%2ld \n", number);
        else if (n == 8)
            printf("The number convert is:%2lo \n", number);
        else if (n == 16)
            printf("The number convert is:%2lx \n", number);
        else 
            printf("The number convert is wrong, please try again\n");
        printf("Enter the number and an integer:");
    }
}