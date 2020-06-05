/*** Chapter16: exercise4 ***/
#include <stdio.h>
#include <string.h>
#include <time.h>
void timeout(double time);

int main(void)
{
    double time;

    puts("Enter the desire time you want to delay in seconds:");
    while (scanf("%lf", &time) == 1)
    {
        puts("Starting:");
        timeout(time);
        printf("It is %lf later. \n", time);
        puts("Enter the desire time to delay:");
    }
    
    return 0;
}

void timeout(double time)
{
    double start, end;
    start = clock();
    end = clock();
    while ((end-start)/(double)CLOCKS_PER_SEC < time)
    {
        end = clock();
    }
    
    return;
}

