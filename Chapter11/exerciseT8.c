#include <stdio.h>
#include <string.h>
#define SIZE 20
char *s_gets(char *st, int n);
char *string_in(char *str1, char *str2);
int main(void)
{
    char str1[SIZE];
    char str2[SIZE];
    char *find;
    puts("Enter the strings:");
    while (s_gets(str1, SIZE) && s_gets(str2, SIZE) && str1[0]!='\0' &&str2[0]!='\0')
    {
        puts("The strs:");
        puts(str1);
        puts(str2);
        find = string_in(str1, str2);
        if (find != 0)
        {
            puts(find);
        }
        else
        {
            puts("No find");
        }
        puts("Try again:");
    }
    puts("The done!");
    return 0;
}
char *s_gets(char *st, int num)
{
    char *ptr;
    ptr = fgets(st, num, stdin);
    if (ptr)
    {
        while (*st!='\0' && *st!='\n')
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
char *string_in(char *str1, char *str2)
{
    int n = strlen(str2);
    int try_times = strlen(str1)-strlen(str2)+1;
    int nomatch = 1;
    if (try_times > 0)
    {
        while (nomatch=strncmp(str1,str2,n) && try_times--)
        {
            str1++;
        }
    }
    if (nomatch)
    {
        return NULL;
    }
    else
    {
        return str1;
    }
}