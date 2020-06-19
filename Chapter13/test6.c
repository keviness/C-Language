/*** Chapter13: test6 ***/
//modify example13.2 promote user enter the argument
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INPUT 20

char *s_gets(char *str, int num);

int main(void)
{
    char input[INPUT];
    char target[INPUT];
    char ch;
    int count = 0;
    int i = 0;
    FILE *pf_source;
    FILE *pf_target;

    puts("Enter the file you want to compress:");
    s_gets(input, INPUT);
    if ((pf_source = fopen(input, "r")) == NULL)
    {
        printf("Usage: The %s file can\'t be opend!\n", input);
        exit(EXIT_FAILURE);
    }
    strncpy(target, input, INPUT-5); //copy the INPUT-5 charcters in input string
    target[INPUT-5] = '\0';
    strcat(target, ".dat");

    if ((pf_target = fopen(target, "w")) == NULL)
    {
        printf("Usage: The %s file can\'t be opend!\n", target);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(pf_source)) != EOF)
    {
        if (count % 3 == 0)
        {
            putc(ch, pf_target);
            i++;
        }
        count++;
    }
    printf("There are %d characters reduce to %d characters.\n", count, i);
    puts("The done~");

    if (fclose(pf_source)!=0 || fclose(pf_target)!=0)
    {
        puts("Error in closing files.");
        exit(EXIT_FAILURE);
    }

    return 0;
}

char *s_gets(char *str, int num)
{
    char *ptr;
    ptr = fgets(str, num, stdin);
    if (ptr)
    {
        while (*str!='\n' && *str!='\0')
        {
            str++;
        }
        if (*str == '\n')
            *str = '\0';
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