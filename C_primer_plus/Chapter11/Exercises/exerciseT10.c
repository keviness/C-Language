/*---remove the space betteen words---*/
#include <stdio.h>
#include <string.h>
#define SIZE 30
char *s_gets(char *st, int n);
void drop_space(char *st);

int main(void)
{
    char input[SIZE];
    puts("Enter your letters:");
    while (s_gets(input, SIZE) && input[0]!='\0')
    {
        puts("The origin letters:");
        puts(input);
        drop_space(input);
        puts("The letters after calling drop space:");
        puts(input);
        puts("Enter your lettes:");
    }
    puts("The done~");

    return 0;
}
void drop_space(char *st)
{
    char *ptr;
    ptr = st;
    while (*st)
    {
        if (*ptr == ' ')  // if it is space point next char
        {
            ptr++;
        }
        *st = *ptr;
        st++;
        ptr++;
    }
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