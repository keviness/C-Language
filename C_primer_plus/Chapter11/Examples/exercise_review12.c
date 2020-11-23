#include <stdio.h>
#include <string.h>
char *ptr(const char * st)
{
    while (*st!='\0' && *st!=' ')
    {
        st++;
    }
    if (*st == ' ')
        return (char*)st;
    else
    {
        return NULL;
    }   
}