#include <stdio.h>
#include <stdbool.h>
int main(void)
{
    long num, div;
    bool nisprime ;
    printf("Enter the limit number(q to quit):\n");
    while (scanf("%ld", num)==1 && num>0)
    {
        if (num < 1)
            printf("The number has no prime number.");
        if (num > 1)
        {
            for (long n=2; n<=num; n++)
            {
                for (div=2, nisprime=true; div*div<n; div++)
                {    
                    if (n%div==0)
                        nisprime = false;
                }
                if (nisprime)
                    printf("The prime number is:%d", n);
            }
        }
    }
    return 0;
}