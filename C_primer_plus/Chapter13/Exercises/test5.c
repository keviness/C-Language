/*** Chapter13: test5 ***/
//using command-line interface instead of interactive interface

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define FILENAME 20

char *s_gets(char *str, int num);
void append(FILE *pf_target, FILE *pf_source);

int main(int argc, char *argv[])
{
    char file_target[FILENAME];
    char file_source[FILENAME];
    char ch;
    FILE *pf_target;
    FILE *pf_source;
    int count;

    if (argc < 3)
    {
        printf("Usage: The %s program need more than 3 arguments, only %d given.\n", argv[0], argc-1);
        exit(EXIT_FAILURE);
    }
    if ((pf_target = fopen(argv[1], "a+")) == NULL)
    {
        printf("Usage: Can\'t open the %s file. \n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(pf_target, NULL, _IOFBF, BUFSIZE) > 0)
    {
        printf("Can\'t crate the output buffer. \n");
        exit(EXIT_FAILURE);
    }

    for (int i=2; i<argc; i++)
    {
        if (strcmp(argv[1], argv[i]) == 0)
        {
            printf("The %s program can\'t append itself. \n", argv[0]);
        }
        else if ((pf_source = fopen(argv[i], "r")) == NULL)
        {
            printf("Can\'t open the %s file. \n", argv[i]);
        }
        else
        {
            if (setvbuf(pf_source, NULL, _IOFBF, BUFSIZE) != 0)
            {
                printf("Error in crating the buffer. \n");
            }
            append(pf_target, pf_source);
            if (ferror(pf_target) != 0)
            {
                printf("Error in writing in %s file.\n", argv[1]);
            }
            if (ferror(pf_source) != 0)
            {
                printf("Error in reading %s file. \n", argv[i]);
            }
            count++;
            if (fclose(pf_source) != 0)
            {
                printf("Can\'t close the %s file.\n", argv[i]);
            }
            printf("%d files had been appended.\n", count);
        }
    }
    puts("append file end!");
    rewind(pf_target);
    puts("The target file content:");
    while ((ch = getc(pf_target)) != EOF)
    {
        putc(ch, stdout);
    }
    puts("\n the done~");
    if (fclose(pf_target) != 0)
    {
        printf("The target %s file can\'t be closed.\n", argv[1]);
    }
    return 0;
}

void append(FILE *pf_target, FILE *pf_source)
{
    char temp[BUFSIZE];
    size_t size;

    while ((size = fread(temp, sizeof(char), BUFSIZE, pf_source)) > 0)
    {
        fwrite(temp, sizeof(char), size, pf_target);
    }
}