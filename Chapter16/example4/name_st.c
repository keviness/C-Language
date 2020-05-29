#include "name.h"

void get_name(names *str)
{
    printf("Enter your first name: \n");
    s_gets(str->first_name, SIZE);
    printf("Enter your last name: \n");
    s_gets(str->last_name, SIZE);
}

void show_name(names *str)
{
    printf("The first name is: %s \n", str->first_name);
    printf("The last name is: %s \n", str->last_name);
}

char *s_gets(char *str, int n)
{
    char *ptr;
    ptr = fgets(str, n, stdin);
    if (ptr)
    {
        while (*str!='\n' && *str!='\0')
            str++;
        if (*str == '\n')
        {
            *str = '\0';
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