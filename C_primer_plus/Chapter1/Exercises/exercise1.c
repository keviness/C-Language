#include <stdio.h>

int main(void)
{
    double input;
    double output;

    printf("Enter the number that you want to convert(q to quit):");
    while (scanf("%lf", &input) == 1)
    {
        output = input*2.54;
        printf("The result: %4.2lf cm\n", output);
        printf("Enter the next nubmer:");
    }
    printf("The Done~");

    return 0;
}