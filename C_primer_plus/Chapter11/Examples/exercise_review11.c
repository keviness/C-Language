/*--struct s_gets() with strchr()--*/
#include <stdio.h>
#include <string.h>
char *s_gets(char *st, int n);
char *s_gets(char *st, int num)
{
    char *ptr;
    char *find;
    ptr = fgets(st, num, stdin);
    if (ptr)
    {
        find = strchr(st, '\n');
        if (find) //if the adress is not a NULL, replace it with '\0'
            *find = '\0';
        else //if the pointer is point at NULL, ignore the other input
        {
            while (getchar()!='\n')
            {
                continue;
            }
        }
    }
    return ptr;
}