/*--replace Array with pointer in s_gets function--*/
#include <stdio.h>
#include <string.h>
#define SIZE 20
char *s_gets(char *st, int n);

int main(void)
{
    char input[SIZE];
    puts("Enter your letters:");
    while (s_gets(input, SIZE) && input[0]!='\0')
    {
        puts("The letters you enter:");
        puts(input);
    }
    return 0;
}
char *s_gets(char *st, int num)
{
    char *ptr;
    ptr = fgets(st, num, stdin);
    if (ptr)
    {
        while (*st!='\n' && *st!='\0')
        {
            st++;
        }
        if (*st == '\n')
            *st = '\0';
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }
    return ptr;
}
