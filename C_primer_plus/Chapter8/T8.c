#include <stdio.h>
float get_float(void);
int get_choice(void);
int get_first(void);
void get_add(void);
void get_multiply(void);
void get_subtract(void);
void get_divide(void);
int main(void)
{
    char ch;
    while ((ch=get_choice()) != 'q')
    {
        switch(ch)
        {
            case 'a': get_add();
                    break;
            case 's': get_subtract();
                    break;
            case 'm': get_multiply();
                    break;
            case 'd': get_divide();
                    break;
            default: printf("The programe error! \n");
                    break;
        }
    }
    printf("Good bye!");
    return 0;
}
int get_choice(void)
{
    int ch;
    printf("Enter your operation of your choice:\n");
    printf("a.add             s.substract \n");
    printf("m.multiply        d.divide \n");
    printf("q.quit\n");
    ch = get_first();
    while (ch!='a' && ch!='s' && ch!='m' && ch!='d' && ch!='q')
    {
        printf("The wrong input, try gain:\n");
        ch = get_first();
    }
    return ch;
}
int get_first(void)
{
    int ch;
    ch = getchar();
    while (getchar() != '\n')
        continue;
    return ch;
}
float get_float(void)
{
    float input;
    while (scanf("%f", &input) != 1)
    {
        while ((input=getchar()) != '\n')
            putchar(input);
        printf(" is not a float, try again:");
    }
    while (getchar() != '\n')
        continue;
    return input;
}
void get_add(void)
{
    float answer, first, second;
    printf("Enter the first number:\n");
    first = get_float();
    printf("Enter the second number:\n");
    second = get_float();
    answer = first + second;
    printf("The value of addition is:%2g \n", answer);
}
void get_subtract(void)
{
    float answer, first, second;
    printf("Enter the first number:\n");
    first = get_float();
    printf("Enter the secone number:\n");
    second = get_float();
    answer = first - second;
    printf("The value of substraction is:%2g \n", answer);
}
void get_multiply(void)
{
    float answer, first, second;
    printf("Enter the first number:\n");
    first = get_float();
    printf("Enter the secone number:\n");
    second = get_float();
    answer = first * second;
    printf("The value of substraction is:%2g \n", answer);
}
void get_divide(void)
{
    float answer, first, second;
    printf("Enter the first number:\n");
    first = get_float();
    printf("Enter the secone number:\n");
    second = get_float();
    while (second == 0)
    {
        printf("The second number must more than zero,try again:");
        second = get_first();
    }
    answer = first / second;
    printf("The value of substraction is:%2g \n", answer);
}