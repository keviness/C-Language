/*** Chapter13: test10 ***/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 40

char * s_gets(char *str, int num);

int main(void)
{
    char file_name[SIZE];
    FILE *pf;
    long pos;
    //char word[SIZE];
    char ch;

    puts("Enter the file name:");
    s_gets(file_name, SIZE);
    if ((pf = fopen(file_name, "r")) == NULL)
    {
        printf("The file %s can\'t be opend.\n", file_name);
        exit(EXIT_FAILURE);
    }
    puts("Enter the file position you want to start show:");
    while (scanf("%ld", &pos)==1 && pos>0)
    {
        fseek(pf, pos, SEEK_SET);
        while ((ch = getc(pf))!=EOF && ch!='\n')
            putc(ch, stdout);
        /*
        fscanf(pf, "%40s", word);
        fprintf(stdout, "%s \n", word);
        */
        puts("\nEnter the file position you want to start show:");
    }
    puts("The done~");

    return 0;
}

char *s_gets(char *str, int num)
{
    char *ptr;
    ptr = fgets(str ,num, stdin);
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