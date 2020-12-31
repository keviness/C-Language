/*** Chapter6: list6-3 ***/
#include <stdio.h>
#include <time.h>
void asctime_ex(const time_t timer);
void ctime_ex(const time_t timer);

int main(void)
{
    time_t current = time(NULL);
    asctime_ex(current);
    ctime_ex(current);

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