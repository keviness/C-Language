/*** example16.5: variable arguments ***/
#include <stdio.h>
#include <math.h>
#define PR_RESULT(x, ...) printf("Result" #x ": "  __VA_ARGS__ )

int main(void)
{
    int x = 25;
    int result;

    result = sqrt(x);
    PR_RESULT(x, "x = %g \n", x);
    PR_RESULT(result, "result = %g \n", result);

    return 0;
}