/*** test 2 ***/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MONFULL 10
#define MONABBREV 5
#define DAY_TAL 20
char *s_gets(char *str, int n);

struct month
{
    char month_full[MONFULL];
    char month_abbrev[MONABBREV];
    int month_code;
    int days;
    int year;
};
int get_info(struct month *pst);
void show_info(const struct month *pst);

int main(void)
{
    struct month mon_info;
    struct month *pst;
    const struct month *pst_cst;
    pst = &mon_info;
    pst_cst = &mon_info;
    puts("Enter your infomation:");
    while (get_info(pst) != 0)
    {
        puts("The informations you need:");
        show_info(pst_cst);
        puts("Enter the next infomation:");
    }
    puts("The done~");

    return 0;
}

int get_info(struct month *pst)
{
    int info;
    puts("Enter the years:");
    if (scanf("%d", &pst->year) == 1)
    {
        puts("Enter the month:");
        if (scanf("%s", pst->month_abbrev)==1 \
        && scanf("%s",pst->month_full) && scanf("%d", &pst->month_code))
        {
            puts("Enter the day:");
            scanf ("%d", &pst->days);
            info = 1;
        }
    }
    else
    {
        info = 0;
    }
    return info;
}

void show_info(const struct month *pst)
{
    int total;
    int days_sum;
    int days_list[12]={31,29,31,30,31,30,31,31,30,31,30,31};

    if ((pst->month_code)>2 && !((pst->year)%400==0 || (((pst->year)%4==0)&&((pst->year)%100!=0))))
    {
        total = 0;
        for (int i=0; i<(pst->month_code); i++)
        {
            total += days_list[i]; 
        }
        days_sum = total + (pst->days) -1;
    }
    /*
    else if ((pst->month_code)<2 && !((pst->year)%400==0 || (((pst->year)%4==0)&&((pst->year)%100!=0))))
    {
        total = 0;
        for (int i=0; i<(pst->month_code); i++)
        {
            total += days_list[i];
        }
        days_sum = total + (pst->days);
    }
    */
    else
    {
        total = 0;
        for (int i=0; i<(pst->month_code); i++)
        {
            total += days_list[i];
        }
        days_sum = total + (pst->days);
    }
    printf("There are %d days thougth %d months in %d \n", days_sum, pst->month_code, pst->year);
}

char *s_gets(char *str, int num)
{
    char *ptr;
    ptr = fgets(str, num, stdin);
    if (ptr)
    {
        while (*str!='\n' && *str!='\0')
            str++;
        if (*str == '\n')
            *str = '\0';
        else
        {
            while (getchar() != '\n')
            {
                continue;
            }
        }
    }
    return ptr;
}