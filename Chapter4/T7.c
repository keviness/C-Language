#include <stdio.h>
#include <float.h>

int main(void)
{
    float number, division;

    printf("Enter your number(a float number):");
    scanf("%f %f", &number, &division);

    printf("the number:%10.3f \n", number/division);
    printf("the exponetial notation:%3.2e\n", number/division);

    printf("the double number:%7.6g \n", number/division);
    printf("the exponetial notation:%3.2e \n", number/division);

    printf("the long double number:%20.12lf\n", number/division);
    printf("the exponetial notation:%3.2E \n", number/division);

    printf("float-dig:%d \n", FLT_DIG);
    printf("double-dig:%d", DBL_DIG);

    return 0;
}