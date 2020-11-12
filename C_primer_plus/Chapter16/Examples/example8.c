/*** example16.16: <stdlib.h> atexit() exit() ***/
#include <stdio.h>
#include <stdlib.h>
void provide_wrong(void);
void sign_off(void);

int main(void)
{
    int num;

    atexit(sign_off);
    printf("Enter your number:");
    if ((num = scanf("%d", &num)) != 1)
    {
        printf("The num information: \n");
        atexit(provide_wrong);
        exit(EXIT_FAILURE);
    }
    printf("%d is a %s num. \n", num, (num%2!=0? "odd":"even"));

    return 0;
}

void provide_wrong(void)
{
    printf("The input isn\'t a number. \n");
}

void sign_off(void)
{
    printf("The program exit successfully! \n");
}