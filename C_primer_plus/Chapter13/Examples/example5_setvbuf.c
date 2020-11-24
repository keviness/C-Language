#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFSIZE 4096
#define LEN 80
char *s_gets(char *st, int n);
void add(FILE *pf_target, FILE *pf_source);
int main(void)
{
    int files = 0;
    int ch;
    char fsource[LEN];
    char ftarget[LEN];
    FILE *pf_target, *pf_source;
    puts("Enter the target file name:");
    s_gets(ftarget, LEN);
    if ((pf_target=fopen(ftarget, "a+")) == NULL)
    {
        fprintf(stderr, "Usage:can\'t open %s file. \n", ftarget);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(pf_target, NULL, _IOFBF, BUFFSIZE) != 0)
    {
        fprintf(stderr, "Usage:can\'t create the output buffer. \n");
        exit(EXIT_FAILURE);
    }
    puts("Enter the source file name:");
    while (s_gets(fsource, LEN)!=NULL && fsource[0]!='\0')
    {
        if ((pf_source=fopen(fsource, "r")) == NULL)
        {
            fprintf(stderr, "Usage:can\'t open %s file. \n", fsource);
            exit(EXIT_FAILURE);
        }
        else if (strcmp(ftarget, fsource) == 0)
        {
            fprintf(stderr, "Usage: can\'t append itself.\n");
            exit(EXIT_FAILURE);
        }
        else if (setvbuf(pf_source, NULL, _IOFBF, BUFFSIZE) != 0)
        {
            fprintf(stderr, "Usage:can\'t create input buffer. \n");
            continue;
        }
        else
        {
            add(pf_target, pf_source);
            if (ferror(pf_target) != 0)
            {
                fprintf(stderr, "Usage:error in writing file. \n");
            }
            if (ferror(pf_source) != 0)
            {
                fprintf(stderr, "Usage:error in reading file. \n");
            }
            files++;
            if(fclose(pf_source) != 0)
            {
                fprintf(stderr, "Usage:Error in close %s file. \n", fsource);
            }
            printf("the %d file %s has added. \n", files, fsource);
            puts("Enter the next file name:");
        }
    }
    puts("*********\n The content of appended file:");
    rewind(pf_target);
    while ((ch = getc(pf_target)) != EOF)
    {
        putc(ch, stdout);
    }
    puts("The put done~");
    if (fclose(pf_target) != 0)
    {
        fprintf(stderr, "Usage:Error in close %s file. \n", ftarget);
    }

    return 0;
}

void add(FILE *pf_target, FILE *pf_source)
{
    size_t bytes;
    static char temp[BUFFSIZE];
    while ((bytes = fread(temp, sizeof(char), BUFFSIZE, pf_source)) >0 )
    {
        fwrite(temp, sizeof(char), bytes, pf_target);
    }
}

char *s_gets(char *str, int num)
{
    char *ptr;
    ptr = fgets(str, num, stdin);
    if (ptr)
    {
        while (*str!='\n' && *str!='\0')
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