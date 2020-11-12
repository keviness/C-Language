/*---T4---*/
#include <stdio.h>
#define SIZE 7
double max_arry(const double *ar, int r);

int main(void)
{
    double ar[7]={1.2, 2.3, 4.5, 6.4, 4.6, 1.4, 1.9};
    printf("The max of the arry:%2g", max_arry(ar, SIZE));
    
    return 0;
}
/*choose the max value*/
double max_arry(const double *ar, int r)
{
    int i;
    double max = ar[0];
    for (i=0; i<r; i++)
    {
        if (max<ar[i])
            max = ar[i];
    }
    return max;
}