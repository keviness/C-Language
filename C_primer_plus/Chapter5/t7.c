#include <stdio.h>
void print_value(double n);

int main(void)
{
    float number;

    printf("Enter your double number:");
    while((scanf("%f", &number) == 1))
    {
        print_value(number);
    }
    return 0;
}
void print_value(double number)
{
    printf("the value:%g \n", number*number*number);
    printf("Enter your double number(q to quit):");
}