#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
char *s_gets(char *st, int n);

int main(void)
{
    long value;
    char *end;
    char input[SIZE];
    puts("Enter your number:");
    while (s_gets(input, SIZE) && input[0]!='\0')
    {
        value = strtol(input, &end, 10);
        printf("The number base 10 is:%2d and end with %s(%2d) \n", value, end, *end);
        value = strtol(input, &end, 8);
        printf("The number base 8 is:%2d and end with %s(%2d) \n", value, end, *end);
        value = strtol(input, &end, 16);
        printf("The number base 16 id%2d and end with %s(%2d) \n", value, end, *end);

        puts("Enter your next number");
    }
    return 0;
}
char *s_gets(char *st, int num)
{
    int i = 0;
    char *ptr;
    ptr = fgets(st, num, stdin);
    if (ptr)
    {
        while (st[i]!='\n' && st[i]!='\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }
    return ptr;
}