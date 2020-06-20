/*** Chapter13: test9 ***/
//rewrite example13.3
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 40
char * s_gets(char *str, int num);

int main(void)
{
    char name[MAX];
    char word[MAX];
    char ch;
    FILE *pf;
    int count = 1;

    puts("Enter the file name:");
    s_gets(name, MAX);
    if ((pf = fopen(name, "a+")) == NULL)
    {
        fprintf(stderr, "Can\'t open the %s file.\n", name);
        exit(EXIT_FAILURE);
    }

    puts("Enter the word and Press '#' to stop:");
    while (fscanf(stdin, "%40s", word)==1 && word[0]!='#')
    {
        fprintf(pf, "%d %s", count, word);
        count++;
    }
    rewind(pf);
    puts("The file content:");
    while ((ch = getc(pf)) != EOF)
    {
        putc(ch, stdout);
    }
    putchar('\n');
    puts("The done~");
    if (fclose(pf) != 0)
    {
        printf("The file %s can\'t be closed.\n", name);
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