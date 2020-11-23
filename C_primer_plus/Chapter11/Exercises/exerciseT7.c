/*----struct the strncpy----*/
#include <stdio.h>
#include <string.h>
#define SIZE 80
char * s_gets(char *str, int n);
char * my_strcopy(char *target, char *source, int n);

int main(void)
{
    char target[SIZE] = "I am kevin and ";
    char input[SIZE];
    puts("Enter the second letters:");
    while (s_gets(input, SIZE)!=NULL && input[0]!='\0')
    {
        puts("The input string:");
        puts(input);
        my_strcopy(target, input, 10);
        puts("The target string:");
        puts(target);
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
char *my_strcopy(char *target, char *source, int n)
{
    int i = 0;
    char *ptr_last = target+strlen(target);
    while (i<n && *ptr_last=='\0' && *source!='\0')
    {
        *ptr_last = *source;
        i++;
        ptr_last++;
        source++;
    }
    return target;
}