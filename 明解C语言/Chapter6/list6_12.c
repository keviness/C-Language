/*** Chapter6: list6-12 ***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int dayofweek(int year, int month, int day);
int is_leap(int year);
int monthdays(int year, int month);
void put_calendar(int y1, int m1, int y2, int m2);
void make_calendar(int year, int month, char s[7][22]);

int main(void)
{
    int y1, y2, m1, m2;

    printf("Enter the start year/month: \n");
    printf("The year:");  scanf("%d", &y1);
    printf("The month:"); scanf("%d", &m1);
    putchar('\n');
    printf("Enter the end year/month: \n");
    printf("The year:");  scanf("%d", &y2);
    printf("The month:");  scanf("%d", &m2);
    put_calendar(y1, m1, y2, m2);

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

void make_calendar(int year, int month, char s[7][22])
{
    int i, k;
    int wd = dayofweek(year, month, 1);
    int mdays = monthdays(year, month);
    char tmp[4];

    sprintf(s[0], "%14d / %02d     ", year, month);
    for (k=1; k<7; k++)
        s[k][0] = '\0';

    k = 1;
    sprintf(s[k], "%*s", 3*wd, "");

    for (i=1; i<=mdays; i++)
    {
        sprintf(tmp, "%3d", i);
        strcat(s[k], tmp);
        if (++wd % 7 == 0)
            k++;
    }
    if (wd % 7 == 0)
        k--;
    else
    {
        for (wd %= 7; wd<7; wd++)
            strcat(s[k], "  ");
    }
    while (++k < 7)
        sprintf(s[k], "%21s", "");
}

void print(char sbuf[3][7][22], int n)
{
    int i, j;

    for (i=0; i<n; i++)
    {
        printf("%s   ", sbuf[i][0]);
    }
    putchar('\n');

    for (i=0; i<n; i++)
        printf(" Sun Mon Tue Wed Thu Fri Sat     ");
    putchar('\n');
    for (i=0; i<n; i++)
        printf("-----------------------    ");
    putchar('\n');

    for (i=1; i<7; i++)
    {
        for (j=0; j<n; j++)
            printf("%s  ", sbuf[j][i]);
        putchar('\n');
    }
    putchar('\n');
}

void put_calendar(int y1, int m1, int y2, int m2)
{
    int y = y1;
    int m = m1;
    int n = 0;
    char sbuf[3][7][22];

    while (y <= y2)
    {
        if (y == y2 && m >m2) break;
        make_calendar(y, m, sbuf[n++]);
        if (n == 3)
        {
            print(sbuf, n);
            n = 0;
        }
        m++;
        if (m==13 && y<y2)
        {
            y++;
            m = 1;
        }
    }
    if (n)
    {
        print(sbuf, m);
    }
}

