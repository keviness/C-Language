/*** Chapter6: list6-3 ***/
#include <stdio.h>
#include <time.h>
void asctime_ex(const time_t timer);
void ctime_ex(const time_t timer);
int ssleep(double x);

int main(void)
{
    time_t start, end;

    start = time(NULL);
    time_t current = time(NULL);
    asctime_ex(current);
    ctime_ex(current);
    ssleep(1128.3);
    end = time(NULL);
    printf("The time used:%4.2f \n", difftime(end, start));

    return 0;
}

void asctime_ex(const time_t timer)
{
    const struct tm *current_tm;
    current_tm = localtime(&timer);

    printf("The asctime: %s\n", asctime(current_tm));
}

void ctime_ex(const time_t timer)
{
    printf("The ctime: %s\n", ctime(&timer));
}

int ssleep(double x)
{
    time_t t1 = time(NULL), t2;
    do
    {
        if ((t2 = time(NULL)) == (time_t)-1)
        {
            return 0;
        }
    }while(difftime(t2, t1) < 0);

    return 1;
}