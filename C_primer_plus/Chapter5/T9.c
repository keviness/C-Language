#include <stdio.h>
void temperature(double n);

int main(void)
{
    float F_temp;
    printf("Enter the temperature:");
    while(scanf("%f", &F_temp) == 1)
    {
        temperature(F_temp);
        printf("Enter the temperature(q to quit):");
    }
    printf("the end!");

    return 0;
}

void temperature( double F_temp)
{
    double K_temp, S_temp;
    K_temp = 5.0/9.0*(F_temp-32.0);
    S_temp = K_temp + 273.16;
    printf("the k_temperature:%4.2g \n", K_temp);
    printf("the S_temperature:%4.2g \n", S_temp);
}