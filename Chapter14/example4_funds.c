/*** function parameters ***/
#include <stdio.h>
#define FUNDS 80

struct funds{
    char bank[FUNDS];
    char owner[FUNDS];
    double bankfund;
    double savefund;
};
//double sum(struct funds *pst);  /* struct pointer */
//double sum(double n, double m);   /* struct field */
double sum(struct funds kevin); /* struct */

int main(void)
{
    struct funds stans = {
        "wemare bank",
        "keviness",
        1234.67,
        34567.89
    };
    puts("The informations:");
    printf("The bank:%s \n",stans.bank);
    printf("The owner:%s \n", stans.owner);
//  printf("The sum: %g \n", sum(&stans));
//  printf("The sum:%g \n", sum(stans.bankfund, stans.savefund));
    printf("The sum:%g \n", sum(stans));

    return 0;
}
/*
double sum(struct funds *pts)
{
    return ((pts->bankfund)+(pts->savefund));
}
*/

/*
double sum(double bankfund, double savefund)
{
    return (bankfund + savefund);
}
*/

double sum(struct funds kevin)
{
    return (kevin.bankfund + kevin.savefund);
}
