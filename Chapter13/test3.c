/*** Chapter13: test3 ***/
//write a copy program
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 20

char *s_gets(char *str, int num);

int main(void)
{
    char source_file[SIZE];
    char target_file[SIZE];
    FILE *pf_source;
    FILE *pf_target;
    char ch;

    puts("Enter the source file name please:");
    s_gets(source_file, SIZE);
    puts("Enter the target file name please:");
    s_gets(target_file, SIZE);

    if ((pf_source = fopen(source_file, "r")) == NULL)
    {
        fprintf(stderr, "Can\'t open the %s file.\n", source_file);
        exit(EXIT_FAILURE);
    }
    if ((pf_target = fopen(target_file, "w")) == NULL)
    {
        fprintf(stderr, "Can\'t open the %s file.\n", target_file);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(pf_source)) != EOF)
    {
        if (islower(ch))
            ch = toupper(ch);
        putc(ch, pf_target);
    }
    
    if (fclose(pf_source) != 0)
    {
        fprintf(stderr, "Can\'t close the %s file.\n", source_file);
        exit(EXIT_FAILURE);
    }
    if (fclose(pf_target) != 0)
    {
        fprintf(stderr, "Can\'t close the %s file.\n", target_file);
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
        while (*str!='\0' && *str!='\n')
            str++;
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