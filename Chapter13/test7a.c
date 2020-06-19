/*** Chapter13: test7a ***/
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
    char *ptr1, *ptr2;

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
/*
    puts("The content of the file1 and the file2:");
    while (1)
    {
        getf(output, OUTPUT, pf_file_first);
        puts(output);
        getf(output, OUTPUT, pf_file_second);
        puts(output);
        if (feof(pf_file_first)!=0 || feof(pf_file_second)!=0)
            break;
    }
*/
  
    puts("The content of the file1 and the file2:");
    do
    {
        if ((ptr1 = fgets(output, OUTPUT, pf_file_first)) != NULL)
        {
            fputs(output, stdout);
        }
        if ((ptr2 = fgets(output, OUTPUT, pf_file_second)) != NULL)
        {
            fputs(output, stdout);
        }
    }
    while (ptr1!=NULL || ptr2!=NULL);
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