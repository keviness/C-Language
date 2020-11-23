#include <stdio.h>
#include <string.h>
#define SIZE 10
char *s_gets(char *ptr, int n);
char * search_char(char *str, char ch);

int main(void)
{
    char ch;
    char * find;
    char input[SIZE];
    puts("Enter you char:");
    ch = getchar();
    while (getchar() != '\n')
        continue;
    puts("Enter your letter:");
    while (s_gets(input, SIZE) && input[0] != '\0')
    {
        find = search_char(input, ch);
        if (find)
        {
            printf("The %c is in %s at %p \n", ch, input, find);
        }
        else
        {
            puts("don\'t search the character, try again:");
            ch = getchar();
            while (getchar() != '\n')
                continue;
        }
        puts("Enter the next letter:");
    }
    puts("The done~");

    return 0;
}
char *s_gets(char *str, int num)
{
    char *ptr;
    ptr = fgets(str, num, stdin);
    if (ptr)
    {
        while (*str!='\n' && *str!='\0')
            str++;
        if (*str == '\n')
            *str = '\0';
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }
    return ptr;
}
char * search_char(char *str, char ch)
{
    while (*str!='\0' && ch!=*str)
        str++;
    if (ch == *str)
    {
        return str;
    }
    else
    {
        return NULL;
    }
}