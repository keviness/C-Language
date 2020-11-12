/*** example16.18: assert() ***/
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>

int main (void)
{
    float x, y, value;

    puts("Enter the your pair numbers:");
    while (scanf("%f %f", &x, &y) == 2 && (x!=0 || y!=0))
    {
        value = x*x - y*y;
        assert(value > 0);
        printf("The answer is: %lf \n", sqrt(value));
        puts("Enter the next pair numbers:");
    }
    puts("The Done~");

    return 0;
}