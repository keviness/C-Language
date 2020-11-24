/*** Chaptr14: test1 ***/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MONLINE 10
#define ABBREV 5

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

int get_day_total(char *str);
char *s_gets(char *str, int num);

int main(void)
{
    char month_name[MONLINE];
    int day_total;

    puts("Enter the month name:");
    while (s_gets(month_name, MONLINE) && month_name[0]!='\0')
    {
        day_total = get_day_total(month_name);
        if (day_total > 0)
            printf("There %d days througth %s months \n", day_total, month_name);
        else
        {
            printf("the %s month you input is wrong! \n", month_name);
        }
        puts("Input the next month:");
    }
    puts("The Done~");

    return 0;
}

int get_day_total(char *str)
{
    int month_code = 0;
    int total_days = 0;
    str[0] = toupper(str[0]);
    for (int i=1; str[i]!='\0'; i++)
    {
        str[i] = tolower(str[i]);
    }
    for (int i=0; i<12; i++)
    {
        if (strcmp(str, months[i].month_full) == 0)
        {
            month_code = months[i].month_num;
            break;
        }
    }
    if (month_code > 0)
    {
        for (int i=0; i<month_code; i++)
        {
            total_days += months[i].days;
        }
    }
    else
    {
        total_days = -1;
    }
    return total_days;
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