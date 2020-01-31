#include <stdio.h>
#define STOP '0'
int main(void)
{
    char chr;
    int n_double, n_prime, n_char;
    double sum_double, sum_prime; 
    double ave_double, ave_prime;
    printf("Enter your letters:\n");
    while ((chr=getchar()) != STOP)
    {
        n_char++;
        if ((int)chr%2 == 0 )
        {    
            n_double++;
            sum_double += (int)chr;
        }
        else
        {
            n_prime++;
            sum_prime += (int)chr;
        }
    }
    printf("The sum of the numbers:%3d \n", n_char);
    printf("The total number od odds:%3d.\n", n_double);
    
    printf("The number of primes:%3d\n", n_prime);
    if (n_double > 0)
        printf("The average of the odd number:%3g\n", sum_double/n_double);
    if (n_prime > 0)
        printf("The average of the prime number:%3g\n", sum_prime/n_prime);

    return 0;
}