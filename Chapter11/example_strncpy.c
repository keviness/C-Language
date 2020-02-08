#include <stdio.h>
#include <string.h>
#define LIM 4
#define SIZE 30
#define TARGETSIZE 7
char *s_gets(char *str, int n);
int main(void)
{
    char *input;
    char temp[LIM][SIZE];
    int i = 0;
    puts("Enter your letter:");
    while (i<LIM && s_gets(input, SIZE) != NULL)
    {
        if (input[0] != 'q')
            printf("%s is not the true input, tyr again:");
        else
        {
            strncpy(temp[i], input, TARGETSIZE-1);
            temp[i][TARGETSIZE-1] = '\0';
            i++;
        }
    }
    puts("Here the accept words:");
    for (i=0; i<LIM; i++)
    {
        puts(temp[i]);
    }

    return 0;
}
char * s_gets(char *str, int n)
{
    char *ptr;
    int i = 0;
    ptr = fgets(str, n, stdin);
    if (ptr)
    {
        while(str[i]!='\n' && str[i]!='\0')
            i++;
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