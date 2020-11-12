#include <stdio.h>
double to_base_n(double m, int n);

int main(void)
{
    double base, answer;
    int n;
    printf("Enter the base and the integer:");
    while (scanf("%lg %d", &base, &n) == 2)
    {
        answer = to_base_n(base, n);
        printf("The value is:%2g \n", answer);
        printf("Enter the base and the integer:");
    }
    printf("Good bye!\n");
    return 0;
}
double to_base_n(double m, int n)
{
    double value = 1;
    if (n==0 && m==0)
    {
        value = 0.0;
    }
    else if (m==0)
        value = 1.0; 
    else if (n>0)
    {
        for (int i=1; i<=n; i++)
            value *= m;
    }
    else
    {
        value = 1/(to_base_n(m, -n));
    }
    return value;
}