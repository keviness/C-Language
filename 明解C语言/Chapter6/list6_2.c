/*** Chapter6: list6-2 ***/
#include <stdio.h>
#include <time.h>
void put_date(const struct tm *timer);

int main(void)
{
    time_t current;
    struct tm *timer;

    time(&current);
    timer = gmtime(&current);
    printf("The time now: \n");
    put_date(timer);

    return 0;
}

void put_date(const struct tm *timer)
{
    char *week_name[] = {"Sun", "Mon", "Tues", "Weds", "Thurs", "Fri", "Sat"};
    printf("%4d year %02d month %02dday (%s) %02dHour:%02dMin:%02dSeconds",
            timer->tm_year + 1900,
            timer->tm_mon + 1, 
            timer->tm_mday,
            week_name[timer->tm_wday],
            timer->tm_hour,
            timer->tm_min,
            timer->tm_sec);
}