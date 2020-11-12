//3.11 exercise5
#include <stdio.h>

int main(void)
{
    int age;
    printf("Enter the age:");
    while (scanf("%d", &age) == 1)
    {
        printf("The time: %g seconds. \n", age*(3.156E7));
        printf("Enter the next age:");
    }
    
    return 0;
}