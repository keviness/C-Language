/*** example16.2: function-like macro ***/
#include <stdio.h>
#define SQART(X) X*X
#define PR(X) printf("The rusult is %d \n", X)
#define SPREATE printf("************* \n")

int main(void)
{
    int x = 5;
    int result;

    result = SQART(x);
    PR(result);
    SPREATE;
    PR(SQART(x++));
    SPREATE;
    PR(x);
    SPREATE;
    PR(SQART(++x));
    SPREATE;
    PR(x);
    SPREATE;
    PR(SQART(x+2));
    SPREATE;

    return 0;
}