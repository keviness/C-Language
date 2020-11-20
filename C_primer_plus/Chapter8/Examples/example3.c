/*checking*/
#include <stdio.h>
#include <stdbool.h>
long get_long(void);
long sum_squares(long a, long b);
bool bad_limits (long begin, long end, long low, long high);
int main(void)
{
    const long MIN = -1000L;
    const long MAX = 1000L;
    long start;
    long stop;
    double answer;
    printf("Enter the start number(0 to quit):");
    start = get_long();
    printf("Enter the end number(0 to quit):");
    stop = get_long();
    while (start != 0 || stop != 0)
    {
        if (bad_limits(start, stop, MIN, MAX))
            printf("The wrong, try again!\n");
        else
        {
            answer = sum_squares(start, stop);
            printf("The sum of the sauares of the integers:\n");
            printf("from %d to %d is %g\n", start, stop, answer);
        }
        printf("lower limit:\n");
        start = get_long();
        printf("upper limit:\n");
        stop = get_long();
    }
    printf("The done!");

    return 0;
}
long get_long(void)
{
    long input;
    char ch;
    while (scanf("%ld", &input) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar('\n');
        printf("is the wrong input, try again!");
    }
    return input;
}
bool bad_limits(long begin, long end, long low, long high)
{
    bool not_good = false;
    if (begin > end)
    {
        printf("%ld is not smaller  than %ld.\n", begin, end);
        not_good = true;
    }
    if (begin<low || end<low)
    {
        printf("values must be %ld or greater.\n", low);
        not_good = true;
    }
    if (begin>high || end>high)
    {
        printf("values must be %ld or smaller.\n", high);
        not_good = true;
    }
    return not_good;
}
long sum_squares(long a, long b)
{
    double total = 0;
    long i;
    for (i=a; i<=b; i++)
        total += (double)i *(double)i;
    return total;
}