/*** 2-1 操纵时间: list2-6 ***/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    clock_t start, end;
    long a, b, c;
    long answer;
    double spend_time;

    srand(time);
    a = rand() % 90;
    b = rand() % 101;
    c = rand() % 1000;
    
    printf("%ld + %ld + %ld =  \n", a, b, c);
    start = clock();
    while (1)
    {
        scanf("%ld", &answer);
        if (answer == a+b+c)
        {
            break;
        }
        printf("It is wrong! try again:");
    }
    end = clock();
    printf("time used: %lf seconds \n", (double)(end-start)/CLOCKS_PER_SEC);
    printf("The done~ the result: %ld \n", a+b+c);
    
    return 0;
}