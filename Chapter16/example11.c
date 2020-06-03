/*** example16.23: <stdarg.h> ***/
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
double sum(int len, ...);

int main(void)
{
    double sum1, sum2;
    sum1 = sum(3, 1.2, 3.4, 4.5);
    sum2 = sum(6, 1.2, 4.5, 6.7, 2.3, 3.4, 5.6);
    printf("The result for sum1: %g \n", sum1);
    printf("The result for sum2: %g \n", sum2);

    return 0;
}

double sum(int len, ...)
{
    double total;
    va_list arguments;
    va_start(arguments, len);

    for (int i=0; i<len; i++)
    {
        total += va_arg(arguments, double);
    }
    va_end(arguments);

    return total;
}