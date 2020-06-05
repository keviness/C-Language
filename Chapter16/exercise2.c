/*** Chapter16 exercise2 ***/
//Get the harmonic mean of two numbers
#include "exercise1.h"
#include <string.h>
#define INVERSE(X) (1/(X))
#define HARM(X, Y) (1/((INVERSE(X) + INVERSE(Y))/2))

int main(void)
{
    double x, y;
    double result;
    
    puts("Enter the numbers:");
    while (scanf("%lf %lf", &x, &y) == 2)
    {
        CLEARINPUT;
        result = HARM(x, y);
        printf("The harmonic number of %.3lf and %.3lf is %.3lf \n", x, y, result);
        puts("Enter the next pair numbers:");
    }
    puts("The Done~");

    return 0;
}