/*--struct a function replace function strlen()--*/
#include <stdio.h>
#include <string.h>
#define SIZE 20
char *s_gets(char *st, int n);
int str_count(char *str);

int main(void)
{
    char input[SIZE];
    puts("Enter your letters:");
    while (s_gets(input, SIZE) && input[0]!='\0')
    {
        puts("The letter you input :");
        puts(input);
        printf("The %d characters of the letter \n", str_count(input));
    }
    puts("The done~");
    return 0;
}
char *s_gets(char *st, int num)
{
    char *ptr;
    ptr = fgets(st, num, stdin);
    if (ptr)
    {
        while (*st!='\n' && *st!='\0')
            st++;
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
int str_count(char *str)
{
    int count;
    while (*str)
    {
        count++;
        str++;
    }
    return count;
}