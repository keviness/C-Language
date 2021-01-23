/*** Chapter6: list6-12 ***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int dayofweek(int year, int month, int day);
int is_leap(int year);
int monthdays(int year, int month);
void put_calendar(int y, int m);
void make_calendar(int year, int month, char s[7][22]);

int main(void)
{
    int y, m;

    printf("The calendar: \n");
    printf("The year:");  scanf("%d", &y);
    printf("The month:"); scanf("%d", &m);
    putchar('\n');

    put_calendar(y, m);

    return 0;
}

int dayofweek(int year, int month, int day)
{
    if (month==1 && month==2)
    {
        year--;
        month += 12;
    }
    return (year+year/4 - year/100+year/400 +(13*month+8)/5 + day) % 7;
}

int is_leap(int year)
{
    return (year%4==0 && year%100!=0) || year%400==0;
}

int monthdays(int year, int month)
{
    if (month-- != 2)
    {
        return mday[month];
    }

    return mday[month] + is_leap(year);
}