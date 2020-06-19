/*** Chapter13: test7b ***/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FILENAME 30
#define OUTPUT 40
char *s_gets(char *str, int num);
char *getf(char *str, int num, FILE *pf);

int main(void)
{
    FILE *pf_file_first;
    FILE *pf_file_second;
    char file_first[FILENAME];
    char file_second[FILENAME];
    char output[OUTPUT];
    char ch1, ch2;

    puts("Enter the first file name:");
    s_gets(file_first, FILENAME);
    puts("Enter the second file name:");
    s_gets(file_second, FILENAME);

    if ((pf_file_first = fopen(file_first, "r")) == NULL)
    {
        fprintf(stderr, "Can\'t open the %s file.\n", file_first);
        exit(EXIT_FAILURE);
    }
    if ((pf_file_second = fopen(file_second, "r")) == NULL)
    {
        fprintf(stderr, "Can\'t open the %s file.\n", file_second);
        exit(EXIT_FAILURE);
    }

    puts("The content of the file1 and the file2:");
    do
    {
        while ((ch1 = getc(pf_file_first))!=EOF && ch1!='\n')
        {
            putc(ch1, stdout);
            /*
            if (ch1 == '\n')
                break;
            */
        }
        while ((ch2 = getc(pf_file_second))!=EOF && ch2!='\n')
        {
            putc(ch2, stdout);
            /*
            if (ch2 == '\n')
                break;
            */
        }
        putchar('\n');
    }
    while (ch1!=EOF || ch2!=EOF);
    puts("The done~");

    if (fclose(pf_file_first)!=0 || fclose(pf_file_second)!=0)
    {
        printf("Error in closing the files.\n");
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