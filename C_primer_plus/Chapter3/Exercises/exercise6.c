//3.11 exercise6
#include <stdio.h>

int main(void)
{
    double kuato;
    printf("Enter the kuato:");

    while (scanf("%f", &kuato) == 1)
    {
        printf("The %g kuatu is %g molecules \n", kuato, kuato*950/3E-23);
        printf("Enter the next kuato of molecules:");
    }
    
    return 0;
}