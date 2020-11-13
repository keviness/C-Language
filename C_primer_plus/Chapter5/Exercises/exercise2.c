/*** chapter5 exercise2 ***/
#include <stdio.h>
#include <string.h>

int main(void)
{
    int number;
    int incresement = 0;
    printf("Enter the number:");
    scanf("%d", &number) == 1;
    while (incresement <= 10)
    {
        printf("%d ", number+incresement);
        incresement++;
    }
    
    return 0;
}