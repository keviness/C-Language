#ifndef __NAME_H__
#define __NAME_H__
#include <stdio.h>
#include <string.h>
#define SIZE 40

struct name_struct {
    char first_name[SIZE];
    char last_name[SIZE];
};

typedef struct name_struct names;

void get_name(names *pts);
void show_name(names *pts);
char *s_gets(char *str, int n);

/*
void get_name(names *pts)
{
    printf("The first name:");
    s_gets(pts->first_name, SIZE);
    printf("The second name:");
    s_gets(pts->last_name, SIZE);
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
*/

#endif