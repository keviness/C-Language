#include <stdio.h>
#include <stdbool.h>
bool bad_limits(long a, long b, long c, long d);
long get_long(void);
long get_squares(long x, long y);
int main(void)
{
    const long MAX = 10000L;
    const long MIN = -10000L;
    long start, end;
    double answer;
    printf("Enter the lower limits:");
    start = get_long();
    printf("Enter the uper limits:");
    end = get_long();
    while (start!=0 || end!=0)
    {
        if (bad_limits(start, end, MIN, MAX))
        {    
            printf("The error input, please try again!\n");
        }
        else
        {
            answer = get_squares(start, end);
            printf("The sum of from %ld to %ld is: %g\n", start, end, answer);    
        }
        printf("Enter the lower limits:");
        start = get_long();
        printf("Enter the uper limits:");
        end = get_long();
    }
    printf("Good bye!");
    return 0;
}
long get_long(void)
{
    char ch;
    long input;
    while ((scanf("%ld",&input) != 1))
    {
        while((ch=getchar()) != '\n')
            putchar(ch);
        printf(" is a wrong input, please try again!\n");
    }
    return input;
}
bool bad_limits(long begin, long end, long low, long high)
{
    bool not_good = false;
    if (begin > end)
    {
        printf("%ld is\'t smaller than %ld.\n", begin, end);
        not_good = true;
    }
    if (begin<low || end<low)
    {
        printf("values must be %ld, or more than it.\n", low);
        not_good = true;
    }
    if (begin>high || end>high)
    {
        printf("values must be %ld, or less than it.\n", high);
        not_good = true;
    }
    return not_good;
}
long get_squares(long start, long end)
{
    double sum;
    for (long i=start; i<=end; i++)
    {
        sum += (double)i*(double)i; 
    }
    return sum;
}
