/*** Chapter6: list6-9 ***/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int dayofweek(int year, int month, int day);


int main(void)
{
    int y, m, d, w;
    char *weeks[] = {"Sun", "Mon", "Tues", "Wed", "Thur", "Fri", "Sat"};

    puts("Enter the year, month, day:");
    printf("The year:");  scanf("%d", &y);
    printf("The month:"); scanf("%d", &m);
    printf("The day: "); scanf("%d", &d);

    w = dayofweek(y, m, d);

    if (w == -1)   printf("Can\'t get the week \n");
    else printf("The week is:%s \n", weeks[w]);

    return 0;
}

int dayofweek(int year, int month, int day)
{
    struct tm t;
    t.tm_year = year - 1900;
    t.tm_mon = month - 1;
    t.tm_mday = day;
    t.tm_hour = 0;
    t.tm_min = 0;
    t.tm_sec = 0;
    t.tm_isdst = -1;

    if (mktime(&t) == (time_t)-1)  return -1;
    else  return t.tm_wday;
}