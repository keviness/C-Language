#include <stdio.h>
#include <string.h>
#define LIM 3
#define SIZE 10
#define STOP "quit"
char * s_gets(char *str, int n);

int main(void)
{
    char input[LIM][SIZE];
    int i = 0;
    puts("Enter your letters:");
    while (i<LIM && s_gets(input[i], SIZE)!=NULL && strcmp(input[i], STOP)!= 0)
    {
        puts("The Enter letter:");
        puts(input[i]);
        puts("That is wrong, try again!");
        i++;
    }
    puts("The right, bye~");
    return 0;
}
char *s_gets(char *str, int n)
{
    char *ptr;
    int i = 0;
    ptr = fgets(str, n, stdin);
    if (ptr)
    {
        while (str[i]!='\0' && str[i]!= '\n')
        {
            i++;
        }
        if (str[i] == '\n')
            str[i] = '\0';
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }
    return ptr;
}