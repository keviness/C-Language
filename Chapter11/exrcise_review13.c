#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ANSWER "QUIT"
#define SIZE 20
void toUpper(char *st);
char *s_gets(char *st, int );

int main(void)
{
    char try[SIZE];
    puts("Enter your letter:");
    while (s_gets(try, SIZE) && try[0]!='\0')
    {
        puts("The letters you input:");
        puts(try);
        toUpper(try);
        puts(try);
        if (strcmp(try, ANSWER) != 0)
        {
            puts("The wrong, try again:");
        }
        else
        {
            puts("That\'s right!");
        }
        puts("Enter next letter:");
    }
    puts("The done~");
}
char *s_gets(char *st, int num)
{
    char *ptr;
    char *find;
    ptr = fgets(st, num, stdin);
    if (ptr)
    {
        find = strchr(st, '\n');
        if (find != NULL)
        {
            *find = '\0';
        }
        else
        {
            while (getchar() != '\n')
            {
                continue;
            }
        }
    }
    return ptr;
}
void toUpper(char *st)
{
    while (*st)
    {
        *st = toupper(*st);
        st++;
    }
}