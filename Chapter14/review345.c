/*** review test3、4、5 ***/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MONLINE 10
#define ABBREV 5
//int day_show(int n);
int day_show(char *str);
char *s_gets(char *str, int n);

struct month{
    char month_full[MONLINE];
    char month_shrink[ABBREV];
    int days;
    int month_num;
};

const struct month months[12] = {
    {"Januray", "JAN", 31, 1},
    {"Feburary", "FEB", 28, 2},
    {"March", "MAR", 31, 3},
    {"April", "APR", 30, 4},
    {"May", "MAY", 31, 5},
    {"June", "JUN", 30, 6},
    {"July", "JUL", 31, 7},
    {"August", "AUG", 30, 8},
    {"September", "SEP", 30, 9},
    {"October", "OCT", 31, 10},
    {"November", "NOV", 30, 11},
    {"December", "DEC", 31, 12}
};

int main(void)
{
    int daytotal;
    char mon_ful[MONLINE];
//  int month_num;
    puts("Enter the month string(q to quit):");
/*  
    while (scanf("%d", &month_num) == 1)
    {
        daytotal = day_show(month_num);
        if (daytotal > 0)
        {
            printf("There %d days througth %d months \n", daytotal, month_num);
        }
        else
            printf("The %d month you input is wrong! \n", month_num);
    }
*/
    while (s_gets(mon_ful, MONLINE) && mon_ful[0]!='\0')
    {
        daytotal = day_show(mon_ful);
        if (daytotal > 0)
            printf("There %d days througth %s months \n", daytotal, mon_ful);
        else
        {
            printf("the %s month you input is wrong! \n", mon_ful);
        }
        puts("Input the next month:");
    }
    puts("The done~");

    return 0;
}

/*
int day_show(int mon)
{
    int total;
    int mon_num = 0;
    for (int i=0; i<12; i++)
    {
        if (mon == months[i].month_num)
        {
            mon_num = mon;
            break;
        }
    }
    if (mon_num == 0)
    {
        total = -1;
    }
    else
    {
        for (int i=0; i<mon_num; i++)
        {
            total += months[i].days;
        }
    }
    return total;
    
}
*/

int day_show(char *mon_str)
{
    int mon_num;
    int total = 0;
    mon_str[0] = toupper(mon_str[0]);
    for (int i=1; mon_str[i]!='\0'; i++)
    {
        mon_str[i] = tolower(mon_str[i]);
    } 
    for (int i=0; i<12; i++)
    {
        if (strcmp(mon_str, months[i].month_full) == 0)
        {
            mon_num = months[i].month_num;
            break;
        }
    }
    if (mon_num > 0)
    {
        for (int i=0; i<mon_num; i++)
        {
            total += months[i].days;
        }
    }
    else
    {
        total = -1;
    }
    return total;
}

char *s_gets(char *str, int num)
{
    char *ptr;
    ptr = fgets(str, num, stdin);
    if (ptr)
    {
        while (*str!='\n' && *str!='\0')
        {
            str++;
        }
        if (*str == '\n')
            *str = '\0';
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }
    return ptr;
}