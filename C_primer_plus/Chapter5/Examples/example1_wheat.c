//5.5 example1: wheat
#include <stdio.h>
#define SIZE 64

int main(void)
{
    int count = 1;
    const double CROP = 2E16;
    double current;
    double total;
    current = total = 1;

    printf("square      current crop      total crop      world crop\n");
    printf("%2d        %4.2g              %4.2g             %4.2g  \n",
         count, current, total, total/CROP);

    while (count < SIZE)
    {
        current *= 2;
        total += current;
        printf("%2d        %4.2g              %4.2g              %4.2g  \n",
         count+1, current, total, total/CROP);
        count++;
    }
    printf("That is all!");

    return 0;
}