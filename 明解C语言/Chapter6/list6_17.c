/*** Chapter6: list6-17 ***/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int mday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int dayofweek(int year, int month, int day);
int is_leap(int year);
int monthdays(int year, int month);
void put_calendar(int y, int m);
int strncmpx(const char *s1, const char *s2, size_t n);
int get_month(char *s);

int main(int argc, char *argv[])
{
    int y, m;
    time_t t = time(NULL);
    struct tm *local = localtime(&t);

    y = local->tm_year + 1900;
    m = local->tm_mon + 1;

    if (argc >= 2)
    {
        m = get_month(argv[1]);
        if (m<0 || m>12)
        {
            fprintf(stderr, "The month error! \n");
            return 1;
        }
    }
    if (argc >= 3)
    {
        y = atoi(argv[2]);
        if (y < 0)
        {
            fprintf(stderr, "The year error! \n");
            return 1;
        }
    }
    printf("Year:%d  Month:%d ", y, m);
    put_calendar(y, m);

    return 0;
}

int get_month(char *s)
{
    int i, m;
    char *month[] = {"January", "February", "March","April", "May", "June", "July", "August", "September", "October", "November", "December"};
    m = atoi(s);
    if (m>=1 && m<=12)
        return m;
    for (i=1; i<=12; i++)
    {
        if (strncmpx(month[i], s, 3) == 0)
            return i;
    }

    return -1;
}

int strncmpx(const char *s1, const char *s2, size_t n)
{
    while (n && toupper(*s1) && toupper(*s2))
    {
        if (toupper(*s1) != toupper(*s2))
            return (unsigned char)*s1 - (unsigned char)*s2;
        s1++;
        s2++;
        n--;
    }
    if (!n) return 0;
    if (*s1) return 1;
    return -1;
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

void put_calendar(int year, int month)
{
    int weekday = dayofweek(year, month, 1);
    int days  = monthdays(year, month);

    printf("\nSUN MON TUE WED THU FRI SAT \n");
    printf("%*s", 3*weekday, "");
    for (int i=1; i<=days; i++)
    {
        printf("%3d", i);
        if (++weekday % 7 == 0)
        {
            putchar('\n');
        }
    }
    if (weekday %7 !=0)
        putchar('\n');
}