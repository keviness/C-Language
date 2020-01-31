#include <stdio.h>
void large_of(double *m, double *n);
int main(void)
{
    double first, second;
    printf("Enter the numbers:");
    while (scanf("%g %g", &first, &second) ==2)
    {
        printf("The first is:%3g \n", first);
        printf("The second is:%3g \n", second);
        large_of(&first, &second);
        printf("The first is:%3g\n", first);
        printf("The secon is:%3g\n", second);

        printf("Enter the numbers:");
    }
    printf("Good bye!");
    return 0; 
}
void large_of(double *m, double *n)
{
    if (*m > *n)
        *n = *m;
    else
    {
        *m = *n;
    }
}