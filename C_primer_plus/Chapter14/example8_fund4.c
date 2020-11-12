/*** struct array ***/
#include <stdio.h>
#include <string.h>
#define NUM 2
#define FOUNDLEN 50

struct funds{
    char name[FOUNDLEN];
    char bank[FOUNDLEN];
    double savefund;
    double bankfund;
};
double sum(const struct funds money_sum[], int n);

int main(void)
{
    struct funds kevin[NUM] = {
        {
            "keviness",
            "nanchang bank",
            23456.67,
            334590.89
        },
        {
            "lake lucy",
            "jiujiang",
            223456.90,
            2309.90
        }
    };
    puts("The funds:");
    for (int i=0; i<NUM; i++)
    {
        printf("%s in %s save %3.2lf \n", kevin[i].name, kevin[i].bank, kevin[i].bankfund+kevin[i].savefund);
    }
    printf("The sum money:%3.2lf \n", sum(kevin, NUM));

    return 0;
}
double sum(const struct funds money[], int num)
{
    double total;
    for (int i=0; i<NUM; i++)
    {
        total += money[i].savefund+money[i].bankfund;
    }
    return total;
}