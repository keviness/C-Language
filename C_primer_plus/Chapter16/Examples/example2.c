/*** example16.4: ## and # ***/
#include <stdio.h>
#define XNAME(n) x ## n
#define PRINT_STATEMENT(n) printf("x" #n "=%d \n", x ## n)

int main(void)
{
    int XNAME(1) = 23;
    int XNAME(2) = 30;
    int XNAME(3) = 40;

    printf("x1 = %d \n", XNAME(1));
    printf("x2 = %d \n", XNAME(2));
    printf("x3 = %d \n", XNAME(3));

    PRINT_STATEMENT(1);
    PRINT_STATEMENT(2);
    PRINT_STATEMENT(3);

    return 0;
}