/*** Chapter16 exercise3 ***/
#include "exercise1.h"
#include "exercise3.h"
#include <string.h>

int main(void)
{
    Polar polar_coord;
    Cartesian cartesian_coord;

    puts("Enter the magnitude:");
    while (scanf("%lf", &polar_coord.magnitude) == 1)
    {
        CLEARINPUT;
        puts("Enter the angle:");
        while (scanf("%lf", &polar_coord.angle) != 1)
        {
            char ch;
            while ((ch = getchar()) != '\n')
            {
                putchar(ch);
            }
            printf(" %s is not a number, try again! \n");
            puts("Enter the angle again:");
        }
        cartesian_coord = polarToCartesian(&polar_coord);
        printf("The magnitude is: %.3lf \n", polar_coord.magnitude);
        printf("The angle is: %.3lf \n", polar_coord.angle);
        puts("The result:");
        printf("The x is: %.3lf \n", cartesian_coord.x);
        printf("The y is: %.3lf \n", cartesian_coord.y);

        puts("Enter the next magnitude:");
    }

    return 0;
}