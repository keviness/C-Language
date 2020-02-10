#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    double base, exponent;
    if (argc != 3)
    {
        printf("%s: arguments counts is not right\n", argv[0]);
    }
    else
    {
        base = atof(argv[1]);
        exponent = atof(argv[2]);
        printf("%f to the %f is: %g",base, exponent, pow(base, exponent));
    }
    return 0;
}